#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

int main(int argc, char *argv[]){
    char c;

    char *input;
    size_t bufsize = 512;

    if ( (input = (char*) malloc(bufsize * sizeof(char))) == NULL){
        fprintf(stderr, "Unable to allocate memory for user input\n");
    }

    printf("Welcome to CMatrix!\n\n");
    printf("\t-type 'h' to see options\n");

    while(1){
        printf(">>> ");
        getline(&input, &bufsize, stdin);
        c = input[0];

        switch (c) {
            case 'h':
                printf("Printing help message!\n");
                break;
            case 'n':
                MatrixCreationPrompt();
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
//    while((c = getchar()) != 'q'){
//        switch (c) {
//            case 'h':
//                printf("Printing help message!\n");
//                break;
//            case 'n':
//                MatrixCreationPrompt();
//                printf("Making a new matrix!\n");
//                break;
//            case 'p':
//                printf("Printing all matrices\n");
//                break;
//            case 'd':
//                printf("Delete a matrix?\n");
//                break;
//            case 'a':
//                printf("Adding matrices!\n");
//                break;
//            case 's':
//                printf("Subtracting matrices\n");
//                break;
//            case 'm':
//                printf("Multiply matrices together\n");
//                break;
//            case '\n':
//                break;
//            default:
//                printf("Command not recognized!\n");
//                break;
//        }
//    }

