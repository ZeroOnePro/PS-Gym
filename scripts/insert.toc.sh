read -p "목차를 삽입할 파일 절대 경로를 붙여넣어 주세요 >> " current

# use gnu-sed on macOS

sed -i "2i <!--ts-->\n<!--te-->\n" "$current" && ~/gh-md-toc --insert --no-backup "$current"