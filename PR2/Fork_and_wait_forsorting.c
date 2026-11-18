
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

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

void display(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main()
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
        printf("\nChild Process\n");
        sort(b, n, 0);
        printf("Descending order: ");
        display(b, n);
    }
    else if(pid > 0)
    {
        printf("\nParent Process\n");
        sort(a, n, 1);
        printf("Ascending order: ");
        display(a, n);

        wait(NULL);
        printf("Child process completed.\n");
    }
    else
    {
        printf("Fork failed.\n");
    }

    return 0;
}




/*


Step 3. Save the file
Press:
- Ctrl + O
- Enter
- Ctrl + X
Step 4. Compile
gcc practical2.c -o practical2


Step 5. Execute
./practical2


*/