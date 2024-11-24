
#include <stdio.h>
#include <unistd.h>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"

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
        for (int j = 0; j < i; j++) {
            printf("=");
        }
        for (int j = i; j < total; j++) {
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

int main()
{
    boot_animation();
    return 0;
}