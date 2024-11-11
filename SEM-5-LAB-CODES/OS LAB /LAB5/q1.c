#include <sys/types.h>  // For defining pid_t
#include <stdio.h>      // For printf
#include <unistd.h>     // For fork(), getpid(), getppid()

int main() {
    pid_t pid;

    // Create a new process
    pid = fork();

    // fork() returns 0 in the child process
    if (pid == 0) {
        printf("This is the child process\n");
        printf("PID of child: %d\n", getpid());       // Child's process ID
        printf("PPID of child: %d\n", getppid());     // Child's parent process ID (should be parent's PID)
    }
    // fork() returns the child's PID in the parent process
    else if (pid > 0) {
        printf("This is the parent process\n");
        printf("PID of parent: %d\n", getpid());      // Parent's process ID
        printf("PPID of parent: %d\n", getppid());    // Parent's parent process ID (can vary, often the shell)
    }
    // fork() returns -1 if the process creation fails
    else {
        printf("Fork unsuccessful\n");
        return 1;  // Exit with failure status
    }

    return 0;  // Successful exit
}
