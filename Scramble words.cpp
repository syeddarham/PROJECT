#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

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



int main(){
	system("cls");
	printf(LIGHT_CYAN);
	int correct=0;
    int score=0;
    int wrong=0;
    char jumble[50][15] = {
        "elppa",   "egnaro",  "anbana",  "treaw", "mruosr",   "triesn",  "dlro", 
        "aortc",   "tihs",    "pmupl",   "oeush",   "ndiogc",  "eotv",    "naorlod",
        "weiv",    "gsisnap", "retecs",  "mstor",   "hsalf",   "mssei",    "posh", 
        "ybdoeog",  "kcab",    "ullf",   "pets",    "llehs",   "etirw",   "meht", 
        "erutcip", "driew",   "gniht",   "draw",    "tiodi",    "emoh",    "yretsym", 
        "retfa",   "sdrib",   "gnimmargorp", "htrae", "ogod",   "rekcaj",  "teews", 
        "elbmuj",  "cimanyd", "lavivrus", "kcah",   "tseuq",   "tnaig",   "doof", 
        "gnirps"
    };
    
    char correctWords[50][15] = {
        "apple", "orange", "banana", "water", "rumors", "insert", "lord",
        "actor", "this", "plump", "house", "coding", "vote", "ronaldo",
        "view", "passing", "secret", "strom", "flash", "messi", "shop",
        "goodbye", "back", "full", "step", "shell", "write", "them",
        "picture", "weird", "thing", "ward", "idiot", "home", "mystery",
        "after", "birds", "programming", "earth", "good", "jacket", "sweet",
        "jumble", "dynamic", "survival", "hack", "quest", "giant", "food",
        "spring"
    };
	printf(GREEN"========================================"RED"Welcome to Scrambled Words"GREEN"=====================================================\n"LIGHT_RED);
    printf("Instruction :\n"WHITE);
    printf("1) Enter the arrangement of words\n");
    printf("2) for each correct answer, score will be incremented by 4\n");
    printf("3) for each wrong answer, score will be deducted by 1\n");
    printf("4) -1 to exit\n");
    printf(LIGHT_CYAN);
    printf("\n");
    char word[15];
    for (int i = 0; i < 50; i++) {
    	printf(LIGHT_CYAN);
        printf("\n\nWord %d: %s\n", i + 1, jumble[i]); 
        printf("Your answer: ");
        scanf("%14s", word);  
        
        if(strcmp(word,"-1")==0){
        printf("\nThank you for playing\n");
        break;
        }
        
        if (strcmp(word, correctWords[i]) == 0) { 
            printf(GREEN "Correct!\n\n" LIGHT_GREEN);
            correct++;
            score+=4;
        } else {
            printf(RED "Wrong! The correct word was: %s\n\n" LIGHT_GREEN, correctWords[i]);
            wrong++;
            score--;
        }
    }
    printf(RESET);
    printf("score = %d\n",score);
    printf("correct= %d\n",correct);
    printf("wrong = %d\n",wrong);
    printf(RESET);
    system("pause");
    system("cls");
    
    printf("\n\n");
}

