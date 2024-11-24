#include <stdio.h>

char arr_quiz[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main() {
    int player = 1, choice, i;
    char mark;
    char invalidMove = 0;

    do {

        printf("\n================================\n\tTicTacToe\n================================\n\n");
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

        if (invalidMove) {
            printf("Invalid move, please try again.\n");
            invalidMove = 0;
        }

        player = (player % 2) ? 1 : 2;
        printf("Player %d's turn: ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice >= 1 && choice <= 9 && arr_quiz[choice] != 'X' && arr_quiz[choice] != 'O') {
            arr_quiz[choice] = mark;
        } else {
            invalidMove = 1;
            while (getchar() != '\n'); 
            player--;
        }

        if (arr_quiz[1] == arr_quiz[2] && arr_quiz[2] == arr_quiz[3]) i = 1;
        else if (arr_quiz[4] == arr_quiz[5] && arr_quiz[5] == arr_quiz[6]) i = 1;
        else if (arr_quiz[7] == arr_quiz[8] && arr_quiz[8] == arr_quiz[9]) i = 1;
        else if (arr_quiz[1] == arr_quiz[4] && arr_quiz[4] == arr_quiz[7]) i = 1;
        else if (arr_quiz[2] == arr_quiz[5] && arr_quiz[5] == arr_quiz[8]) i = 1;
        else if (arr_quiz[3] == arr_quiz[6] && arr_quiz[6] == arr_quiz[9]) i = 1;
        else if (arr_quiz[1] == arr_quiz[5] && arr_quiz[5] == arr_quiz[9]) i = 1;
        else if (arr_quiz[3] == arr_quiz[5] && arr_quiz[5] == arr_quiz[7]) i = 1;
        else {
            i = 0;
            for (int j = 1; j <= 9; j++) {
                if (arr_quiz[j] != 'X' && arr_quiz[j] != 'O') {
                    i = -1;
                    break;
                }
            }
        }

        player++;
    } while (i == -1);

    system("cls");

    printf("\n================================\n\tTicTacToe\n================================\n\n");
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

    if (i == 1) {
        printf("Player %d won!\n", player - 1);
    } else {
        printf("Game Draw!\n");
    }

    system("pause");
}

