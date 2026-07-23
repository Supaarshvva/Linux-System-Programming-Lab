# Question 3 Explanation

## `open()`

- `open()` is used to open a file.
- It tells the operating system which file to access and how to access it.
- In this program, `open()` is used to create and open `employees.dat`.
- It can open a file for reading, writing, or both.
- If the file does not exist, `open()` can create it with the correct permissions.

## `read()`

- `read()` is used to read data from an opened file.
- It copies data from the file into a memory location.
- In the program, `read()` is used to read employee records back from `employees.dat`.
- The function returns the number of bytes read.

## `write()`

- `write()` is used to write data into a file.
- It takes data from memory and stores it in the file.
- In this program, `write()` is used to store all three employee records.
- Later, it is also used to update the second employee's salary.

## `lseek()`

- `lseek()` changes the position of the file pointer.
- The file pointer tells the system where the next read or write should happen.
- In this program, `lseek()` moves the pointer to the second employee record.
- This is why the program can update only one part of the file without rewriting the whole file.

## `close()`

- `close()` closes the file after the program is done using it.
- It releases the file descriptor so the system can manage resources properly.
- In this program, `close()` is used after writing, updating, and reading the file.

## Why `lseek()` helps update one employee record

- A file is stored as a sequence of bytes.
- Each employee record has a fixed size in the file.
- `lseek()` moves the file pointer directly to the byte position of the second employee record.
- Then `write()` writes only that one record.
- Because the file pointer is moved to the correct position, the program does not need to rewrite all records in the file.
- This makes the update fast and efficient.

## Simple summary

- `open()` opens the file.
- `write()` stores records.
- `lseek()` moves to the correct record position.
- `read()` reads records back.
- `close()` finishes file access.

This program uses Linux system calls directly, which makes it efficient and beginner-friendly to understand.
