#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>



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



void Calender()
{
}
void DIGITAL_CLOCK()
{
}
void Contacts()
{
}
void TicTacToe()
{
}
void CALCULATOR()
{
}
void LuckyTrivia()
{
}
void ScrambledJumbled()
{
}

int main()
{
    int choice;
    printf("\n");
main:
    printf(GREEN"\n\t   ================================\n\t"RED"\t   WELCOME USER"GREEN"\n\t   ================================\n\n"RESET);
    printf("\n");
    printf("\n");
    printf(YELLOW"\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"RESET);
    printf(YELLOW"\tX"LIGHT_RED"           PHONE INTERFACE          "YELLOW"X\n");
    printf("\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
    printf("\tX                                    X\n");
    printf("\tX"LIGHT_CYAN"    (1) CALENDAR                    "YELLOW"X\n");
    printf("\tX"LIGHT_CYAN"    (2) DIGITAL CLOCK               "YELLOW"X\n");
    printf("\tX"LIGHT_CYAN"    (3) TODO APP                    "YELLOW"X\n");
    printf("\tX"LIGHT_CYAN"    (4) CONTACTS MANAGEMENT SYSTEM  "YELLOW"X\n");
    printf("\tX"LIGHT_CYAN"    (5) TicTacToe                   "YELLOW"X\n");
    printf("\tX"LIGHT_CYAN"    (6) CALCULATOR                  "YELLOW"X\n");
    printf("\tX"LIGHT_CYAN"    (7) LUCKY TRIVIA                "YELLOW"X\n");
    printf("\tX"LIGHT_CYAN"    (8) SCRAMBLED JUMBLED           "YELLOW"X\n");
    printf("\tX"LIGHT_CYAN"    (9) Switch OFF                  "YELLOW"X\n");
    printf("\tX"LIGHT_CYAN"                                    "YELLOW"X\n");
    printf("\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"RESET);  
    printf("\n");
    printf(BLUE"Enter your choice (1-8): "GREEN);
    scanf("%d", &choice);
    printf(RESET);
    switch (choice)
    {
    case 1:
        Calender();
        break;
    case 2:
        DIGITAL_CLOCK();
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        TicTacToe();
        break;
    case 6:
        CALCULATOR();
        break;
    case 7:
        LuckyTrivia();
        break;
    case 8:
        ScrambledJumbled();
        break;
    case 9:
        exit(0);
    default:
        printf(RED"\nInvalid choice.Try Again\n");
        system("pause");
        system("cls");
        goto main;
    }
    return 0;
}