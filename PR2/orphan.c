
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();

    if(pid == 0)
    {
        sleep(5);

        printf("\nChild Process\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID after adoption: %d\n", getppid());
        printf("Child process completed.\n");
    }
    else if(pid > 0)
    {
        printf("Parent Process\n");
        printf("Parent PID: %d\n", getpid());
        printf("Parent process is exiting.\n");
    }
    else
    {
        printf("Fork failed.\n");
    }

    return 0;
}







/*

Step 1. Create the file
nano orphan.c


Step 3. Save and compile
Save using Ctrl + O → Enter → Ctrl + X.
gcc orphan.c -o orphan


Step 4. Execute
./orphan


Step 5. Expected output
Parent Process
Parent PID: 1234
Parent process is exiting.

Child Process
Child PID: 1235
Parent PID after adoption: 1
Child process completed.


*/