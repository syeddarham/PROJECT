#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define DEFAULT "\033[39m"
#define LIGHT_GRAY "\033[90m"
#define LIGHT_RED "\033[91m"
#define LIGHT_GREEN "\033[92m"
#define LIGHT_YELLOW "\033[93m"
#define LIGHT_BLUE "\033[94m"
#define LIGHT_MAGENTA "\033[95m"
#define LIGHT_CYAN "\033[96m"
#define LIGHT_WHITE "\033[97m"
#define RESET "\033[0m"

struct contact
{
    char ph[100], name[20], address[20], email[30];
} list;

char search[20], name[20];
FILE *todo_fptr;

int main()
{
    int i, n, ch, l, found;
    printf("\n\n\n\n");
    printf(RED);
    printf("\t=============================================================================================\n");
    printf("\t=============================================================================================\n\n");
    printf(LIGHT_CYAN);
    printf("\tCCCCCCCC    OOOOOOO    N       N   TTTTTTTTTTT   AAAAAAAA   CCCCCCCC  TTTTTTTTTTT   SSSSSSSSS\n");
    printf("\tCC         O       O   N N     N       TT        A      A   CC            TT        S        \n");
    printf("\tCC         O       O   N   N   N       TT        AAAAAAAA   CC            TT        SSSSSSSSS\n");
    printf("\tCC         O       O   N     N N       TT        A      A   CC            TT                S\n");
    printf("\tCCCCCCCC    OOOOOOO    N       N       TT        A      A   CCCCCCCC      TT        SSSSSSSSS\n");
    printf(RESET);
    printf("\n");
    printf(RED);
    printf("\t=============================================================================================\n");
    printf("\t=============================================================================================\n\n");
    printf(RESET);
    system("pause");
REPEAT:
    system("cls");
    printf(YELLOW "\t====================="
                  "========================"
                  "========================="
                  "======================="
                  "==========\n" RESET);
    printf(MAGENTA "\t\t\t\t\t**** Welcome to Contact Management System ****\n" RESET);
    printf(YELLOW "\t====================="
                  "========================"
                  "========================="
                  "======================="
                  "==========\n" RESET);
    printf("\n\n\n\t\t\t" RED "MAIN MENU" RESET "\n\t\t=====================\n\t\t" GREEN "[1] Add a New Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for Contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t" RESET "=================\n\t\t");
    printf("Enter Your Choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 0:
        printf(RED "\n\n\t\tAre You Sure To Exit?" RESET);
        break;

    case 1:
        system("cls");
        todo_fptr = fopen("contact.txt", "a");
        while (1)
        {
            fflush(stdin);
            printf("\n");
            printf(LIGHT_CYAN "To Exit Enter Blank Space in the Name Input\n\n" RESET);
            printf(BLUE "Name :" RESET);
            printf(GREEN);
            scanf("%[^\n]", list.name);
            printf(RESET);
            if (strcmp(list.name, "") == 0 || strcmp(list.name, " ") == 0)
                break;
            fflush(stdin);
            printf(BLUE "Phone: " RESET);
            printf(GREEN);
            scanf("%s", &list.ph);
            printf(RESET);
            fflush(stdin);
            printf(BLUE "Address: " RESET);
            printf(GREEN);
            scanf("%[^\n]", list.address);
            printf(RESET);
            fflush(stdin);
            printf(BLUE "Email Address: " RESET);
            printf(GREEN);
            scanf("%s", list.email);
            printf(RESET);
            fprintf(todo_fptr, "%s %s %s %s\n", list.name, list.ph, list.address, list.email);
            printf("\n");
        }
        fclose(todo_fptr);
        break;

    case 2:
        system("cls");
        printf(GREEN "\n================================\n\t" RED "LIST OF CONTACTS" GREEN "\n================================\n\n" RESET);
        todo_fptr = fopen("contact.txt", "r");
        if (todo_fptr == NULL)
        {
            printf(RED "No contacts found.\n" RESET);
            break;
        }
        while (fscanf(todo_fptr, "%s %s %s %s", list.name, &list.ph, list.address, list.email) != EOF)
        {
            printf("Name: %s\nPhone: %s\nAddress: %s\nEmail: %s\n\n", list.name, list.ph, list.address, list.email);
        }
        fclose(todo_fptr);
        break;

    case 3:
        system("cls");
        found = 0;
        printf(GREEN "\n================================\n\t" RED "LIST OF CONTACTS" GREEN "\n================================\n\n" RESET);
        printf("Enter The Name Of Contact :");
        fflush(stdin);
        printf(BLUE);
        scanf("%[^\n]", search);
        printf(RESET);
        todo_fptr = fopen("contact.txt", "r");
        if (todo_fptr == NULL)
        {
            printf(RED "No contacts found.\n" RESET);
            break;
        }
        printf("\n\nSearch result for '%s' \n" GREEN "===================================================\n\n" RESET, search);
        while (fscanf(todo_fptr, "%s %s %s %s", list.name, &list.ph, list.address, list.email) != EOF)
        {
            if (strcasecmp(list.name, search) == 0)
            {
                printf("Name: %s\nPhone: %s\nAddress: %s\nEmail: %s\n\n", list.name, list.ph, list.address, list.email);
                found = 1;
            }
        }
        if (!found)
            printf(RED "No match found.\n" RESET);
        fclose(todo_fptr);
        break;

    case 4:
        system("cls");
        printf(GREEN "\n================================\n\t" RED "EDIT CONTACT" GREEN "\n================================\n\n" RESET);
        printf("Enter the name of contact to edit: ");
        fflush(stdin);
        printf(GREEN);
        scanf("%[^\n]", name);
        printf(RESET);
        FILE *temp = fopen("temp.txt", "w");
        todo_fptr = fopen("contact.txt", "r");
        if (todo_fptr == NULL)
        {
            printf(RED "No contacts found.\n" RESET);
            break;
        }
        found = 0;
        while (fscanf(todo_fptr, "%s %s %s %s", list.name, &list.ph, list.address, list.email) != EOF)
        {
            if (strcasecmp(list.name, name) == 0)
            {
                printf(RED "\nEditing '%s'\n" RESET, name);
                printf(BLUE "Name: " RESET);
                printf(GREEN);
                scanf("%s", list.name);
                printf(RESET);
                printf(BLUE "Phone: " RESET);
                printf(GREEN);
                scanf("%s", &list.ph);
                printf(RESET);
                printf(BLUE "Address: " RESET);
                printf(GREEN);
                scanf("%s", list.address);
                printf(RESET);
                printf(BLUE "Email: " RESET);
                printf(GREEN);
                scanf("%s", list.email);
                printf(RESET);
                found = 1;
            }
            fprintf(temp, "%s %s %s %s\n", list.name, list.ph, list.address, list.email);
        }
        fclose(todo_fptr);
        fclose(temp);
        remove("contact.txt");
        rename("temp.txt", "contact.txt");
        if (!found)
            printf(RED "Contact not found.\n" RESET);
        break;

    case 5:
        system("cls");
        printf(GREEN "\n================================\n\t" RED "DELETE CONTACT" GREEN "\n================================\n\n" RESET);
        printf("Enter the name of contact to delete: ");
        fflush(stdin);
        scanf("%[^\n]", name);
        temp = fopen("temp.txt", "w");
        todo_fptr = fopen("contact.txt", "r");
        if (todo_fptr == NULL)
        {
            printf(RED "No contacts found.\n" RESET);
            break;
        }
        found = 0;
        while (fscanf(todo_fptr, "%s %s %s %s", list.name, &list.ph, list.address, list.email) != EOF)
        {
            if (strcasecmp(list.name, name) != 0)
                fprintf(temp, "%s %s %s %s\n", list.name, list.ph, list.address, list.email);
            else
                found = 1;
        }
        fclose(todo_fptr);
        fclose(temp);
        remove("contact.txt");
        rename("temp.txt", "contact.txt");
        if (found)
            printf(RED "Contact deleted.\n" RESET);
        else
            printf(RED "Contact not found.\n" RESET);
        break;

    default:
        printf(RED "\nInvalid choice\n" RESET);
    }

    printf(BLUE "\n\n\nEnter the Choice:" RESET "\n\n[1] Main Menu\t[0] Exit\n\n");
    scanf("%d", &ch);
    if (ch == 1)
    {
        goto REPEAT;
    }
    return 0;
}
