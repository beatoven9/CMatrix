#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector.h"

void VectorUserPrompt(Vector *newVector){
    char *labelInput;
    size_t labelBufSize = VECLABELMAXLEN;

    char *lengthInput;
    size_t lenBufSize = LENMAXLEN;

    char *elementsInput;
    size_t elementsBufSize = ELEMENTSMAXLEN;

    int vectorLength;
    double *elementsArray;
    elementsArray = (double*) malloc(sizeof(double));

    if ( (labelInput = (char*) malloc(labelBufSize * sizeof(char))) == NULL){
        fprintf(stderr, "unable to allocate memory for labelInput of Vector\n");
        return ;
    }

    printf("What is the label of your new Vector?");
    getline(&labelInput, &labelBufSize, stdin);

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

    //I'm not totally clear on why I need to set this
    //I think that it should be enough that I'm setting it inside of the function
    //since I pass it as a pointer. I'm clearly misunderstanding something
    elementsArray = ParseElementsInput(elementsArray, elementsInput);

    CreateNewVector(newVector, labelInput, vectorLength, elementsArray);
    
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

//This isn't error handling user error yet
int ParseLengthInput(char *lengthInput){
    char *tail;
    int result;
    tail = (char*) malloc(LINEMAX * sizeof(char));
    result = strtol(lengthInput, &tail, 10);
    //if (strcmp(tail, "") != 0){
    //    fprintf(stderr, "Error parsing vector length!\n");
    //    return -1;
    //} else {
    //    return result;
    //}
    return result;
}

int CreateNewVector(Vector *newVector, char* labelInput, int vectorLength, double *elementsArray){
    int i;

    newVector->label = (char*) malloc(VECLABELMAXLEN * sizeof(char));
    strncpy(newVector->label, labelInput, VECLABELMAXLEN - 1);
    newVector->length = vectorLength;
    newVector->elements = (double*) malloc(vectorLength * sizeof(double));

    for (i = 0; i < vectorLength; i++){
        newVector->elements[i] = elementsArray[i];
    }
    return 0;
}
