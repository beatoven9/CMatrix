#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector.h"

//This might have to be different
//Maybe, the main function keeps an array of vectors and matrices.
//then, when this function is called, the array gets passed to the function
//and this function adds the new vector to the array.
void VectorUserPrompt(){
    char *lengthInput;
    size_t lenBufSize = LENMAXLEN;

    char *elementsInput;
    size_t elementsBufSize = ELEMENTSMAXLEN;

    int vectorLength;
    double *elementsArray;
    elementsArray = (double*) malloc(sizeof(double));

    if ( (lengthInput = (char*) malloc(lenBufSize * sizeof(char))) == NULL){
        fprintf(stderr, "unable to allocate memory for lengthInput of Vector\n");
        return ;
    }

    printf("What is the length of your new Vector?");
    getline(&lengthInput, &lenBufSize, stdin);

    if ((vectorLength = ParseLengthInput(lengthInput)) == -1){
        fprintf(stderr, "Error occured parsing lengthInput\n");
    }

    if ( (elementsInput = (char*) malloc(elementsBufSize * sizeof(char))) == NULL){
        fprintf(stderr, "unable to allocate memory for elementsInput of Vector\n");
        return ;
    }

    printf("Enter the elements of your vector in a space separated list.\n");
    getline(&elementsInput, &elementsBufSize, stdin);

    ParseElementsInput(elementsArray, elementsInput);

    CreateNewVector(vectorLength, elementsArray);
    
    free(lengthInput);
    free(elementsInput);

}

Vector* AddVectors(Vector vectorA, Vector vectorB, Vector *result){
    int i;

    if (vectorA.length == vectorB.length){
        for (i = 0; i < vectorA.length; i++){
            result->elements[i] = vectorA.elements[i] + vectorB.elements[i];
        }
        return result;
    }else{
        fprintf(stderr, "Attempting to add two vectors of unequal length\n");
        return NULL;
    }
}

double* ParseElementsInput(double *elementsArray, char *elementsInput){
    int elementsIndex = 0;
    int numElements = 1;
    char *currentElement;

    currentElement = strtok(elementsInput, " ");
    elementsArray[elementsIndex] = strtod(currentElement, NULL);
    
    while ((currentElement = strtok(NULL, " ")) != NULL){
        elementsIndex++; 
        numElements = elementsIndex + 1;
        elementsArray = realloc(elementsArray, numElements * sizeof(double));
        elementsArray[elementsIndex] = strtod(currentElement, NULL);
    } 
    return elementsArray;
}

int ParseLengthInput(char *lengthInput){
    char *tail;
    int result;
    tail = (char*) malloc(LINEMAX * sizeof(char));
    result = strtol(lengthInput, &tail, 10);
    if (tail[0] != '\0' ){
        fprintf(stderr, "Error parsing vector length!\n");
        return -1;
    } else {
        return result;
    }
}

Vector* CreateNewVector(int vectorLength, double *elementsArray){
    return NULL;
}
