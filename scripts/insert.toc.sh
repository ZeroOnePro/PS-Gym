read -p "목차를 삽입할 파일 절대 경로를 붙여넣어 주세요 >> " current

# use gnu-sed on macOS

echo $current

sed -i "2i <!--ts-->\n<!--te-->\n" "$current" && ./scripts/gh-md-toc.sh --insert --no-backup "$current"