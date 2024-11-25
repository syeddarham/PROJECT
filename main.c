#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LENGTH 101
#define M_PI 3.1421

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

FILE *todo_fptr;
FILE *contact_fptr;

// CONACTS

struct contact
{
    char ph[100], name[20], address[20], email[30];
} list;

char search[20], name[20];
int i, n, ch, l, found;

// Boot Animation

void print_boot_logo()
{
    printf(CYAN);
    printf("\n\n\n\n");
    printf("\t\t\t    * * * * * * * *\n");
    printf("\t\t\t    *             *\n");
    printf("\t\t\t    *   ANDROID   *\n");
    printf("\t\t\t    *             *\n");
    printf("\t\t\t    * * * * * * * *\n");
    printf(RESET);
}
void show_starting_up()
{
    printf(YELLOW);
    printf("\n\nStarting up your Android phone...\n");
    printf("Please wait...\n");
    printf(RESET);
}

void progress_bar(int total)
{
    int i;
    for (i = 0; i <= total; i++)
    {
        printf("\r[");
        for (int j = 0; j < i; j++)
        {
            printf("=");
        }
        for (int j = i; j < total; j++)
        {
            printf(" ");
        }
        printf("] %d%%", (i * 100) / total);
        fflush(stdout);
        usleep(100000);
    }
    printf("\n");
}

void boot_animation()
{
    system("cls");
    print_boot_logo();
    usleep(5000000);
    system("cls");
    show_starting_up();
    progress_bar(30);
    usleep(500000);

    system("cls");
    printf(GREEN);
    printf("Android is now ready to use!\n");
    printf(RESET);
}

// LOGIN SIGNUP

struct Login_USER
{
    char name[20];
    char password[20];
};

