
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, req[100], visited[100] = {0};
    int total = 0, current, min, index;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter disk requests:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    current = head;

    printf("\nSSTF Sequence: %d", current);

    for(int i = 0; i < n; i++)
    {
        min = 999999;
        index = -1;

        for(int j = 0; j < n; j++)
        {
            if(!visited[j] && abs(req[j] - current) < min)
            {
                min = abs(req[j] - current);
                index = j;
            }
        }

        visited[index] = 1;
        total += min;
        current = req[index];

        printf(" -> %d", current);
    }

    printf("\nTotal Head Movement: %d\n", total);

    return 0;
}



/*

Compile and run:
gcc sstf.c -o sstf
./sstf

*/