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

    Vector **v_array;
    v_array = (Vector**) malloc(sizeof(Vector*));
    int currentIndex = 0;
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
            {
                PrintHelpMenu();
                break;

            }
            case 'n':
            {
                MatrixCreationPrompt();
                printf("New matrix created!\n");
                break;
            }
            case 'v':
            {
                v_array[currentIndex] = (Vector*) malloc(sizeof(Vector));
                VectorUserPrompt(v_array[currentIndex]);
                v_arrayLength++;
                currentIndex++;
                v_array = (Vector**) realloc(v_array, (currentIndex + 1) * sizeof(Vector*));
                v_array[currentIndex + 1] = NULL;
                printf("New vector created!\n");
                break;
            }
            case 'p':
            {
                //This should be fixed above
                //I need a better way to mark the end of the array 
                //A NULL value is probably the best way, because then I would be able to use a while loop
                // or find a way to only keep the length of the array, not one past the end
                // Maybe I can have it be an array of pointers instead of an array of vectors

                for (i = 0; i < v_arrayLength - 1; i++){
                    PrintVector(v_array[i]);
                }
                break;
            }
            case 'd':
            {
                printf("Delete a matrix not yet implemented\n");
                break;
            }
            case 'a':
            {
                Vector *sum = (Vector* ) malloc(sizeof(Vector));
                sum = AddVectors(v_array[currentIndex - 1], v_array[currentIndex - 2], sum);
                if (sum != NULL){
                    PrintVector(sum);
                }
                break;
            }
            case 's':
            {
                printf("Subtracting matrices not yet implemented\n");
                break;
            }
            case 'm':
            {
                double *result;
                result = (double*) malloc(sizeof(double));
                result = DotProductVectors(v_array[currentIndex - 1], v_array[currentIndex - 2], result);
                printf("Dot product is: %f\n", *result);
                break;
            }
            case 'i':
            {
                printf("Finding inverse matrix not yet implemented\n");
                break;
            }
            case 'q':
            {
                return 0;
                break;
            }
            case '\n':
            {
                break;
            }
            default:
            {
                printf("Command not recognized!\n");
                break;
            }
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

