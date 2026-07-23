#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Employee structure
struct Employee {
    int id;
    char name[30];
    float salary;
};

int main(void)
{
    const char *filename = "employees.dat";
    int fd;
    ssize_t bytes_written;
    ssize_t bytes_read;
    struct Employee employees[3] = {
        {1, "Alice", 45000.0f},
        {2, "Bob", 50000.0f},
        {3, "Charlie", 55000.0f}
    };
    struct Employee updated_employee;
    struct Employee read_employee;
    int i;

    // Step 1: Create the file with write-only access.
    // O_CREAT creates the file if it does not exist.
    // O_TRUNC clears the file if it already exists.
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("open for writing failed");
        return 1;
    }
    printf("File created: %s\n", filename);

    // Step 2: Write all three employee records to the file.
    bytes_written = write(fd, employees, sizeof(employees));
    if (bytes_written == -1)
    {
        perror("write failed");
        close(fd);
        return 1;
    }

    if (bytes_written != sizeof(employees))
    {
        perror("partial write occurred");
        close(fd);
        return 1;
    }

    printf("Records written successfully.\n");

    // Step 3: Close the file after writing.
    if (close(fd) == -1)
    {
        perror("close after write failed");
        return 1;
    }

    // Step 4: Re-open the file for reading and writing.
    fd = open(filename, O_RDWR);
    if (fd == -1)
    {
        perror("open for update failed");
        return 1;
    }

    // Step 5: Move the file pointer to the second employee record.
    // The first record uses one struct size, so the second starts after that.
    if (lseek(fd, sizeof(struct Employee), SEEK_SET) == -1)
    {
        perror("lseek failed");
        close(fd);
        return 1;
    }

    // Step 6: Create the updated record for the second employee.
    updated_employee = employees[1];
    updated_employee.salary = 65000.0f;

    // Step 7: Update only the second employee's salary using lseek.
    bytes_written = write(fd, &updated_employee, sizeof(struct Employee));
    if (bytes_written == -1)
    {
        perror("write update failed");
        close(fd);
        return 1;
    }

    if (bytes_written != sizeof(struct Employee))
    {
        perror("partial update occurred");
        close(fd);
        return 1;
    }

    printf("Record updated successfully.\n");

    // Step 8: Close the file after updating.
    if (close(fd) == -1)
    {
        perror("close after update failed");
        return 1;
    }

    // Step 9: Open the file again for reading.
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("open for reading failed");
        return 1;
    }

    // Step 10: Read back all employee records and print them.
    printf("Records read successfully:\n");
    for (i = 0; i < 3; i++)
    {
        bytes_read = read(fd, &read_employee, sizeof(struct Employee));
        if (bytes_read == -1)
        {
            perror("read failed");
            close(fd);
            return 1;
        }

        if (bytes_read == 0)
        {
            printf("Reached end of file earlier than expected.\n");
            break;
        }

        printf("ID: %d, Name: %s, Salary: %.2f\n",
               read_employee.id,
               read_employee.name,
               read_employee.salary);
    }

    // Step 11: Close the file after reading.
    if (close(fd) == -1)
    {
        perror("close after read failed");
        return 1;
    }

    return 0;
}
