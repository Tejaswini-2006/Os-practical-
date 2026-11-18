
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, req[100];
    int total = 0, current;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter disk requests:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

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

    printf("\nC-LOOK Sequence: %d", current);

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

    // Jump to lowest request and continue
    for(int i = 0; i < n; i++)
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
gcc clook.c -o clook
./clook




*/