int Login_Signup() {
    struct Login_USER U;
    FILE *ptr1, *ptr2;
    int choice;
    int loggedIn = 0;
    int attempts = 0;

    printf(YELLOW "\n================================\n\t" CYAN "     WELCOME" YELLOW "\n================================\n\n" RESET);

    do {
        printf("\n\n\n" RED "\tMAIN MENU" RESET "\n=======================\n" BLUE "[1] Signup\n[2] Login\n[3] Exit" RESET "\n=======================\n");

        printf(LIGHT_MAGENTA "Enter Choice: " RESET);
        printf(GREEN);
        if (scanf("%d", &choice) != 1) {
            printf(RED "Invalid input. Please enter a number.\n" RESET);
            fflush(stdin);
        }
        printf(RESET);

        switch (choice) {
        case 1:
            ptr1 = fopen("users.txt", "a+");
            ptr2 = fopen("passwords.txt", "a+");

            if (ptr1 == NULL || ptr2 == NULL) {
                printf(RED "Error opening files!\n" RESET);
                return 0;
            }
            
            printf(YELLOW "Enter Username: " RESET);
            printf(GREEN);
            scanf("%19s", U.name);
            printf(RESET);

            char temp[20];
            int found = 0;
            rewind(ptr1);
            while (fgets(temp, sizeof(temp), ptr1) != NULL) {
                temp[strcspn(temp, "\n")] = 0;
                if (strcmp(U.name, temp) == 0) {
                    printf(RED "\nUsername already exists. Please choose a different username.\n" RESET);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf(YELLOW "Enter Password: " RESET);
                printf(GREEN);
                scanf("%19s", U.password);
                printf(RESET);

                fprintf(ptr1, "%s\n", U.name);
                fprintf(ptr2, "%s\n", U.password);

                printf(GREEN "\nSignup successful!\n" RESET);
            }

            fclose(ptr1);
            fclose(ptr2);
            break;

        case 2:
            printf(RED "\n NOTE" RESET "\n Inputting Invalid Credentials more than 5 times will lead to exit.\n\n");
            printf(BLUE "Enter Username: " RESET);
            printf(GREEN);
            scanf("%19s", U.name);
            printf(RESET);
            printf(BLUE "Enter Password: " RESET);
            printf(BLACK);
            scanf("%19s", U.password);
            printf(RESET);
            printf("\n");

            ptr1 = fopen("users.txt", "r");
            ptr2 = fopen("passwords.txt", "r");

            if (ptr1 == NULL || ptr2 == NULL) {
                printf(RED "Error opening files!\n" RESET);
                break;
            }

            char temp1[20], temp2[20];
            found = 0;

            while (fgets(temp1, sizeof(temp1), ptr1) != NULL && fgets(temp2, sizeof(temp2), ptr2) != NULL) {
                temp1[strcspn(temp1, "\n")] = 0;
                temp2[strcspn(temp2, "\n")] = 0;

                if (strcmp(U.name, temp1) == 0 && strcmp(U.password, temp2) == 0) {
                    printf(GREEN "\nLogged in successfully!\n" RESET);
                    found = 1;
                    loggedIn = 1;
                    break;
                }
            }

            fclose(ptr1);
            fclose(ptr2);

            if (!found) {
                attempts++;
                if (attempts >= 5) {
                    printf(RED "\nToo many failed attempts. Exiting.\n" RESET);
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



void Auth()
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
        exit(0);
    }
}

void Interface()
{
    printf("\n");
    printf(GREEN "\n\t   ================================\n\t" RED "\t   WELCOME USER" GREEN "\n\t   ================================\n\n" RESET);
    printf("\n");
    printf("\n");
    printf(YELLOW "\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n" RESET);
    printf(YELLOW "\tX" LIGHT_RED "           PHONE INTERFACE          " YELLOW "X\n");
    printf("\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
    printf("\tX                                    X\n");
    printf("\tX" LIGHT_CYAN "    (1) CALENDAR                    " YELLOW "X\n");
    printf("\tX" LIGHT_CYAN "    (2) DIGITAL CLOCK               " YELLOW "X\n");
    printf("\tX" LIGHT_CYAN "    (3) TODO APP                    " YELLOW "X\n");
    printf("\tX" LIGHT_CYAN "    (4) CONTACTS MANAGEMENT SYSTEM  " YELLOW "X\n");
    printf("\tX" LIGHT_CYAN "    (5) TicTacToe                   " YELLOW "X\n");
    printf("\tX" LIGHT_CYAN "    (6) CALCULATOR                  " YELLOW "X\n");
    printf("\tX" LIGHT_CYAN "    (7) LUCKY TRIVIA                " YELLOW "X\n");
    printf("\tX" LIGHT_CYAN "    (8) SCRAMBLED JUMBLED           " YELLOW "X\n");
    printf("\tX" LIGHT_CYAN "    (9) Switch OFF                  " YELLOW "X\n");
    printf("\tX" LIGHT_CYAN "   (10) ABOUT US                    " YELLOW "X\n");
    printf("\tX" LIGHT_CYAN "                                    " YELLOW "X\n");
    printf("\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n" RESET);
}

// TICTACTOE

char arr_quiz[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// CALCULATOR

void display_calc();
void displaycalculationmenu();
void performcalculation();
double add(double *numbers, int count);
double sub(double *numbers, int count);
double mul(double *numbers, int count);
double division(double *numbers, int count);
double power(double base, double exponent);
double squareroot(double a);
double logBase(double x, double b);
double exponential(double x);
double factorial(int n);
double modulus(int a, int b);
double sine(double angle);
double cosine(double angle);
double tangent(double angle);
double permutation(int n, int r);
double combination(int n, int r);

void display_cal()
{
    printf("\n");
    printf(LIGHT_BLUE "=========================================\n");
    printf("=          " LIGHT_RED "SCIENTIFIC CALCULATOR" LIGHT_BLUE "        =\n");
    printf("=========================================\n");
    printf("=            " LIGHT_RED "MAIN MENU" LIGHT_BLUE "                  =\n");
    printf("=========================================\n");
    printf("=\t" LIGHT_RED "[1] Perform Calculations" LIGHT_BLUE "    	=\n");
    printf("=\t" LIGHT_RED "[2] Exit" LIGHT_BLUE "                        =\n");
    printf("=========================================\n" RESET);
}

void displaycalculationmenu()
{
    printf("\n");
    printf(MAGENTA "=========================================\n");
    printf("=        " YELLOW "CALCULATION OPERATIONS" MAGENTA "         =\n");
    printf("=========================================\n");
    printf(LIGHT_CYAN "[1]  Addition \n");
    printf("[2]  Subtraction \n");
    printf("[3]  Multiplication \n");
    printf("[4]  Division \n");
    printf("[5]  Power \n");
    printf("[6]  Square Root \n");
    printf("[7]  Logarithm \n");
    printf("[8]  Exponential \n");
    printf("[9]  Factorial \n");
    printf("[10] Modulus \n");
    printf("[11] Sine \n");
    printf("[12] Cosine \n");
    printf("[13] Tangent \n");
    printf("[14] Permutation \n");
    printf("[15] Combination \n");
    printf(MAGENTA "=========================================\n" RESET);
}

void performcalculation()
{
    int operation, n, r, count;
    double result;
    double numbers[100];

    displaycalculationmenu();
    printf(CYAN "Enter the operation you want to perform: " RESET);
    printf(GREEN);
    scanf("%d", &operation);
    printf(RESET);
    system("cls");

    switch (operation)
    {
    case 1:
        printf(CYAN "Enter the number of values to add: " RESET);
        printf(GREEN);
        scanf("%d", &count);
        printf(RESET);
        printf(CYAN "Enter the numbers: " RESET);
        printf(GREEN);
        for (int i = 0; i < count; i++)
        {
            scanf("%lf", &numbers[i]);
        }
        printf(RESET);
        result = add(numbers, count);
        printf(GREEN "Result: %.2lf\n" RESET, result);
        break;
    case 2:
        printf(CYAN "Enter the number of values to subtract: " RESET);
        printf(GREEN);
        scanf("%d", &count);
        printf(RESET);
        printf(CYAN "Enter the numbers (first number will be the minuend): " RESET);
        printf(GREEN);
        for (int i = 0; i < count; i++)
        {
            scanf("%lf", &numbers[i]);
        }
        printf(RESET);
        result = sub(numbers, count);
        printf(GREEN "Result: %.2lf\n" RESET, result);
        break;
    case 3:
        printf(CYAN "Enter the number of values to multiply: " RESET);
        printf(GREEN);
        scanf("%d", &count);
        printf(RESET);
        printf(CYAN "Enter the numbers: " RESET);
        printf(GREEN);
        for (int i = 0; i < count; i++)
        {
            scanf("%lf", &numbers[i]);
        }
        printf(RESET);
        result = mul(numbers, count);
        printf(GREEN "Result: %.2lf\n" RESET, result);
        break;
    case 4:
        printf(CYAN "Enter the number of values to divide: " RESET);
        printf(GREEN);
        scanf("%d", &count);
        printf(RESET);
        printf(CYAN "Enter the numbers (first number will be the dividend): " RESET);
        printf(GREEN);
        for (int i = 0; i < count; i++)
        {
            scanf("%lf", &numbers[i]);
        }
        printf(RESET);
        result = division(numbers, count);
        if (result != -1)
        {
            printf(GREEN "Result: %.2lf\n" RESET, result);
        }
        break;
    case 5:
        printf(CYAN "Enter base and exponent: " RESET);
        printf(GREEN);
        scanf("%lf %lf", &numbers[0], &numbers[1]);
        printf(RESET);
        result = power(numbers[0], numbers[1]);
        printf(GREEN "Result: %.2lf\n" RESET, result);
        break;
    case 6:
        printf(CYAN "Enter the number: " RESET);
        printf(GREEN);
        scanf("%lf", &numbers[0]);
        printf(RESET);
        result = squareroot(numbers[0]);
        printf(GREEN "Result: %.2lf\n" RESET, result);
        break;
    case 7:
        printf(CYAN "Enter x and base b: " RESET);
        printf(GREEN);
        scanf("%lf %lf", &numbers[0], &numbers[1]);
        printf(RESET);
        result = logBase(numbers[0], numbers[1]);
        if (result != -1)
        {
            printf(GREEN "Result: %.2lf\n" RESET, result);
        }
        break;
    case 8:
        printf(CYAN "Enter exponent for e^x: " RESET);
        printf(GREEN);
        scanf("%lf", &numbers[0]);
        printf(RESET);
        result = exponential(numbers[0]);
        printf(GREEN "Result: %.2lf\n" RESET, result);
        break;
    case 9:
        printf(CYAN "Enter a non-negative integer: " RESET);
        printf(GREEN);
        scanf("%d", &n);
        printf(RESET);
        if (n >= 0)
        {
            result = factorial(n);
            printf(GREEN "Result: %.2lf\n" RESET, result);
        }
        else
        {
            printf(RED "Error: Factorial is not defined for negative numbers!\n" RESET);
        }
        break;
    case 10:
        printf(CYAN "Enter two integers for modulus: " RESET);
        printf(GREEN);
        scanf("%lf %lf", &numbers[0], &numbers[1]);
        printf(RESET);
        result = modulus((int)numbers[0], (int)numbers[1]);
        printf(GREEN "Result: %.2lf\n" RESET, result);
        break;
    case 11:
        printf(CYAN "Enter angle in degrees: " RESET);
        printf(GREEN);
        scanf("%lf", &numbers[0]);
        printf(RESET);
        result = sine(numbers[0]);
        printf(GREEN "sin(%.2lf) = %.2lf\n" RESET, numbers[0], result);
        break;
    case 12:
        printf(CYAN "Enter angle in degrees: " RESET);
        printf(GREEN);
        scanf("%lf", &numbers[0]);
        printf(RESET);
        result = cosine(numbers[0]);
        printf(GREEN "cos(%.2lf) = %.2lf\n" RESET, numbers[0], result);
        break;
    case 13:
        printf(CYAN "Enter angle in degrees: " RESET);
        printf(GREEN);
        scanf("%lf", &numbers[0]);
        printf(RESET);
        result = tangent(numbers[0]);
        if (result == -1)
        {
            break;
        }
        else
        {
            printf(GREEN "tan(%.2lf) = %.2lf\n" RESET, numbers[0], result);
        }
        break;
    case 14:
        printf(CYAN "Enter n and r (nPr): " RESET);
        printf(GREEN);
        scanf("%d %d", &n, &r);
        printf(RESET);
        result = permutation(n, r);
        printf(GREEN "Result: %.2lf\n" RESET, result);
        break;
    case 15:
        printf(CYAN "Enter n and r (nCr): " RESET);
        printf(GREEN);
        scanf("%d %d", &n, &r);
        printf(RESET);
        result = combination(n, r);
        printf(GREEN "Result: %.2lf\n" RESET, result);
        break;
    default:
        printf(RED "Invalid operation.\n" RESET);
        break;
    }
    printf(MAGENTA "=========================================\n" RESET);
}

double add(double *numbers, int count)
{
    double sum = 0.0;
    for (int i = 0; i < count; i++)
    {
        sum += numbers[i];
    }
    return sum;
}

double sub(double *numbers, int count)
{
    double result = numbers[0];
    for (int i = 1; i < count; i++)
    {
        result -= numbers[i];
    }
    return result;
}

double mul(double *numbers, int count)
{
    double product = 1.0;
    for (int i = 0; i < count; i++)
    {
        product *= numbers[i];
    }
    return product;
}

double division(double *numbers, int count)
{
    double result = numbers[0];
    for (int i = 1; i < count; i++)
    {
        if (numbers[i] == 0)
        {
            printf(RED "Error: Division by zero!\n" RESET);
            return -1;
        }
        result /= numbers[i];
    }
    return result;
}

double power(double base, double exponent)
{
    return pow(base, exponent);
}

double squareroot(double a)
{
    if (a < 0)
    {
        printf(RED "Error: Square root of negative number!\n" RESET);
        return -1;
    }
    return sqrt(a);
}

double logBase(double x, double b)
{
    if (x <= 0 || b <= 1)
    {
        printf(RED "Error: Logarithm requires x > 0 and base > 1.\n" RESET);
        return -1;
    }
    return log(x) / log(b);
}

double exponential(double x)
{
    return exp(x);
}

double factorial(int n)
{
    if (n < 0)
    {
        printf(RED "Error: Factorial is not defined for negative numbers!\n" RESET);
        return -1;
    }
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

double modulus(int a, int b)
{
    return a % b;
}

double sine(double angle)
{
    return sin(angle * (M_PI / 180.0));
}

double cosine(double angle)
{
    return cos(angle * (M_PI / 180.0));
}

double tangent(double angle)
{
    while (angle >= 360.0)
    {
        angle -= 360.0;
    }
    while (angle < 0.0)
    {
        angle += 360.0;
    }

    if (angle == 90.0 || angle == 270.0)
    {
        printf(RED "Error: Tangent is undefined for angles of 90 and 270 degrees.\n" RESET);
        return -1;
    }
    else
    {
        return tan(angle * (M_PI / 180.0));
    }
}

double permutation(int n, int r)
{
    return factorial(n) / factorial(n - r);
}

double combination(int n, int r)
{
    if (r > n)
    {
        printf(RED "Error: r cannot be greater than n.\n" RESET);
        return -1;
    }
    return factorial(n) / (factorial(r) * factorial(n - r));
}
// QUIZ GAME

void math()
{
    int score = 0;
    int p;
    int wrong = 0;
    int correct = 0;
    printf(GREEN "============================================" RED "Maths Quiz Starts!" GREEN "==========================================================\n" RED);

    printf("Instruction:\n" WHITE);
    printf(" 1)Each Question = 4 marks\n 2)For each wrong answer your score will be deducted by 1\n 3)50 percent score for passing the quiz\n\n\n" LIGHT_CYAN);
    printf("Q1 : x^2-8x+15=0\n");
    printf(" 1)(x-3)(x+5)\n 2)(x+3)(x-5)\n 3)(x-3)(x-5)\n 4)(x+3)(x+5)\n\n");
    scanf("%d", &p);
    if (p == 3)
    {
        score += 4;
        correct += 1;

        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q2 : x^2-6x+8=0\n\n");
    printf(" 1)(x-2)(x-4)\n 2)(x+2)(x-4)\n 3)(x-2)(x+4)\n 4)(x+2)(x+4)\n\n");
    scanf("%d", &p);
    if (p == 1)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q3 : cube root of unity\n");
    printf(" 1)1\n 2)5\n 3)6\n 4)7\n");
    scanf("%d", &p);
    if (p == 1)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q4 : What is the slope of the line passing through the points (2,3) and (5,11)? \n");
    printf(" 1)8/3\n 2)7/3\n 3)8/5\n 4)9/4\n");
    scanf("%d", &p);
    if (p == 1)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q5 : What is the value of x in the equation 3(x-2)+4=10 \n");
    printf(" 1)x=6\n 2)x=8\n 3)x=5\n 4)x=4\n");
    scanf("%d", &p);
    if (p == 4)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q6 : (9+9)+8*10/2\n");
    printf(" 1)98\n 2)58\n 3)48\n 4)none\n");
    scanf("%d", &p);
    if (p == 2)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q7 : x^2-5x+6\n");
    printf(" 1)(x+2)(x-3)\n 2)(x-2)(x+3)\n 3)(x-2)(x-3)\n 4)(x+2)(x+3)\n");
    scanf("%d", &p);
    if (p == 3)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }

    printf("Q8 : If g(x) = 2x - 7, find g(-3)\n");
    printf(" 1)13\n 2)-13\n 3)-15\n 4)14\n");
    scanf("%d", &p);
    if (p == 2)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q9 : What is the value of (3/4) + (1/2)?\n\n");
    printf(" 1)5/3\n 2)5/4\n 3)5/2\n 4)7/4\n");
    scanf("%d", &p);
    if (p == 2)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q10 : Solve for y in the equation: 4y + 2 = 18\n\n");
    printf(" 1)y=4\n 2)y=3\n 3)y=1\n 4)y=5\n");
    scanf("%d", &p);
    if (p == 1)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf("wrong Answer!\n\n");
    }
    if (score >= 20)
    {
        printf(GREEN "Congratulations you 've passed\n\n" RESET);
    }
    else
    {
        printf(RED "Sorry, You didn't passed\n\n\n" RESET);
    }
    printf("Score = %d\n\n", score);
    printf("Wrong Answers = %d\n\n", wrong);
    printf("Correct Answers = %d\n\n", correct);
    printf(RESET);
    system("pause");
    system("cls");
    printf("\n\n");
}

void GK()
{
    int score = 0;
    int p;
    int wrong = 0;
    int correct = 0;
    printf(GREEN "========================================" RED "General Knowledge Quiz Starts!" GREEN "===================================================\n" LIGHT_RED);

    printf("Instruction:\n" WHITE);
    printf(" 1)Each Question = 4 marks\n 2)For each wrong answer your score will be deducted by 1\n 3)50 percent score for passing the quiz\n\n\n" LIGHT_CYAN);
    printf("Q1 : What is the only country that is also a continent?\n");
    printf(" 1)Australia\n 2)New Zealand\n 3)Africa\n 4)Japan\n\n");
    scanf("%d", &p);
    if (p == 1)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q2 : Army Cheif of Pakistan\n");
    printf(" 1)Imran Khan\n 2)Nawaz Sharif\n 3)Gen Asim Munir\n 4)none\n");
    scanf("%d", &p);
    if (p == 3)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q3 : Which planet in our solar system is known for its rings?\n");
    printf(" 1)Saturn\n 2)Jupiter\n 3)Mars\n 4)Venus\n");
    scanf("%d", &p);
    if (p == 1)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q4 : What is the most spoken language in the world? \n");
    printf(" 1)English\n 2)China\n 3)Urdu\n 4)Siraiki\n");
    scanf("%d", &p);
    if (p == 2)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q5 : Which mathematician is known for the Fundamental Theorem of Algebra?\n");
    printf(" 1)Pythagoras\n 2)Albert Einstein\n 3)Carl Friedrich Gauss\n 4)none\n");
    scanf("%d", &p);
    if (p == 3)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q6 : What is the rarest blood type in humans?\n");
    printf(" 1)AB+\n 2)AB-\n 3)O+\n 4)O-\n");
    scanf("%d", &p);
    if (p == 2)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q7 : Which ancient city was known for its hanging gardens, one of the Seven Wonders of the Ancient World?\n");
    printf(" 1)Babylon\n 2)Tehran\n 3)Cairo\n 4)Paris\n");
    scanf("%d", &p);
    if (p == 1)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }

    printf("Q8 : Which ancient civilization is known for creating a written language called cuneiform?\n");
    printf(" 1)Akaidians\n 2)Sumerian\n 3)Mesopotamia\n 4)Egypt\n");
    scanf("%d", &p);
    if (p == 2)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q9 : What is the largest ocean on Earth?\n\n");
    printf(" 1)Pacific Ocean\n 2)Indian Ocean\n 3)Atlantic Ocean\n 4)Artic Ocean\n");
    scanf("%d", &p);
    if (p == 1)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q10 : Longest River in the world?\n\n");
    printf(" 1)Amazon River\n 2)Nile River\n 3)Mississippi River\n 4)Yangtze River\n");
    scanf("%d", &p);
    if (p == 2)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    if (score >= 20)
    {
        printf(GREEN "Congratulations you 've passed\n\n" RESET);
    }
    else
    {
        printf(RED "Sorry, You didn't passed\n\n\n" RESET);
    }
    printf("Score = %d\n\n", score);
    printf("Wrong Answers = %d\n\n", wrong);
    printf("Correct Answers = %d\n\n", correct);
    printf(RESET);
    system("pause");
    system("cls");
    printf("\n\n");
}

void Eng()
{
    int score = 0;
    int p;
    int wrong = 0;
    int correct = 0;
    printf(GREEN "============================================" RED "English Quiz Starts!" GREEN "========================================================\n" LIGHT_RED);

    printf("Instruction:\n" WHITE);
    printf(" 1)Each Question = 4 marks\n 2)For each wrong answer your score will be deducted by 1\n 3)50 percent score for passing the quiz\n\n\n" LIGHT_CYAN);
    printf("Q1 : What is the meaning of the word ubiquitous?\n");
    printf(" 1)Rare\n 2)Existing everywhere\n 3)Uncertain\n 4)Difficult to find\n\n");
    scanf("%d", &p);
    if (p == 2)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q2 : Identify the sentence with the correct use of the subjunctive mood\n");
    printf(" 1)If she was here, we would start.\n 2)I wish he were more responsible.\n 3)If he is happy, I am happy\n 4)She acts as if she is the boss\n");
    scanf("%d", &p);
    if (p == 2)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q3 : Which of the following sentences uses an ellipsis correctly?\n");
    printf(" 1)I was thinking... maybe we should go.\n 2)She said she would come but... she didn’t\n 3) I want to go... to the store\n 4)All of the above.\n");
    scanf("%d", &p);
    if (p == 4)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q4 : What is the term for a figure of speech in which apparently contradictory terms appear in conjunction? \n");
    printf(" 1)Hyperbole\n 2)Oxymoron\n 3)Paradox\n 4)Metaphor\n");
    scanf("%d", &p);
    if (p == 2)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q5 : Choose the sentence that demonstrates parallel structure\n");
    printf(" 1)She likes reading, writing, and to jog.\n 2)He enjoys swimming, biking, and running.\n 3)They are excited to travel, exploring new places, and to learn.\n 4)I prefer tea, coffee, and to drink soda.\n");
    scanf("%d", &p);
    if (p == 2)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q6 : Which of the following words is a homophone for to ?\n");
    printf(" 1)Too\n 2)Two\n 3)Both a and b\n 4)None of the above\n");
    scanf("%d", &p);
    if (p == 3)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q7 : What is the correct form of the adjective in this sentence: She is the ____ student in the class\n");
    printf(" 1)More intelligent\n 2)Most intelligent\n 3)Intelligentest\n 4)Intelligence\n");
    scanf("%d", &p);
    if (p == 2)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }

    printf("Q8 : In which of the following sentences is the word 'however' used incorrectly?\n");
    printf(" 1)I wanted to go; however, I had to work.\n 2)The movie was good; however it was too long\n 3)I love chocolate; however, I try to limit my intake.\n 4)She is talented; however, she needs more practice.\n");
    scanf("%d", &p);
    if (p == 2)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q9 : What is the meaning of the idiom 'to let the cat out of the bag'?\n\n");
    printf(" 1)To reveal a secret\n 2)To be careless\n 3)To cause trouble\n 4)To get lost\n");
    scanf("%d", &p);
    if (p == 1)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q10 : Which of the following sentences contains a dangling modifier?\n\n");
    printf(" 1)After reading the book, the movie was disappointing\n 2)Running quickly, the finish line was finally in sight\n 3)To improve his health, exercise is essential.\n 4)All of the above\n");
    scanf("%d", &p);
    if (p == 4)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    if (score >= 20)
    {
        printf(GREEN "Congratulations you 've passed\n\n" RESET);
    }
    else
    {
        printf(RED "Sorry, You didn't passed\n\n\n" RESET);
    }
    printf("Score = %d\n\n", score);
    printf("Wrong Answers = %d\n\n", wrong);
    printf("Correct Answers = %d\n\n", correct);
    printf(RESET);
    system("pause");
    system("cls");
    printf("\n\n");
}

void Physics()
{
    int score = 0;
    int p;
    int wrong = 0;
    int correct = 0;
    printf(GREEN "============================================" RED "Physics Quiz Starts!" GREEN "========================================================\n" LIGHT_RED);

    printf("Instruction:\n" WHITE);
    printf(" 1)Each Question = 4 marks\n 2)For each wrong answer your score will be deducted by 1\n 3)50 percent score for passing the quiz\n\n\n" LIGHT_CYAN);
    printf("Q1 : What is the unit of force in the International System of Units (SI)?\n");
    printf(" 1)Joule\n 2)Newton\n 3)Pascal\n 4)Watt\n\n");
    scanf("%d", &p);
    if (p == 2)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q2 : What is the principle behind a hydraulic lift?\n");
    printf(" 1)Conservation of energy\n 2)Pascal's principle\n 3)Bernoulli's principle\n 4)Archimedes' principle\n");
    scanf("%d", &p);
    if (p == 2)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q3 : Which of the following statements about Newton's Third Law of Motion is true?\n");
    printf(" 1)An object at rest will stay at rest unless acted upon\n 2)For every action, there is an equal and opposite reaction.\n 3)Force is equal to mass times acceleration\n 4)Energy cannot be created or destroyed\n");
    scanf("%d", &p);
    if (p == 2)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
        ;
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q4 : Which of the following is a scalar quantity? \n");
    printf(" 1)Velocity\n 2)Force\n 3)Acceleration\n 4)Mass\n");
    scanf("%d", &p);
    if (p == 4)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q5 : What is the frequency of a wave with a wavelength of 2 meters traveling at a speed of 340 m/s?\n");
    printf(" 1)170 Hz\n 2)340 Hz\n 3)1700 Hz\n 4)680 Hz\n");
    scanf("%d", &p);
    if (p == 1)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q6 : Which law states that the total energy of an isolated system remains constant?\n");
    printf(" 1)Newton's first law\n 2)Law of conservation of mass\n 3)Law of conservation of energy\n 4)Hooke's law\n");
    scanf("%d", &p);
    if (p == 3)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q7 : What is the approximate value of gravitational acceleration on Earth's surface?\n");
    printf(" 1)9.81^-2\n 2)6.81^-2\n 3)9.8^-2\n 4)9.89^-2\n");
    scanf("%d", &p);
    if (p == 1)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
        ;
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }

    printf("Q8 : Which phenomenon explains why a pencil appears broken when placed in water?\n");
    printf(" 1)Reflection\n 2)Refraction\n 3)Diffraction\n 4)Dispersion\n");
    scanf("%d", &p);
    if (p == 2)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q9 : What is the main function of a transformer?\n\n");
    printf(" 1)To store energy\n 2)To convert AC to DC\n 3)To change the voltage level of alternating current\n 4)To amplify sound\n");
    scanf("%d", &p);
    if (p == 3)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    printf("Q10 : Which particle is considered to have no electric charge?\n\n");
    printf(" 1)Proton\n 2)Neutron\n 3)Electron\n 4)Positron\n");
    scanf("%d", &p);
    if (p == 2)
    {
        score += 4;
        correct += 1;
        printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
    }
    else
    {
        score += -1;
        wrong += 1;
        printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
    }
    if (score >= 20)
    {
        printf(GREEN "Congratulations you 've passed\n\n" RESET);
    }
    else
    {
        printf(RED "Sorry, You didn't passed\n\n\n" RESET);
    }
    printf("Score = %d\n\n", score);
    printf("Wrong Answers = %d\n\n", wrong);
    printf("Correct Answers = %d\n\n", correct);
    printf(RESET);
    system("pause");
    system("cls");
    printf("\n\n");

    printf("\n\n");
}

// TODO

void display()
{
    printf("\n\n\n\n");
    printf(RED);
    printf("\t=============================================================================================\n");
    printf("\t=============================================================================================\n\n");
    printf(CYAN);
    printf("\t\tTTTTTTTTTT  OOOOOOO    DDDDDDDDD      OOOOOOO      AAAAAAA   PPPPPPP   PPPPPPP\n");
    printf("\t\t    T      O       O   D        D    O       O     A     A   P      P  P      P\n");
    printf("\t\t    T      O       O   D         D   O       O     AAAAAAA   PPPPPPP   PPPPPPP\n");
    printf("\t\t    T      O       O   D        D    O       O     A     A   P         P\n");
    printf("\t\t    T       OOOOOOO    DDDDDDDDD      OOOOOOO      A     A   P         P\n");
    printf(RESET);
    printf("\n");
    printf(RED);
    printf("\t=============================================================================================\n");
    printf("\t=============================================================================================\n\n");
    printf(RESET);
    system("pause");
}

void viewtodo()
{
    system("cls");
    printf(RED);
    printf("=========================================================\n");
    printf("  Sr No. |                  TODO LIST                       \n");
    printf("=========================================================\n\n");
    printf(RESET);
    todo_fptr = fopen("todos.txt", "r");
    if (todo_fptr == NULL)
    {
        printf(RED "Error in opening file\n" RESET);
        return;
    }
    char str[MAX_LENGTH];
    int count = 0;
    while (fgets(str, MAX_LENGTH, todo_fptr) != NULL)
    {
        count++;
        printf("  [%d]\t\t%s", count, str);
    }
    fclose(todo_fptr);
    if (count == 0)
    {
        printf(RED "\n\nOpps! TODO list is Empty :(\n\n\n" RESET);
    }
    else
    {
        printf("\n\n\n");
    }
    system("pause");
}

void createtodo()
{
    char c;
    system("cls");
    while (1)
    {
        printf(BLUE "\nWant to add new To-Do ??\n"
                    "Press 'y/Y' for Yes and 'n/N' "
                    "for No\n\t\t" RESET);
        fflush(stdin);
        scanf(" %c", &c);

        if (c == 'n' || c == 'N')
            break;
        else if (c == 'Y' || c == 'y')
        {
            printf("\n\nType Your TODO.....\n");
            fflush(stdin);
            char str[MAX_LENGTH];
            printf(GREEN);
            fgets(str, MAX_LENGTH, stdin);
            printf(RESET);
            todo_fptr = fopen("todos.txt", "a");
            if (todo_fptr == NULL)
            {
                printf(RED "Error in opening file\n" RESET);
                return;
            }
            fputs(str, todo_fptr);
            fclose(todo_fptr);
        }
    }
}

void edittodo()
{
    int x;
    system("cls");

    todo_fptr = fopen("todos.txt", "r");
    if (todo_fptr == NULL)
    {
        printf(RED "Error in opening file\n" RESET);
        return;
    }

    char str[MAX_LENGTH];
    int count = 0;
    while (fgets(str, MAX_LENGTH, todo_fptr) != NULL)
    {
        count++;
    }
    fclose(todo_fptr);

    if (count == 0)
    {
        printf(RED "\n\nOops! To-Do list is Empty :(\n\n\n" RESET);
    }
    else
    {
        system("cls");
        printf(RED);
        printf("=========================================================\n");
        printf("  Sr No. |                  TODO LIST                       \n");
        printf("=========================================================\n\n");
        printf(RESET);
        todo_fptr = fopen("todos.txt", "r");
        if (todo_fptr == NULL)
        {
            printf(RED "Error in opening file\n" RESET);
            return;
        }
        char str[MAX_LENGTH];
        int count = 0;
        while (fgets(str, MAX_LENGTH, todo_fptr) != NULL)
        {
            count++;
            printf("  [%d]\t\t%s", count, str);
        }
        fclose(todo_fptr);
        if (count == 0)
        {
            printf(RED "\n\nOpps! TODO list is Empty :(\n\n\n" RESET);
        }
        else
        {
            printf("\n\n\n");
        }
        printf(BLUE "\nEnter the To-Do's number that you want to edit.\n\t\t" RESET);
        scanf("%d", &x);

        if (x < 1 || x > count)
        {
            printf(RED "Invalid To-Do number.\n" RESET);
        }
        else
        {
            todo_fptr = fopen("todos.txt", "r");
            FILE *fp2 = fopen("temp.txt", "w");
            int i = 1;

            while (fgets(str, MAX_LENGTH, todo_fptr) != NULL)
            {
                if (i == x)
                {
                    printf("\nEnter new To-Do:\n");
                    getchar();
                    fgets(str, MAX_LENGTH, stdin);
                }
                fputs(str, fp2);
                i++;
            }
            fclose(todo_fptr);
            fclose(fp2);

            remove("todos.txt");
            rename("temp.txt", "todos.txt");

            printf(GREEN "To-Do %d edited successfully.\n" RESET, x);
        }
    }
    system("pause");
}

void deletetodo()
{
    int x;
    system("cls");
    todo_fptr = fopen("todos.txt", "r");
    if (todo_fptr == NULL)
    {
        printf(RED "Error in opening file\n" RESET);
        return;
    }
    char str[MAX_LENGTH];
    int count = 0;
    while (fgets(str, MAX_LENGTH, todo_fptr) != NULL)
    {
        count++;
    }
    fclose(todo_fptr);
    if (count == 0)
    {
        printf(RED "\n\nOpps! To-Do list is Empty :(\n\n\n" RESET);
    }
    else
    {
        {
            system("cls");
            printf(GREEN);
            printf("=========================================================\n");
            printf("  Sr No. |                  TODO LIST                       \n");
            printf("=========================================================\n\n");
            printf(RESET);
            todo_fptr = fopen("todos.txt", "r");
            if (todo_fptr == NULL)
            {
                printf(RED "Error in opening file\n" RESET);
                return;
            }
            char str[MAX_LENGTH];
            int count = 0;
            while (fgets(str, MAX_LENGTH, todo_fptr) != NULL)
            {
                count++;
                printf("  [%d]\t\t%s", count, str);
            }
            fclose(todo_fptr);
            if (count == 0)
            {
                printf(RED "\n\nOpps! TODO list is Empty :(\n\n\n" RESET);
            }
            else
            {
                printf("\n\n\n");
            }
        }
        printf(GREEN "\nEnter the To-Do's number that you want to remove.\n\t\t" RESET);
        scanf("%d", &x);

        if (x < 1 || x > count)
        {
            printf(RED "Invalid To-Do number.\n" RESET);
        }
        else
        {
            todo_fptr = fopen("todos.txt", "r");
            FILE *fp2 = fopen("temp.txt", "w");
            int i = 1;
            while (fgets(str, MAX_LENGTH, todo_fptr) != NULL)
            {
                if (i != x)
                    fputs(str, fp2);
                i++;
            }
            fclose(todo_fptr);
            fclose(fp2);
            remove("todos.txt");
            rename("temp.txt", "todos.txt");
            printf(RED "To-Do %d deleted.\n" RESET, x);
        }
    }
    system("pause");
}
void TODO()
{
    system("cls");
    system("cls");
    system("cls");
    printf(RED);
    printf("\t=============================================================================================\n");
    printf("\t=============================================================================================\n\n");
    printf(RESET);
    printf(MAGENTA);
    printf("\t\tTTTTTTTTTT  OOOOOOO    DDDDDDDDD      OOOOOOO      AAAAAAA   PPPPPPP   PPPPPPP\n");
    printf("\t\t    T      O       O   D        D    O       O     A     A   P      P  P      P\n");
    printf("\t\t    T      O       O   D         D   O       O     AAAAAAA   PPPPPPP   PPPPPPP\n");
    printf("\t\t    T      O       O   D        D    O       O     A     A   P         P\n");
    printf("\t\t    T       OOOOOOO    DDDDDDDDD      OOOOOOO      A     A   P         P\n");
    printf(RESET);
    printf("\n");
    printf(RED);
    printf("\t=============================================================================================\n");
    printf("\t=============================================================================================\n\n");
    printf(RESET);
}

// CALENDER

int first_week_day(int year)
{
    int d;
    d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400) + 1) % 7;
    return d;
}

int main()
{
    boot_animation();
    system("cls");
    Auth();
    {
        while (1)
        {
        main:
        xaryab:
            system("cls");
            printf("\n");
            Interface();
            int choice;
            printf(BLUE "Enter your choice (1-10): " GREEN);
            if (scanf("%d", &choice) != 1)
            {
                system("cls");
                fflush(stdin);
                printf(RED "Invalid input. Please enter a number.\n" RESET);
                goto xaryab;
            }
            switch (choice)
            {
            case 1:
            {
                int year, day, month_number, days_in_month, week_day, starting_day;

            loop:
                system("cls");
                printf(BLUE "\nEnter Your Desired Year: " GREEN);
                scanf("%d", &year);
                printf(RESET);
                char *months[] = {"January", "February", "March", "April", "May", "June", "July",
                                  "August", "September", "October", "November", "December"};
                int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                {
                    month_days[1] = 29;
                }

                starting_day = first_week_day(year);

                for (month_number = 0; month_number < 12; month_number++)
                {
                    days_in_month = month_days[month_number];
                    printf(YELLOW "\n\n--------------- " LIGHT_CYAN "%s" YELLOW " -------------------\n" RESET, months[month_number]);
                    printf(LIGHT_RED "\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n" RESET);

                    for (week_day = 0; week_day < starting_day; week_day++)
                    {
                        printf("     ");
                    }

                    for (day = 1; day <= days_in_month; day++)
                    {
                        printf("%5d", day);

                        if (++week_day > 6)
                        {
                            printf("\n");
                            week_day = 0;
                        }
                    }

                    starting_day = week_day;
                }

                int choice;
                printf(BLUE "\n\n[1] Try Again [2] Exit: " GREEN);
                scanf("%d", &choice);
                printf(RESET);
                if (choice == 1)
                {
                    goto loop;
                }
                else if (choice == 2)
                {
                    goto main;
                }
            }
            case 2:
            {
                int hour, minute, second;
                time_t current_time;
                char input;
                int stop_clock = 0;
                printf("Press 'Q' to quit the clock.\n");
                system("pause");
                usleep(500000);
                while (!stop_clock)
                {
                    if (_kbhit())
                    {
                        input = _getch();
                        if (input == 'q' || input == 'Q')
                        {
                            stop_clock = 1;
                            break;
                        }
                    }

                    current_time = time(NULL);
                    int total_seconds = current_time % 86400;
                    hour = (total_seconds / 3600 + 5) % 12;
                    minute = (total_seconds / 60) % 60;
                    second = total_seconds % 60;

                    system("cls || clear");
                    printf("\n\n\n\n\n\n\n\n\n");
                    printf("\n\t\t\t\t\t"
                           " _____________________________________");
                    printf("\n\t\t\t\t\t|                                    |");
                    printf("\n\t\t\t\t\t|            " LIGHT_GREEN "DIGITAL CLOCK" RESET "           |");
                    printf("\n\t\t\t\t\t|                                    |");
                    printf("\n\t\t\t\t\t|            " LIGHT_MAGENTA "Hr : Min : Sec" RESET "          |");
                    printf("\n\t\t\t\t\t|            " DEFAULT "%02d : %02d  : %02d" RESET "           |", hour, minute, second);
                    printf("\n\t\t\t\t\t|____________________________________|");
                    fflush(stdin);
                    sleep(1);
                }

                printf(GREEN "\nClock stopped. \nGoodbye!\n" RESET);
            }
            break;
            case 3:
            {
                int choice_1;
                system("cls");
                display();
                while (1)
                {

                    system("cls");
                    TODO();
                    printf("\n");
                    printf(GREEN);
                    printf("\n\n\n\t\t\t" RED "MAIN MENU" RESET "\n\t\t==========================\n\t\t" GREEN "[1] To see your To-Do list\n\t\t[2] To create new To-Do\n\t\t[3] To edit a To-Do\n\t\t[4] To delete your To-Do\n\t\t[5] Exit\n\t\t" RESET "==========================\n\t\t");
                    printf(RESET);
                    printf("\n\n\nEnter your choice\t:\t");
                    scanf("%d", &choice_1);

                    switch (choice_1)
                    {
                    case 1:
                        viewtodo();
                        break;
                    case 2:
                        createtodo();
                        break;
                    case 3:
                        edittodo();
                        break;
                    case 4:
                        deletetodo();
                        break;
                    case 5:
                        goto main;
                    default:
                        printf(RED "\nInvalid Choice\n" RESET);
                        system("pause");
                    }
                }
            }
            break;
            case 4:
            {
                system("cls");
                {
                    int found;
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
                    goto main;
                }
            }

            case 5:
            {
                int player = 1, choice, i;
                char mark;
                char invalidMove = 0;

                do
                {
                begin:
                    system("cls");

                    printf(GREEN "\n================================\n\t" RED "TicTacToe" GREEN "\n================================\n\n" RESET);
                    printf("Player 1 (X) - Player 2 (O)\n\n");

                    printf("     |     |     \n");
                    printf("  %c  |  %c  |  %c  \n", arr_quiz[1], arr_quiz[2], arr_quiz[3]);
                    printf("_____|_____|_____\n");
                    printf("     |     |     \n");
                    printf("  %c  |  %c  |  %c  \n", arr_quiz[4], arr_quiz[5], arr_quiz[6]);
                    printf("_____|_____|_____\n");
                    printf("     |     |     \n");
                    printf("  %c  |  %c  |  %c  \n", arr_quiz[7], arr_quiz[8], arr_quiz[9]);
                    printf("     |     |     \n");

                    if (invalidMove)
                    {
                        printf("Invalid move, please try again.\n");
                        invalidMove = 0;
                    }

                    player = (player % 2) ? 1 : 2;
                    printf("Player %d's turn: ", player);
                    scanf("%d", &choice);

                    mark = (player == 1) ? 'X' : 'O';

                    if (choice >= 1 && choice <= 9 && arr_quiz[choice] != 'X' && arr_quiz[choice] != 'O')
                    {
                        arr_quiz[choice] = mark;
                    }
                    else
                    {
                        invalidMove = 1;
                        while (getchar() != '\n')
                            ;
                        player--;
                    }

                    if (arr_quiz[1] == arr_quiz[2] && arr_quiz[2] == arr_quiz[3])
                        i = 1;
                    else if (arr_quiz[4] == arr_quiz[5] && arr_quiz[5] == arr_quiz[6])
                        i = 1;
                    else if (arr_quiz[7] == arr_quiz[8] && arr_quiz[8] == arr_quiz[9])
                        i = 1;
                    else if (arr_quiz[1] == arr_quiz[4] && arr_quiz[4] == arr_quiz[7])
                        i = 1;
                    else if (arr_quiz[2] == arr_quiz[5] && arr_quiz[5] == arr_quiz[8])
                        i = 1;
                    else if (arr_quiz[3] == arr_quiz[6] && arr_quiz[6] == arr_quiz[9])
                        i = 1;
                    else if (arr_quiz[1] == arr_quiz[5] && arr_quiz[5] == arr_quiz[9])
                        i = 1;
                    else if (arr_quiz[3] == arr_quiz[5] && arr_quiz[5] == arr_quiz[7])
                        i = 1;
                    else
                    {
                        i = 0;
                        for (int j = 1; j <= 9; j++)
                        {
                            if (arr_quiz[j] != 'X' && arr_quiz[j] != 'O')
                            {
                                i = -1;
                                break;
                            }
                        }
                    }

                    player++;
                } while (i == -1);

                system("cls");

                printf(GREEN "\n================================\n\t" RED "TicTacToe" GREEN "\n================================\n\n" RESET);
                printf("Player 1 (X) - Player 2 (O)\n\n");

                printf("     |     |     \n");
                printf("  %c  |  %c  |  %c  \n", arr_quiz[1], arr_quiz[2], arr_quiz[3]);
                printf("_____|_____|_____\n");
                printf("     |     |     \n");
                printf("  %c  |  %c  |  %c  \n", arr_quiz[4], arr_quiz[5], arr_quiz[6]);
                printf("_____|_____|_____\n");
                printf("     |     |     \n");
                printf("  %c  |  %c  |  %c  \n", arr_quiz[7], arr_quiz[8], arr_quiz[9]);
                printf("     |     |     \n");

                if (i == 1)
                {
                    printf(GREEN "\nPlayer %d won!\n" RESET, player - 1);
                }
                else
                {
                    printf(BLUE "Game Draw!\n" RESET);
                }

                for (int k = 1; k <= 9; k++)
                {
                    arr_quiz[k] = '0' + k;
                }
                int ch;
                printf(BLUE "\n\n\nEnter the Choice:" RESET "\n\n[1] Play Again\t[0] Exit\n\n");
                scanf("%d", &ch);
                if (ch == 1)
                {
                    goto begin;
                }
                system("pause");
                goto main;
            }

            case 6:
            {
                int choice_calc;
                do
                {
                    system("cls");
                    display_cal();
                    printf(CYAN "Enter your choice: " RESET);
                    printf(GREEN);
                    if (scanf("%d", &choice_calc) != 1)
                    {
                        system("cls");
                        printf(RED "Invalid input. Please enter a number.\n" RESET);
                        fflush(stdin);
                    }
                    printf(RESET);

                    system("cls");
                    switch (choice_calc)
                    {
                    case 1:
                        performcalculation();
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        printf(GREEN "Exiting the calculator. Thank you for using it!\n" RESET);
                        break;
                    default:
                        printf(RED "Invalid choice_calc. Please try again.\n" RESET);
                        system("pause");
                        system("cls");
                        break;
                    }
                } while (choice_calc != 2);

                goto main;
            }
            case 7:
            {
                int n;
                do
                {
                    system("cls");
                    printf(LIGHT_CYAN);
                    printf(GREEN "============================================" RED "Welcome to Quiz Games" GREEN "=======================================================\n" LIGHT_RED);
                    printf("Press\n" WHITE);
                    printf(" '1' for Maths Quiz\n '2' for General Knowledge Quiz \n '3' for English Quiz\n '4' for Physics Quiz\n '0' to exit\n  =  ");
                    printf(GREEN);
                    if (scanf("%d", &n) != 1)
                    {
                        system("cls");
                        printf(RED "Invalid input. Please enter a number.\n" RESET);
                        fflush(stdin);
                    }
                    printf(RESET);

                    printf(RESET);
                    system("cls");
                    if (n == 1)
                    {
                        printf(LIGHT_CYAN);
                        math();
                        printf(RESET);
                    }
                    else if (n == 2)
                    {
                        printf(LIGHT_CYAN);
                        GK();
                        printf(RESET);
                    }
                    else if (n == 3)
                    {
                        printf(LIGHT_CYAN);
                        Eng();
                        printf(RESET);
                    }
                    else if (n == 4)
                    {
                        printf(LIGHT_CYAN);
                        Physics();
                        printf(RESET);
                    }
                    else
                    {
                        if (n == 0)
                        {
                            break;
                        }
                        else
                        {
                            printf("Please Enter valid Input(1,2,3,4 or 0 to exit)\n\n");
                        }
                    }
                } while (n != 0);
                printf("Thank you for Playing, Come back soon Please");
                printf("\n\n");
                goto main;
            }
            case 8:
            {
                system("cls");
                printf(LIGHT_CYAN);
                int correct = 0;
                int score = 0;
                int wrong = 0;
                char jumble[50][15] = {
                    "elppa", "egnaro", "anbana", "treaw", "mruosr", "triesn", "dlro",
                    "aortc", "tihs", "pmupl", "oeush", "ndiogc", "eotv", "naorlod",
                    "weiv", "gsisnap", "retecs", "mstor", "hsalf", "mssei", "posh",
                    "ybdoeog", "kcab", "ullf", "pets", "llehs", "etirw", "meht",
                    "erutcip", "driew", "gniht", "draw", "tiodi", "emoh", "yretsym",
                    "retfa", "sdrib", "gnimmargorp", "htrae", "ogod", "rekcaj", "teews",
                    "elbmuj", "cimanyd", "lavivrus", "kcah", "tseuq", "tnaig", "doof",
                    "gnirps"};

                char correctWords[50][15] = {
                    "apple", "orange", "banana", "water", "rumors", "insert", "lord",
                    "actor", "this", "plump", "house", "coding", "vote", "ronaldo",
                    "view", "passing", "secret", "strom", "flash", "messi", "shop",
                    "goodbye", "back", "full", "step", "shell", "write", "them",
                    "picture", "weird", "thing", "ward", "idiot", "home", "mystery",
                    "after", "birds", "programming", "earth", "good", "jacket", "sweet",
                    "jumble", "dynamic", "survival", "hack", "quest", "giant", "food",
                    "spring"};
                printf(GREEN "========================================" RED "Welcome to Scrambled Words" GREEN "=====================================================\n" LIGHT_RED);
                printf("Instruction :\n" WHITE);
                printf("1) Enter the arrangement of words\n");
                printf("2) for each correct answer, score will be incremented by 4\n");
                printf("3) for each wrong answer, score will be deducted by 1\n");
                printf("4) -1 to exit\n");
                printf(LIGHT_CYAN);
                printf("\n");
                char word[15];
                for (int i = 0; i < 50; i++)
                {
                    printf(LIGHT_CYAN);
                    printf("\n\nWord %d: %s\n", i + 1, jumble[i]);
                    printf("Your answer: ");
                    scanf("%14s", word);

                    if (strcmp(word, "-1") == 0)
                    {
                        printf("\nThank you for playing\n");
                        break;
                    }

                    if (strcmp(word, correctWords[i]) == 0)
                    {
                        printf(GREEN "Correct!\n\n" LIGHT_GREEN);
                        correct++;
                        score += 4;
                    }
                    else
                    {
                        printf(RED "Wrong! The correct word was: %s\n\n" LIGHT_GREEN, correctWords[i]);
                        wrong++;
                        score--;
                    }
                }
                printf(RESET);
                printf("score = %d\n", score);
                printf("correct= %d\n", correct);
                printf("wrong = %d\n", wrong);
                printf(RESET);
                system("pause");
                system("cls");
                printf("\n\n");
                goto main;
            }
            case 9:
                printf(RED "\nSwitching Off ...." RESET);
                exit(0);
            case 10:
                system("cls");
                printf(GREEN "========================================" RED "DEVELOPERS" GREEN "=====================================================\n" LIGHT_RED);
                printf("\n\t\t\t[1] SYED ARHAM (LEADER)\n");
                printf("\t\t\t[2] XARYAB AWAN\n");
                printf("\t\t\t[3] SAAD NAEEM\n");
                printf("\t\t\t[4] RIDA BATOOL\n" RESET);
                printf(BLUE);
                system("pause");
                printf(RESET);
                break;
            default:
                printf(RED "\nInvalid choice.Try Again\n" RESET);
                system("pause");
                system("cls");
            }
        }
    }
}
