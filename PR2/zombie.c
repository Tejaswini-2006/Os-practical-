
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if(pid == 0)
    {
        printf("Child process is running.\n");
        printf("Child PID: %d\n", getpid());
        printf("Child process is exiting.\n");
    }
    else if(pid > 0)
    {
        printf("Parent process is running.\n");
        printf("Parent PID: %d\n", getpid());

        sleep(30);

        wait(NULL);
        printf("Parent collected child status.\n");
    }
    else
    {
        printf("Fork failed.\n");
    }

    return 0;
}




/*

Step 1. Create the file
nano zombie.c

Step 3. Save and compile
Save using Ctrl + O → Enter → Ctrl + X.
gcc zombie.c -o zombie


Step 4. Execute
./zombie


Step 5. Observe the Zombie Process
While the program is running, open a second Ubuntu terminal and execute:
ps -el | grep zombie


You may see output similar to:
Z  12345  12344 ... zombie


*/