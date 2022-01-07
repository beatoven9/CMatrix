#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matrix.h"
#include "vector.h"

void PrintHelpMenu();

int main(int argc, char *argv[]){
    char c;

    char *input;
    size_t bufsize = 512;
    int userInputLen;

    if ( (input = (char*) malloc(bufsize * sizeof(char))) == NULL){
        fprintf(stderr, "Unable to allocate memory for user input\n");
    }

    printf("Welcome to CMatrix!\n\n");
    printf("\t-type 'h' to see options\n");

    while(1){
        printf(">>> ");
        getline(&input, &bufsize, stdin);
        userInputLen = strlen(input);
        if (userInputLen > 2){
            PrintHelpMenu();
            continue;
        }
        c = input[0];

        switch (c) {
            case 'h':
                PrintHelpMenu();
                break;
            case 'n':
                MatrixCreationPrompt();
                printf("New matrix created!\n");
                break;
            case 'v':
                VectorUserPrompt();
                printf("New matrix created!\n");
                break;
            case 'p':
                printf("Printing all matrices\n");
                break;
            case 'd':
                printf("Delete a matrix?\n");
                break;
            case 'a':
                printf("Adding matrices!\n");
                break;
            case 's':
                printf("Subtracting matrices\n");
                break;
            case 'm':
                printf("Multiply matrices together\n");
                break;
            case 'i':
                printf("Finding inverse matrix\n");
                break;
            case 'q':
                printf("Quitting\n");
                return 0;
                break;
            case '\n':
                break;
            default:
                printf("Command not recognized!\n");
                break;
        }
    }

    return 0;
}

void PrintHelpMenu(){
    printf("\nHELP:\n \
\tn: Create new matrix\n \
\tv: Create new vector\n \
\td: Delete matrix\n \
\tp: Print matrix\n \
\ta: Add matrices\n \
\ts: Subtract matrices\n \
\tm: Multiply matrices\n \
\ti: Find inverse matrix\n \
\tq: Quit\n\n");
}

