
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, size, req[100];
    int total = 0, current;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter disk requests:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter total number of cylinders: ");
    scanf("%d", &size);

    // Sort requests
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(req[j] > req[j+1])
            {
                int t = req[j];
                req[j] = req[j+1];
                req[j+1] = t;
            }
        }
    }

    current = head;

    printf("\nSCAN Sequence: %d", current);

    // Move towards higher cylinders
    for(int i = 0; i < n; i++)
    {
        if(req[i] >= head)
        {
            total += abs(req[i] - current);
            current = req[i];
            printf(" -> %d", current);
        }
    }

    // Move to last cylinder
    if(current != size-1)
    {
        total += abs((size-1) - current);
        current = size-1;
        printf(" -> %d", current);
    }

    // Reverse direction
    for(int i = n-1; i >= 0; i--)
    {
        if(req[i] < head)
        {
            total += abs(req[i] - current);
            current = req[i];
            printf(" -> %d", current);
        }
    }

    printf("\nTotal Head Movement: %d\n", total);

    return 0;
}

/*

Compile and run:
gcc scan.c -o scan
./scan


*/