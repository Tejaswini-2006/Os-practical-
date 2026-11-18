// Process 2 : Receiver Program //



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    FILE *fp, *file;
    char sentence[1024];
    int ch;

    int characters = 0;
    int words = 0;
    int lines = 0;
    int inword = 0;

    mkfifo("fifo1", 0666);
    mkfifo("fifo2", 0666);

    fp = fopen("fifo1", "r");

    while (fgets(sentence, sizeof(sentence), fp) != NULL)
    {
        if (strcmp(sentence, "END\n") == 0)
            break;

        lines++;

        for (int i = 0; sentence[i] != '\0'; i++)
        {
            if (sentence[i] != '\n')
                characters++;

            if (isspace((unsigned char)sentence[i]))
                inword = 0;

            else if (inword == 0)
            {
                words++;
                inword = 1;
            }
        }
    }

    fclose(fp);

    file = fopen("output.txt", "w");

    fprintf(file, "Number of Characters: %d\n", characters);
    fprintf(file, "Number of Words: %d\n", words);
    fprintf(file, "Number of Lines: %d\n", lines);

    fclose(file);

    fp = fopen("fifo2", "w");

    file = fopen("output.txt", "r");

    while ((ch = fgetc(file)) != EOF)
    {
        fputc(ch, fp);
    }

    fclose(file);
    fclose(fp);

    return 0;
}
