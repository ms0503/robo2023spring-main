#!/bin/bash
cd "$(realpath "$(dirname "$0")")" || exit
printf "コミット前にclang-formatによるlintが行われます。\n"
if ! (type clang-format &>/dev/null); then
    printf "clang-formatがインストールされていません。\n"
    printf "clang-formatをインストールして下さい。\n"
    exit 1
fi
if [[ -f ./.git/hooks/pre-commit && ! -w ./.git/hooks/pre-commit || -f ./.git/modules/libmecha/hooks/pre-commit && ! -w ./.git/modules/libmecha/hooks/pre-commit ]]; then
    printf "pre-commitフックへの書き込み権限がありません。\n"
    printf "書き込み権限の付与を試みます..."
    if chmod 0755 ./.git/hooks/pre-commit ./.git/modules/libmecha/hooks/pre-commit; then
        printf "成功\n"
    else
        printf "失敗\n"
        printf "インストールする事が出来ません。\n"
        exit 2
    fi
fi
read -r -n1 -p "インストールしますか？ [Y/n]> " result
if [[ "$result" = [Nn] ]]; then
    printf "中断しました。\n"
    exit 0
fi
if [[ ! -f ./.git/hooks/pre-commit ]]; then
    printf "#!/usr/bin/env bash\n" > ./.git/hooks/pre-commit
    printf "exec 1>&2\n" >> ./.git/hooks/pre-commit
    chmod +x ./.git/hooks/pre-commit
fi
printf "./pre-commit-hook.sh\n" >> ./.git/hooks/pre-commit
if [[ ! -f ./.git/modules/libmecha/hooks/pre-commit ]]; then
    printf "#!/usr/bin/env bash\n" > ./.git/modules/libmecha/hooks/pre-commit
    printf "exec 1>&2\n" >> ./.git/modules/libmecha/hooks/pre-commit
    chmod +x ./.git/modules/libmecha/hooks/pre-commit
fi
printf "./pre-commit-hook.sh\n" >> ./.git/modules/libmecha/hooks/pre-commit
printf "インストールに成功しました。\n"
exit 0
