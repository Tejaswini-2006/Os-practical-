
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void sort(int a[], int n, int order)
{
    int i, j, temp;

    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if((order == 1 && a[j] > a[j+1]) ||
               (order == 0 && a[j] < a[j+1]))
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void fork_wait()
{
    int n, a[100], b[100];

    printf("Enter number of integers: ");
    scanf("%d", &n);

    printf("Enter integers:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    pid_t pid = fork();

    if(pid == 0)
    {
        sort(b, n, 0);
        printf("\nChild Process - Descending: ");
        for(int i = 0; i < n; i++)
            printf("%d ", b[i]);
        printf("\n");
    }
    else if(pid > 0)
    {
        sort(a, n, 1);
        printf("\nParent Process - Ascending: ");
        for(int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        wait(NULL);
        printf("Child process completed.\n");
    }
    else
        printf("Fork failed.\n");
}

void zombie()
{
    pid_t pid = fork();

    if(pid == 0)
    {
        printf("Child process exiting. PID: %d\n", getpid());
        exit(0);
    }
    else if(pid > 0)
    {
        printf("Parent sleeping for 20 seconds.\n");
        printf("Zombie child PID: %d\n", pid);

        sleep(20);

        wait(NULL);
        printf("Parent collected child status.\n");
    }
    else
        printf("Fork failed.\n");
}

void orphan()
{
    pid_t pid = fork();

    if(pid == 0)
    {
        sleep(5);

        printf("\nOrphan Child Process\n");
        printf("Child PID: %d\n", getpid());
        printf("New Parent PID: %d\n", getppid());
    }
    else if(pid > 0)
    {
        printf("Parent process is exiting.\n");
        return;
    }
    else
        printf("Fork failed.\n");
}

int main()
{
    int choice;

    printf("\n----- PROCESS MANAGEMENT -----\n");
    printf("1. FORK and WAIT with Sorting\n");
    printf("2. Zombie Process\n");
    printf("3. Orphan Process\n");
    printf("4. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            fork_wait();
            break;

        case 2:
            zombie();
            break;

        case 3:
            orphan();
            break;

        case 4:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}



/*

Step 3. Save and compile
Save with Ctrl + O → Enter → Ctrl + X.
gcc process2.c -o process2


Step 4. Execute
./process2

*/