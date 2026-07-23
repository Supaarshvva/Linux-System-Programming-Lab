#!/bin/bash

# Directories and files used by this script
SUBMISSION_DIR="submissions"
BACKUP_DIR="backup"
REPORT_FILE="report.txt"
ERROR_FILE="errors.log"

# Counters for final report
processed=0
duplicates=0
backed_up=0

# Use an associative array to track file hashes
declare -A hashes

# Ensure the backup directory exists and send mkdir errors to errors.log
mkdir -p "$BACKUP_DIR" 2>>"$ERROR_FILE"

# Append all stderr output to the error log
: > "$ERROR_FILE"
exec 2>>"$ERROR_FILE"

# Allow the glob to expand to nothing if there are no files
shopt -s nullglob

# Process each file in the submissions folder
for file in "$SUBMISSION_DIR"/*
do
    # Skip non-regular files (directories, symlinks, etc.)
    if [ ! -f "$file" ]; then
        continue
    fi

    ((processed++))

    # Compute the MD5 hash and keep only the hash value
    hash=$(md5sum "$file" | awk '{print $1}')

    # Check if this hash has already been seen
    if [[ -n "${hashes[$hash]:-}" ]]; then
        ((duplicates++))
        continue
    fi

    # Mark this hash as seen and copy the unique file to backup
    hashes["$hash"]="$file"
    cp "$file" "$BACKUP_DIR/" 2>>"$ERROR_FILE"
    ((backed_up++))
done

# Write the summary report
cat > "$REPORT_FILE" <<EOF
Processed files: $processed
Duplicate files: $duplicates
Backed up files: $backed_up
EOF

# Final message for the user
echo "Processing completed successfully."
