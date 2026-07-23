# Linux Log Monitoring Assignment

## Introduction

This assignment shows how to monitor a log file in Linux and save only error messages in a separate file.

The main commands used here are:

- `tail`
- `grep`
- `tail -f`
- `|` (pipe)
- `>`
- `>>`
- `2>`
- `2>>`
- `2>/dev/null`

## 1. `tail`

`tail` shows the last lines of a file.

Example:

```bash
tail sample.log
```

This displays the end of `sample.log`.

## 2. `grep`

`grep` searches for lines that match a pattern.

Example:

```bash
grep "ERROR" sample.log
```

This prints only the lines containing the word `ERROR`.

## 3. `tail -f`

`tail -f` follows a file continuously and shows new lines as they are added.

Example:

```bash
tail -f sample.log
```

This is useful for monitoring a live log file in real time.

## 4. Pipe (`|`)

The pipe symbol `|` sends the output of one command into another command.

Example:

```bash
tail -f sample.log | grep "ERROR"
```

This means:

- `tail -f` keeps showing new log lines
- `grep "ERROR"` filters only the lines containing `ERROR`

So the final output shows only error messages from the log file.

## 5. `>`

`>` redirects the output of a command into a file and overwrites the file if it already exists.

Example:

```bash
grep "ERROR" sample.log > errors.txt
```

This stores the matching lines into `errors.txt`.

## 6. `>>`

`>>` redirects output into a file by appending to the end of the file.

Example:

```bash
grep "ERROR" sample.log >> errors.txt
```

This adds new error lines to the existing file instead of replacing it.

## 7. `2>`

`2>` redirects standard error output (stderr) to a file.

Example:

```bash
command 2> errors.txt
```

This stores only error messages from the command in `errors.txt`.

## 8. `2>>`

`2>>` redirects standard error output to a file by appending.

Example:

```bash
command 2>> errors.txt
```

This adds new error messages to `errors.txt`.

## 9. `2>/dev/null`

`2>/dev/null` sends error messages to `/dev/null`, which is like a trash can.

Example:

```bash
command 2>/dev/null
```

This hides the error output and does not show it on the screen.

## How to monitor a log file and save only error messages

A common command used for monitoring logs is:

```bash
tail -f sample.log | grep "ERROR" > errors.txt
```

### What this command does

- `tail -f sample.log`
  - watches the log file continuously
- `| grep "ERROR"`
  - filters only the lines containing `ERROR`
- `> errors.txt`
  - saves the filtered output into `errors.txt`

### Example of error handling

If we want to ignore unwanted error output from the command itself, we can use:

```bash
tail -f sample.log 2>/dev/null | grep "ERROR" > errors.txt
```

### Explanation

- `tail -f sample.log` keeps reading the file
- `2>/dev/null` hides any error messages from `tail`
- `| grep "ERROR"` keeps only error lines
- `> errors.txt` stores those lines in a file

## Simple summary

- `tail` shows the end of a file
- `grep` filters lines by a pattern
- `tail -f` monitors a file live
- `|` connects two commands
- `>` overwrites a file
- `>>` appends to a file
- `2>` redirects errors to a file
- `2>>` appends errors to a file
- `2>/dev/null` hides error messages

By combining these commands, we can monitor a log file in real time and save only the important error messages in another file.
