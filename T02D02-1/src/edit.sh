#!/bin/bash

#Проверка на наличеие всех параметров
if [ "$#" -ne 3 ]; then
 echo "Usage: $0 <file_path> <search_string> <replace_string>"
 exit 1
fi
#Переменные
file_path="$1"
search_string="$2"
replace_string="$3"


if [ ! -f "$file_path" ]; then
 echo "Error: File not found: $file_path"
 exit 1
fi
#Делаем заменау в файле
sed -i '' "s/$search_string/$replace_string/g" "$file_path"
#Вносим изменения в логи
echo "$file_path — $(wc -c $file_path | awk '{print $1}') — $(date +"%Y-%m-%d %H:%M") — $(shasum -a 256 $file_path | cut -d ' ' -f1) — sha256" >> src/files.log

echo "Замена успешно выполнена"
