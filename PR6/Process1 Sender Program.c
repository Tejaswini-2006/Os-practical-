// Process1: Sender Program //


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    FILE *fp;
    char sentence[1024];
    char result[1024];

    mkfifo("fifo1", 0666);
    mkfifo("fifo2", 0666);

    printf("Enter sentences (type END to stop):\n");

    fp = fopen("fifo1", "w");

    while (1)
    {
        fgets(sentence, sizeof(sentence), stdin);

        fputs(sentence, fp);
        fflush(fp);

        if (strcmp(sentence, "END\n") == 0)
            break;
    }

    fclose(fp);

    fp = fopen("fifo2", "r");

    printf("\nReceived Result:\n");

    while (fgets(result, sizeof(result), fp) != NULL)
    {
        printf("%s", result);
    }

    fclose(fp);

    return 0;
}




/*

3. Complete execution steps in Ubuntu

Step 1: Create first file
nano process1.c
Paste Process 1 code and save using Ctrl + O, Enter, Ctrl + X.



Step 2: Create second file
nano process2.c
Paste Process 2 code and save.



Step 3: Compile both programs
gcc process1.c -o process1
gcc process2.c -o process2


Step 4: Open Terminal 1
Run the receiver first:
./process2

It will wait for input from Process 1.




Step 5: Open Terminal 2
Run the sender:
./process1


Step 6: Enter input
Hello world
Operating Systems
Interprocess Communication
END





4. Expected output
TERMINAL 2 – PROCESS 1
Enter sentences (type END to stop):

Hello world
Operating Systems
Interprocess Communication
END



Received Result:

Number of Characters: 48
Number of Words: 6
Number of Lines: 3
The actual character count is calculated by the program; the above count is illustrative.




5. Check the output file
In either terminal, execute:
cat output.txt


*/
