if git rev-parse --verify HEAD &>/dev/null; then
    against="HEAD"
else
    against="$(git hash-object -t tree /dev/null)"
fi
exitcode=0
sources=$(find Core -type f -regextype posix-egrep -regex '^.*\.(c(c|pp|xx)?|h(h|pp)?)$' -print)
isExistsClangFormat=false
isExistsSed=false
isExistsNkf=false
if type "clang-format" &>/dev/null; then
    isExistsClangFormat=true
else
    printf "There is not clang-format.\n"
    printf "If you hope to lint the codes, please install clang-format.\n"
fi
if type "sed" &>/dev/null; then
    isExistsSed=true
fi
if type "nkf" &>/dev/null; then
    isExistsNkf=true
fi
if ! $isExistsSed && $isExistsNkf; then
    printf "There is not sed and nkf.\n"
    printf "If you hope to convert CRLF to LF, please install sed and/or nkf.\n"
fi
for file in $sources; do
    if $isExistsClangFormat && ! (diff -q "$file" <(clang-format "$file") &>/dev/null); then
        exitcode=1
        printf "[1m%s[0m\n" "$file"
        diff --color=always -ud "$file" <(clang-format "$file") | sed -e '1,2d'
        printf "\n\n"
        clang-format -i "$file"
    fi
    if $isExistsSed && ! (diff -q "$file" <(sed 's/\r$//g' "$file") &>/dev/null); then
        exitcode=1
        printf "[1m%s[0m\n" "$file"
        diff --color=always -ud "$file" <(sed 's/\r$//g' "$file") | sed -e '1,2d'
        printf "\n\n"
        #sed -i 's/\r$//g' "$file"
    elif ($isExistsNkf && ! (diff -q "$file" <(nkf -d -w "$file") &>/dev/null)); then
        exitcode=1
        printf "[1m%s[0m\n" "$file"
        diff --color=always -ud "$file" <(nkf -d -w "$file") | sed -e '1,2d'
        printf "\n\n"
        #nkf -d -w --overwrite "$file"
    fi
done
exit $exitcode
