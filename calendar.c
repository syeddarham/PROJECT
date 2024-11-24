#include <stdio.h>
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

int first_week_day(int year)
{
    int d;
    d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400) + 1) % 7;
    return d;
}

int main()
{
    int year, day, month_number, days_in_month, week_day, starting_day;

loop:
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
        return 0;
    }
}