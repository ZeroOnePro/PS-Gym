find . -type f ! \( -path './.git*' -prune -o -path "./node_modules*" -prune -o -path "./github*" -prune -o -path "./.vscode*" -prune \) -not -name "*.*" -exec rm {} \;

echo "모든 binary 실행파일을 삭제했습니다."