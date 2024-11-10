#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TODOS 100
#define MAX_LENGTH 101

char todos[MAX_TODOS][MAX_LENGTH];
int todo_count = 0;

void display()
{
    system("color 4F");
    printf("\n\n\n\n");
    printf("\t====================="
           "========================"
           "========================="
           "======================="
           "==========\n");
    printf("\t======================"
           "======================="
           "======================="
           "========================"
           "==========\n\n");
    printf("\t\t\t\t\t\t\tWelcome to the To-Do App\n\n");
    printf("\t====================="
           "========================"
           "========================="
           "======================"
           "==========\n");
    printf("\t======================"
           "======================="
           "======================="
           "========================"
           "==========\n");
    system("pause");
}

void viewtodo()
{
    system("cls");
    if (todo_count == 0)
    {
        printf("\n\nEmpty To-Do \n\n");
    }
    else
    {
        for (int i = 0; i < todo_count; i++)
        {
            printf("%d.) %s", i + 1, todos[i]);
        }
    }
    printf("\n\n\n");
    system("pause");
}

void createtodo()
{
    char c;
    system("cls");
    while (1)
    {
        if (todo_count >= MAX_TODOS)
        {
            printf("To-Do list is full.\n");
            break;
        }

        printf("\nWant to add new To-Do ??"
               " Press 'y/Y' for Yes and 'n/N' "
               "for No :-)\n\t\t");
        fflush(stdin);
        scanf(" %c", &c);

        if (c == 'n' || c == 'N')
            break;
        else if (c == 'Y' || c == 'y')
        {
            printf("\nType it.....\n");
            fflush(stdin);
            fgets(todos[todo_count], MAX_LENGTH, stdin);
            todo_count++;
        }
    }
}

void deletetodo()
{
    int x;
    system("cls");

    if (todo_count == 0)
    {
        printf("\n\nOpps! To-Do list is Empty :)\n\n\n");
    }
    else
    {
        printf("\nEnter the To-Do's number that you want to remove.\n\t\t");
        scanf("%d", &x);

        if (x < 1 || x > todo_count)
        {
            printf("Invalid To-Do number.\n");
        }
        else
        {
            for (int i = x - 1; i < todo_count - 1; i++)
            {
                strcpy(todos[i], todos[i + 1]);
            }
            todo_count--;
            printf("To-Do %d deleted.\n", x);
        }
    }
    system("pause");
}

int main()
{
    int choice;
    display();

    while (1)
    {
        system("Color 3F");
        system("cls");

        printf("1. To see your To-Do list\n");
        printf("2. To create new To-Do\n");
        printf("3. To delete your To-Do\n");
        printf("4. Exit");
        printf("\n\n\nEnter your choice\t:\t");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            viewtodo();
            break;
        case 2:
            createtodo();
            break;
        case 3:
            deletetodo();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("\nInvalid Choice\n");
            system("pause");
        }
    }
    return 0;
}
