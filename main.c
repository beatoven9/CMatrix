#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matrix.h"
#include "vector.h"

void PrintHelpMenu();

int main(int argc, char *argv[]){
    char c;
    int i;

    char *input;
    size_t bufsize = 512;
    int userInputLen;

    Vector *v_array;
    v_array = (Vector*) malloc(sizeof(Vector));
    int v_arrayLength = 1;

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
                VectorUserPrompt(&v_array[v_arrayLength - 1]);
                v_arrayLength++;
                v_array = (Vector*) realloc(v_array, (v_arrayLength) * sizeof(Vector));
                printf("New vector created!\n");
                break;
            case 'p':
                //This should be fixed above
                //I need a better way to mark the end of the array 
                //          this is probably the best way, because then I would be able to use a while loop
                // or find a way to only keep the length of the array, not one past the end
                for (i = 0; i < v_arrayLength - 1; i++){
                    PrintVector(&v_array[i]);
                }
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

