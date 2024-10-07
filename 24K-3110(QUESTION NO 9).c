#include <stdio.h>

int main() {
    int marks = 0;         
    int wrongcount = 0;   
    int answer;           

    printf("Welcome to the University Entry Test\n");  
    
    printf("\nQuestion 1:\n");
    printf("1. Option A\n");
    printf("2. Option B\n");
    printf("3. Option C\n");
    printf("4. Option D\n");
    printf("enter your answer (1-4): ");
    scanf("%d", &answer);
    if (answer == 1) { // Assuming the correct answer = Option A
        marks += 4;
        printf("Correct answer! You've gained 4 marks.\n");
    } else {
        marks -= 1;
        wrongcount++;
        printf("Wrong answer! You've lost 1 mark.\n");
    }
    printf("\nQuestion 2:\n");
    printf("1. Option A\n");
    printf("2. Option B\n");
    printf("3. Option C\n");
    printf("4. Option D\n");
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    if (answer == 2) {  // assuming the correct answer = Option B
        marks += 4;
        printf("Correct answer! You've gained 4 marks.\n");
    } else {
        marks -= 1;
        wrongcount++;
        printf("Wrong answer! You've lost 1 mark.\n");
    }


    printf("\nQuestion 3:\n");
    printf("1. Option A\n");
    printf("2. Option B\n");
    printf("3. Option C\n");
    printf("4. Option D\n");
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    if (answer == 3) { // assuming the correct answer = Option C
        marks += 4;
        printf("Correct answer! You've gained 4 marks.\n");
    } else {
        marks -= 1;
        wrongcount++;
        printf("Wrong answer! You've lost 1 mark.\n");
    }

    printf("\nQuestion 4:\n");
    printf("1. Option A\n");
    printf("2. Option B\n");
    printf("3. Option C\n");
    printf("4. Option D\n");
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    if (answer == 4) { // assuming the correct answer = Option D
        marks += 4;
        printf("Correct answer! You've gained 4 marks.\n");
    } else {
        marks -= 1;
        wrongcount++;
        printf("Wrong answer! You've lost 1 mark.\n");
    }

    
    if (wrongcount >= 4) {
        printf("Sorry, you did not qualify for the admission.\n");
        return 0; 
    }

    printf("\nQuestion 5:\n");
    printf("1. Option A\n");
    printf("2. Option B\n");
    printf("3. Option C\n");
    printf("4. Option D\n");
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    if (answer == 1) { // assuming the correct answer = Option A
        marks += 4;
        printf("Correct answer! You've gained 4 marks.\n");
    } else {
        marks -= 1;
        wrongcount++;
        printf("Wrong answer! You've lost 1 mark.\n");
    }

    if (marks >= 20) {
        printf("Congratulations, you have qualified for the admission!\n");
        return 0; 
    }


    printf("\nYour final score is: %d\n", marks);
    if (marks < 20) {
        printf("You did not qualify for the admission.\n");
    }

    return 0;
}
