
#include <stdio.h>
#include <string.h>

struct Contact
{
    char name[30];
    char phone[15];
    char email[40];
};

int main()
{
    struct Contact book[100];
    int count = 0, choice, i, pos;
    char search[30];

    while (1)
    {
        printf("\n--- ADDRESS BOOK ---\n");
        printf("1. Create Address Book\n");
        printf("2. View Address Book\n");
        printf("3. Insert Record\n");
        printf("4. Delete Record\n");
        printf("5. Modify Record\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter number of contacts: ");
                scanf("%d", &count);

                for (i = 0; i < count; i++)
                {
                    printf("\nEnter name: ");
                    scanf(" %29[^\n]", book[i].name);

                    printf("Enter phone: ");
                    scanf(" %14s", book[i].phone);

                    printf("Enter email: ");
                    scanf(" %39s", book[i].email);
                }
                break;

            case 2:
                if (count == 0)
                    printf("Address book is empty!\n");
                else
                {
                    for (i = 0; i < count; i++)
                    {
                        printf("\nName: %s", book[i].name);
                        printf("\nPhone: %s", book[i].phone);
                        printf("\nEmail: %s\n", book[i].email);
                    }
                }
                break;

            case 3:
                if (count >= 100)
                {
                    printf("Address book is full!\n");
                    break;
                }

                printf("Enter name: ");
                scanf(" %29[^\n]", book[count].name);

                printf("Enter phone: ");
                scanf(" %14s", book[count].phone);

                printf("Enter email: ");
                scanf(" %39s", book[count].email);

                count++;
                printf("Record inserted successfully!\n");
                break;

            case 4:
                printf("Enter name to delete: ");
                scanf(" %29[^\n]", search);

                pos = -1;

                for (i = 0; i < count; i++)
                {
                    if (strcmp(book[i].name, search) == 0)
                    {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1)
                    printf("Record not found!\n");
                else
                {
                    for (i = pos; i < count - 1; i++)
                        book[i] = book[i + 1];

                    count--;
                    printf("Record deleted successfully!\n");
                }
                break;

            case 5:
                printf("Enter name to modify: ");
                scanf(" %29[^\n]", search);

                pos = -1;

                for (i = 0; i < count; i++)
                {
                    if (strcmp(book[i].name, search) == 0)
                    {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1)
                    printf("Record not found!\n");
                else
                {
                    printf("Enter new phone: ");
                    scanf(" %14s", book[pos].phone);

                    printf("Enter new email: ");
                    scanf(" %39s", book[pos].email);

                    printf("Record modified successfully!\n");
                }
                break;

            case 6:
                printf("Exiting Address Book...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}





/*


file Running:


Step 1: Create a new file
touch practical1.c


Step 2: Open the file
nano practical1.c


Step 3: Paste your complete C program
- Copy the C code from your preparation document.
- Paste it into the file.
- Press Ctrl + O → Enter to save.
- Press Ctrl + X to exit.


Step 4: Compile the program
gcc practical1.c -o a


Step 5: Execute the program
./a


*/