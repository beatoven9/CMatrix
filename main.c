#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    int c;

    printf("Welcome to CMatrix!\n\n");
    printf("\t-type 'h' to see options\n");

    while((c = getchar()) != 'q'){
        switch (c) {
            case 'h':
                printf("Printing help message!\n");
                break;
            case 'n':
                printf("Making a new matrix!\n");
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
            case '\n':
                break;
            default:
                printf("Command not recognized!\n");
                break;
        }
    }
    return 0;
}
