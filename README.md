# Linux System Programming Lab

This repository contains solutions for a Linux System Programming laboratory assignment. The projects cover essential Linux concepts including shell scripting, process management, Linux system calls, log monitoring, and recovery mechanisms in the `vi` editor.

## Repository Structure

The repository is organized into the following folders:

- `Question1/` – Shell scripting for duplicate file detection and backup.
- `Question2/` – Process creation and monitoring using `fork()`, `waitpid()`, `kill()`, and signals.
- `Question3/` – Employee record management using Linux system calls such as `open()`, `read()`, `write()`, `lseek()`, and `close()`.
- `Question4/` – Linux log monitoring using commands like `tail`, `grep`, pipes, and redirection.
- `Question5/` – Evaluation of `vi` recovery mechanisms including swap files, undo history, registers, backup files, and auto-recovery.

The `Screenshots/` folder contains execution screenshots for each question.

## Technologies Used

- Ubuntu Linux
- C Programming
- Bash Shell Scripting
- GCC Compiler
- Linux System Calls
- Git & GitHub
- Visual Studio Code

## Learning Outcomes

This project demonstrates understanding of:

- Shell scripting
- Process management
- File handling using Linux system calls
- Linux command-line utilities
- Input/output redirection
- Log analysis
- `vi` editor recovery features
- Git version control

## How to Run

### Question 2

```bash
gcc process_monitor.c -o process_monitor
./process_monitor
```

### Question 3

```bash
gcc employee_records.c -o employee_records
./employee_records
```

Question 1 is executed as a shell script, while Questions 4 and 5 are mainly command-line and theory-based exercises.

## Author

Name:
Course:
Institution: