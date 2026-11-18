
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, size;
    int req[100], temp[100], visited[100] = {0};
    int i, j, current, total, min, index;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk requests:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter total number of cylinders: ");
    scanf("%d", &size);

    // Sort requests
    for(i = 0; i < n; i++)
        temp[i] = req[i];

    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(temp[j] > temp[j+1])
            {
                int t = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = t;
            }
        }
    }

    // SSTF
    current = head;
    total = 0;

    printf("\nSSTF Sequence: %d", current);

    for(i = 0; i < n; i++)
    {
        min = 999999;
        index = -1;

        for(j = 0; j < n; j++)
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

    printf("\nTotal SSTF Head Movement: %d\n", total);

    // SCAN (Moving towards higher cylinders first)
    current = head;
    total = 0;

    printf("\nSCAN Sequence: %d", current);

    for(i = 0; i < n; i++)
    {
        if(temp[i] >= head)
        {
            total += abs(temp[i] - current);
            current = temp[i];
            printf(" -> %d", current);
        }
    }

    if(current != size-1)
    {
        total += abs((size-1) - current);
        current = size-1;
        printf(" -> %d", current);
    }

    for(i = n-1; i >= 0; i--)
    {
        if(temp[i] < head)
        {
            total += abs(temp[i] - current);
            current = temp[i];
            printf(" -> %d", current);
        }
    }

    printf("\nTotal SCAN Head Movement: %d\n", total);

    // C-LOOK (Moving towards higher cylinders first)
    current = head;
    total = 0;

    printf("\nC-LOOK Sequence: %d", current);

    for(i = 0; i < n; i++)
    {
        if(temp[i] >= head)
        {
            total += abs(temp[i] - current);
            current = temp[i];
            printf(" -> %d", current);
        }
    }

    for(i = 0; i < n; i++)
    {
        if(temp[i] < head)
        {
            total += abs(temp[i] - current);
            current = temp[i];
            printf(" -> %d", current);
        }
    }

    printf("\nTotal C-LOOK Head Movement: %d\n", total);

    return 0;
}



/*

2. How to execute on Ubuntu


Step 1: Create the file
nano disk.c
Paste the code and save using Ctrl + O → Enter → Ctrl + X.


Step 2: Compile
gcc disk.c -o disk


Step 3: Execute
./disk


Step 4: Enter sample input

Use this sample to test:
Enter number of disk requests: 8

Enter disk requests:
98 183 37 122 14 124 65 67

Enter initial head position: 53

Enter total number of cylinders: 200


The disk cylinders range from 0 to 199.



3. Expected output
SSTF
SSTF Sequence:
53 -> 65 -> 67 -> 37 -> 14 -> 98 -> 122 -> 124 -> 183

Total SSTF Head Movement: 236



SCAN
SCAN Sequence:
53 -> 65 -> 67 -> 98 -> 122 -> 124 -> 183 -> 199 -> 37 -> 14

Total SCAN Head Movement: 331



C-LOOK
C-LOOK Sequence:
53 -> 65 -> 67 -> 98 -> 122 -> 124 -> 183 -> 14 -> 37

Total C-LOOK Head Movement: 322



*/