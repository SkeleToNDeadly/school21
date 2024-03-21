#!/bin/bash

if [ $# -eq 0 ]; then
  echo "Usage: $0 <log_file_path>"
  exit 1
fi

log_file=$1

if [ ! -f "$log_file" ]; then
  echo "Error: File not found"
  exit 1
fi

total_entries=$(wc -l < "$log_file")
unique_files=$(awk '{print $1}' "$log_file" | sort -u | wc -l)
changes=$(awk '{if ($4 != "NULL") print $4}' "$log_file" | sort -u | wc -l)

echo "$total_entries$unique_files$changes"

