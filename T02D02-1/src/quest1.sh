#!bin/bash
cd /Users/coldwatd/T02D02-1
 
### change file ####


echo "src/history_of_vim.txt — $(wc -c  src/history_of_vim.txt | awk '{print $1}') — $(date +"%Y-%m-%d %H:%M") — $(shasum -a 256 src/history_of_vim.txt | cut -d ' ' -f1) — sha256" >> src/files.log

