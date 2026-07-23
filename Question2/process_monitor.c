#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>

#define CHILD_COUNT 3

int main(void)
{
    pid_t child_pids[CHILD_COUNT];
    int sleep_times[CHILD_COUNT] = {2, 4, 8};
    int child_state[CHILD_COUNT] = {0, 0, 0}; // 0 = still running, 1 = finished
    int status;
    int i;
    int seconds_passed = 0;
    int running_children = CHILD_COUNT;

    // Print the parent process ID so the user can see the parent process clearly.
    printf("Parent PID: %d\n", getpid());

    // Create exactly 3 child processes using fork().
    for (i = 0; i < CHILD_COUNT; i++)
    {
        pid_t pid = fork();

        if (pid == -1)
        {
            perror("fork failed");
            exit(1);
        }

        if (pid == 0)
        {
            // This block runs only in the child process.
            printf("Child %d created. Child PID: %d\n", i + 1, getpid());
            printf("Child %d sleeping for %d seconds.\n", i + 1, sleep_times[i]);

            // Sleep for a different amount of time in each child.
            sleep(sleep_times[i]);

            // Exit normally using exit().
            printf("Child %d finished sleeping and exited normally.\n", i + 1);
            exit(0);
        }
        else
        {
            // This block runs only in the parent process.
            child_pids[i] = pid;
            printf("Parent: child %d created with PID %d\n", i + 1, child_pids[i]);
        }
    }

    // Parent monitors all children using waitpid().
    // It keeps polling until all children are reaped.
    while (running_children > 0)
    {
        sleep(1);
        seconds_passed++;

        for (i = 0; i < CHILD_COUNT; i++)
        {
            // Skip children that already finished.
            if (child_state[i] == 1)
            {
                continue;
            }

            // waitpid() with WNOHANG checks whether the child has exited yet.
            // If the child is still running, it returns 0 immediately.
            pid_t result = waitpid(child_pids[i], &status, WNOHANG);

            if (result == -1)
            {
                perror("waitpid failed");
                exit(1);
            }

            if (result == 0)
            {
                // Child is still running.
                printf("Parent: waiting for child %d (PID %d)\n", i + 1, child_pids[i]);

                // If the child has been running for more than 5 seconds, terminate it.
                if (seconds_passed > 5 && sleep_times[i] > 5)
                {
                    printf("Parent: child %d exceeded 5 seconds. Sending SIGTERM.\n", i + 1);
                    kill(child_pids[i], SIGTERM);
                }
            }
            else
            {
                // Child has exited, so this child is no longer running.
                child_state[i] = 1;
                running_children--;

                if (WIFEXITED(status))
                {
                    printf("Parent: child %d exited normally with status %d\n", i + 1, WEXITSTATUS(status));
                }
                else if (WIFSIGNALED(status))
                {
                    printf("Parent: child %d was terminated by signal %d\n", i + 1, WTERMSIG(status));
                }
            }
        }
    }

    printf("Parent: all children have been monitored and reaped.\n");
    return 0;
}
