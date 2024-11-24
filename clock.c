#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h> 

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

int main() {
    int hour, minute, second;
    time_t current_time;
    char input;
    int stop_clock = 0;

    printf("Press 'Q' to quit the clock.\n");
    usleep(500000); 
    while (!stop_clock) {
        if (_kbhit()) {
            input = _getch();
            if (input == 'q' || input == 'Q') {
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
        printf("\n\t\t\t\t\t"" _____________________________________");
        printf("\n\t\t\t\t\t|                                    |");
        printf("\n\t\t\t\t\t|            "LIGHT_GREEN"DIGITAL CLOCK"RESET"           |");
        printf("\n\t\t\t\t\t|                                    |");
        printf("\n\t\t\t\t\t|            "LIGHT_MAGENTA"Hr : Min : Sec"RESET"          |");
        printf("\n\t\t\t\t\t|            "DEFAULT"%02d : %02d  : %02d"RESET"           |", hour, minute, second);
        printf("\n\t\t\t\t\t|____________________________________|");
        fflush(stdin);
        sleep(1);
    }

    printf(GREEN"\nClock stopped. \nGoodbye!\n"RESET);
    return 0;
}
