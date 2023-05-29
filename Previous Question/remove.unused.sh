find . -type f ! \( -path './.git*' -prune -o -path "./github*" -prune -o -path "./.vscode*" -prune \) -not -name "*.*" -exec rm {} \;
find . -name "tempCodeRunner*" -exec rm {} \;

echo "모든 불필요한 파일을 삭제했습니다"