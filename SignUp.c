#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

struct Login_USER
{
    char name[20];
    char password[20];
};

int Login_Signup()
{
    struct Login_USER U;
    FILE *ptr1, *ptr2;
    int choice;
    int loggedIn = 0;
    int attempts = 0;

    printf(YELLOW "\n================================\n\t" CYAN "     WELCOME" YELLOW "\n================================\n\n" RESET);

    do
    {
        printf("\n\n\n" RED "\tMAIN MENU" RESET "\n=======================\n" BLUE "[1] Signup\n[2] Login\n[3] Exit" RESET "=======================\n");

        printf(LIGHT_MAGENTA "Enter Choice: " RESET);
        printf(GREEN);
        scanf("%d", &choice);
        printf(RESET "\n");

        switch (choice)
        {
        case 1:
            system("cls");
            ptr1 = fopen("users.txt", "a");
            ptr2 = fopen("passwords.txt", "a");

            if (ptr1 == NULL || ptr2 == NULL)
            {
                printf(RED "Error opening files!\n" RESET);
                return 0;
            }
            printf("\n");
            printf(YELLOW "Enter Username: " RESET);
            printf(GREEN);
            scanf("%s", U.name);
            printf(RESET);
            fprintf(ptr1, "%s\n", U.name);

            printf(YELLOW "Enter Password: " RESET);
            printf(GREEN);
            scanf("%s", U.password);
            printf(RESET);
            fprintf(ptr2, "%s\n", U.password);

            fclose(ptr1);
            fclose(ptr2);

            printf(GREEN "\nSignup successful!\n" RESET);
            break;

        case 2:
            system("cls");
            printf(RED "\n NOTE" RESET "\n Inputting Invalid Credentials more than 5 times will lead the PHONE to switch off.\n\n");
            printf(BLUE "Enter Username: " RESET);
            printf(GREEN);
            scanf("%s", U.name);
            printf(RESET);
            printf(BLUE "Enter Password: " RESET);
            printf(BLACK);
            scanf("%s", U.password);
            printf(RESET);
            printf("\n");

            ptr1 = fopen("users.txt", "r");
            ptr2 = fopen("passwords.txt", "r");

            if (ptr1 == NULL || ptr2 == NULL)
            {
                printf(RED "Error opening files!\n" RESET);
                return 0;
            }

            char temp1[20], temp2[20];
            int found = 0;

            while (fgets(temp1, sizeof(temp1), ptr1) != NULL && fgets(temp2, sizeof(temp2), ptr2) != NULL)
            {
                temp1[strcspn(temp1, "\n")] = 0;
                temp2[strcspn(temp2, "\n")] = 0;

                if (strcmp(U.name, temp1) == 0 && strcmp(U.password, temp2) == 0)
                {
                    printf(GREEN "\nLogged in successfully!\n" RESET);
                    found = 1;
                    loggedIn = 1;
                    break;
                }
            }

            fclose(ptr1);
            fclose(ptr2);

            if (!found)
            {
                attempts++;
                if (attempts >= 5)
                {
                    printf(RED "\nPhone Switched Off\n" RESET);
                    exit(0);
                }
                printf(RED "\nInvalid username or password. Attempts left: %d\n" RESET, 5 - attempts);
            }

            break;

        case 3:
            loggedIn = 3;
            break;

        default:
            printf(RED "Invalid choice. Please try again.\n" RESET);
        }
    } while (choice != 3 && loggedIn != 1);

    return loggedIn;
}

int main()
{

    printf("\n\n\n\n");
    printf(RED);
    printf("\t===========================================================================================================\n");
    printf("\t===========================================================================================================\n\n");
    printf(LIGHT_CYAN);
    printf("\t LL          OOOOOOO    GGGGGGGG   IIIIIIII   N       N       AAAAAAAA   UUU    UUU  TTTTTTTTTTT  HH    HH\n");
    printf("\t LL         O       O  GG             II      N N     N       A      A   UUU    UUU      TT       HH    HH\n");
    printf("\t LL         O       O  GG   GGG       II      N   N   N       AAAAAAAA   UUU    UUU      TT       HHHHHHHH\n");
    printf("\t LL         O       O  GG    GG       II      N     N N       A      A   UUU    UUU      TT       HH    HH\n");
    printf("\t LLLLLLLLL   OOOOOOO    GGGGGGGG   IIIIIIII   N       N       A      A    UUUUUUUU       TT       HH    HH\n");
    printf(RESET);
    printf("\n");
    printf(RED);
    printf("\t===========================================================================================================\n");
    printf("\t===========================================================================================================\n\n");
    printf(RESET);
    system("pause");
    system("cls");
    int result = Login_Signup();

    if (result == 1)
    {
        printf(GREEN "\nWelcome!\n" RESET);
    }
    else if (result == 3)
    {
        printf(RED "Exiting...\n" RESET);
    }

    return 0;
}
