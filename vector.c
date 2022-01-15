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

Vector* AddVectors(Vector *vectorA, Vector *vectorB, Vector *result){
    int i;

    if (vectorA->length == vectorB->length){
        result->elements = (double *) malloc(vectorA->length * sizeof(double));
        for (i = 0; i < vectorA->length; i++){
            result->elements[i] = vectorA->elements[i] + vectorB->elements[i];
        }
        result->label = (char*) malloc( LINEMAX * (sizeof(char)));
        strncpy(result->label, "Sum of two vectors", LINEMAX);
        result->length = vectorA->length;
        printf("Successfully added the two\n");
        return result;
    }else{
        fprintf(stderr, "Attempting to add two vectors of unequal length\n");
        return NULL;
    }
}

double* DotProductVectors(Vector *vectorA, Vector *vectorB, double *result){
    int i;
    *result = 0;

    printf("about to get dot product of %s and %s\n", vectorA->label, vectorB->label);
    if (vectorA->length == vectorB->length){
        for (i = 0; i < vectorA->length; i++){
            *result += vectorA->elements[i] * vectorB->elements[i];
        }
        printf("Successfully multiplied the two\n");
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
    if (newVector->label == NULL){
        fprintf(stderr, "Unable to allocate memory for newVector->label\n");
        return -1;
    }
    strncpy(newVector->label, labelInput, VECLABELMAXLEN - 1);
    newVector->length = vectorLength;
    newVector->elements = (double*) malloc(vectorLength * sizeof(double));
    if (newVector->elements == NULL){
        fprintf(stderr, "unable to locate memory for newVector->elementsArray\n");
        return -1;
    }
    newVector->largestElement = 0;

    for (i = 0; i < vectorLength; i++){
        printf("Adding element %f to array\n", elementsArray[i]);
        newVector->elements[i] = elementsArray[i];
        if (newVector->largestElement < elementsArray[i]){
            newVector->largestElement = elementsArray[i];
        }
    }
    return 0;
}

int DigitCount(double num, int precision){
    int divisor = 10;
    int digitCount = 1;

    while(((int) num / divisor)){
        digitCount++;
        divisor *= 10;
    }
    return digitCount;
}

void PrintVector(Vector *vector){
    int i, j; 
    int precision = 2;
    int numOfSpaces;
    int largestElementDecimalPlaces = 1;
    int currentElementDecimanlPlaces = 1;
    //int divisor;

    largestElementDecimalPlaces = DigitCount(vector->largestElement, precision);

    numOfSpaces = largestElementDecimalPlaces + precision + 1; // + 1 is for the decimal point

    printf("Vector: %s\n", vector->label);
    printf("\t*-");
    for (i = 0; i < numOfSpaces; i++){
        printf(" ");
    }
    printf("-*\n");
    for (i = 0; i < vector->length; i++){
        printf("\t| %.*f", precision, vector->elements[i]);

        currentElementDecimanlPlaces = DigitCount(vector->elements[i], precision);

//        divisor = 10;
//        currentElementDecimanlPlaces = 1;
//        while(((int) vector->elements[i] / divisor)){
//            currentElementDecimanlPlaces++;
//            divisor *= 10;
//        }
        int spaces = largestElementDecimalPlaces - currentElementDecimanlPlaces;

        for (j = 0; j < spaces; j++){
            printf(" ");
        }
        printf(" |\n");
    }
    printf("\t*-");
    for (i = 0; i < numOfSpaces; i++){
        printf(" ");
    }
    printf("-*\n");
    printf("\n");
}
