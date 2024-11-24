#include <stdio.h>
#include <math.h>
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

#define M_PI 3.142141


void display_calc();
void displaycalculationmenu();
void performcalculation();
double add(double* numbers, int count);
double sub(double* numbers, int count);
double mul(double* numbers, int count);
double division(double* numbers, int count);
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





int main()
{
    int choice_calc;
    do
    {
        display_cal();
        printf(CYAN "Enter your choice_calc: " RESET);
        scanf("%d", &choice_calc);
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

    return 0;
}

