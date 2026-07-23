# Question 2 Explanation

## `fork()`

- `fork()` creates a new child process from the current parent process.
- After calling `fork()`, two processes exist:
  - the parent process
  - the child process
- The child gets its own process ID (PID), while the parent keeps the child's PID.
- In the program, `fork()` is used to create exactly 3 child processes.

## `wait()`

- `wait()` makes the parent process wait until one of its child processes finishes.
- It is used to collect the child process status after it exits.
- This helps prevent the child from becoming a zombie process.

## `waitpid()`

- `waitpid()` is a more flexible version of `wait()`.
- It lets the parent wait for a specific child process.
- In this program, `waitpid()` is used with `WNOHANG` to check whether a child has ended without blocking the parent.
- This allows the parent to monitor children continuously.

## Zombie process

- A zombie process is a child process that has finished running but still has an entry in the process table.
- This happens when the parent has not yet called `wait()` or `waitpid()` to collect the child's exit status.
- The parent in this program avoids zombies by calling `waitpid()` repeatedly for each child.

## `kill()`

- `kill()` is used to send a signal to a process.
- In this program, the parent uses `kill()` to send a signal to a child process.
- This helps stop a child that is running too long.

## `SIGTERM`

- `SIGTERM` is a signal used to request termination of a process.
- It is a polite way to ask a process to stop.
- In this program, the parent sends `SIGTERM` to a child that has run longer than 5 seconds.

## `exit()`

- `exit()` ends a process normally.
- In the child processes, `exit(0)` is used to finish successfully.
- The return value can be checked by the parent using `waitpid()`.

## How the parent monitors children

- The parent creates 3 children using `fork()`.
- Each child sleeps for a different duration.
- The parent stores each child's PID in an array.
- Then the parent uses `waitpid()` in a loop to check whether each child has finished.
- If a child is still running, the parent waits and keeps monitoring.

## How the parent prevents zombie processes

- A child process that ends must be reaped by the parent.
- The parent does this by calling `waitpid()`.
- This allows the operating system to remove the child process entry after the parent reads its exit status.
- Because the parent monitors and waits for all children, the program does not leave zombie processes behind.

## Summary

- `fork()` creates child processes.
- `waitpid()` lets the parent monitor and collect status of children.
- `kill()` with `SIGTERM` stops a child if it takes too long.
- `exit()` ends the child normally.
- Using `waitpid()` properly prevents zombie processes.
