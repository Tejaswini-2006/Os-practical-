
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int p1[2], p2[2];
    pid_t pid;
    char filename[100];
    char buffer[1024];
    FILE *fp;
    int n;

    pipe(p1);
    pipe(p2);

    pid = fork();

    if (pid == 0)
    {
        // Child Process
        close(p1[1]);
        close(p2[0]);

        read(p1[0], filename, sizeof(filename));

        fp = fopen(filename, "r");

        if (fp == NULL)
        {
            strcpy(buffer, "File not found!");
            write(p2[1], buffer, strlen(buffer) + 1);
        }
        else
        {
            while ((n = fread(buffer, 1, sizeof(buffer), fp)) > 0)
            {
                write(p2[1], buffer, n);
            }

            fclose(fp);
            close(p2[1]);
            close(p1[0]);
            return 0;
        }

        close(p1[0]);
        close(p2[1]);
    }
    else
    {
        // Parent Process
        close(p1[0]);
        close(p2[1]);

        printf("Enter file name: ");
        scanf("%99s", filename);

        write(p1[1], filename, strlen(filename) + 1);
        close(p1[1]);

        printf("\nFile Contents:\n");

        while ((n = read(p2[0], buffer, sizeof(buffer))) > 0)
        {
            write(STDOUT_FILENO, buffer, n);
        }

        close(p2[0]);
        wait(NULL);
    }

    return 0;
}




/* steps 


1) Create a file:
nano pipe.c


2. How to execute it on Ubuntu


Step 1: Compile
gcc pipe.c -o pipe


Step 2: Create a sample text file
nano sample.txt


Write some content:
Operating System Practical
Interprocess Communication
Communication using Pipes


Save it.

Step 3: Run the program
./pipe


Enter:
sample.txt


Step 4: Expected output
Enter file name: sample.txt

File Contents:
Operating System Practical
Interprocess Communication
Communication using Pipes



