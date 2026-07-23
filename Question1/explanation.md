# Question 1 Explanation

## Objective of the script

- The script reads files from the `submissions` folder.
- It finds duplicate files using MD5 hashes.
- It copies only unique files into the `backup` folder.
- It counts how many files were processed, how many were duplicates, and how many were backed up.
- It writes the final counts to `report.txt` and logs any errors to `errors.log`.

## Commands used

- `mkdir`
  - Creates the `backup` directory if it does not already exist.
  - This makes sure the script has a place to save files.

- `cp`
  - Copies each unique file from `submissions` to `backup`.
  - It keeps the original submission file and creates a backup copy.

- `md5sum`
  - Computes a hash value for each file.
  - The hash is a unique fingerprint for the file contents.

- `awk`
  - Extracts only the hash value from the output of `md5sum`.
  - This makes it easy to compare hashes.

- `echo`
  - Prints the final message: `Processing completed successfully.`
  - It helps the user know the script finished without stopping.

## Why stderr is redirected using `2>>`

- `2>>` sends error messages to the `errors.log` file.
- This keeps error output separate from normal script output.
- It also preserves any previous errors by appending instead of overwriting.
- If a command fails, the error is saved for later review.

## How duplicate detection works

- The script calculates an MD5 hash for each file.
- It stores each hash in a Bash associative array.
- If a file has a hash that is already in the array, it is a duplicate.
- Duplicate files are not copied to the backup folder.
- Only the first file with each unique hash is backed up.

## How `report.txt` is generated

- The script counts:
  - total files processed,
  - duplicate files found,
  - files copied to `backup`.
- It writes these counts into `report.txt` using a here-document.
- This file shows the final results of the script.
