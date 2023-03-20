if git rev-parse --verify HEAD &>/dev/null; then
    against="HEAD"
else
    against="$(git hash-object -t tree /dev/null)"
fi
if ! (type "clang-format" &>/dev/null); then
    printf "There is not clang-format.\n"
    printf "Please install clang-format.\n"
    exit 1
fi
fixed=0
for file in $(git diff --cached --name-only --diff-filter=AM "$against" -- | grep -E '\.(c(c|pp|xx)?|h(h|pp)?)$'); do
    diff -q "$file" <(clang-format "$file") &>/dev/null && continue
    fixed=1
    printf "[1m%s[0m\n" "$file"
    diff --color=always -u "$file" <(clang-format "$file") | sed -e '1,2d'
    printf "\n\n"
    clang-format -i "$file"
done
exit $fixed
