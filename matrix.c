#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matrix.h"

//test to see if you can create matrix dimensions without an error.
//then work on entering the elements
//then work on the print function
//
//I should have matrices organized as an array of vectors.
//I might want another struct specifically for Vectors
//  This way, I can use vectors as the basis for addition/multiplication
//for example. I can figure out Vector addition and then for matrices, iterate through the vectors.
//      I can figure out multiplying vectors by a scalar and then use this + vector addition as the 
//          building blocks for dot products.

void MatrixCreationPrompt(){
    char *label;
    size_t labelbufsize = LABELMAXLEN;

    char *dimensions;
    size_t dimbufsize = DIMENSIONSMAXLEN;
    MatrixDimensions *m_dimensions;

    char *members;
    size_t membersbufsize = MEMBERSMAXLEN;

    if (( label = (char*) malloc(labelbufsize * sizeof( char))) == NULL){
        fprintf(stderr, "Unable to allocate memory to create label\n");
    }

    printf("How would you like to label your new matrix? ");
    getline(&label, &labelbufsize, stdin);

    if (( dimensions = (char*) malloc(dimbufsize * sizeof( char))) == NULL){
        fprintf(stderr, "Unable to allocate memory to create dimensions input\n");
    }
    if (( m_dimensions = (MatrixDimensions*) malloc(sizeof( MatrixDimensions))) == NULL){
        fprintf(stderr, "Unable to allocate memory for m_dimensions\n");
    }
    printf("What are the dimensions of your new matrix? enter in comma separated list( x,y )\n");
    getline(&dimensions, &dimbufsize, stdin);

    if ( ParseDimensionsInput(m_dimensions, dimensions) == NULL){
        fprintf(stderr, "Error while parsing dimensions input\n");
    }

    if (( members = (char*) malloc(membersbufsize * sizeof( char))) == NULL){
        fprintf(stderr, "Unable to allocate memory to create members input\n");
    }
    printf("What are the members of your matrix?\n \
\t-Enter the members separated by spaces.\n \
\t-Separate each row with a semicolon (;)\n");
    getline(&members, &membersbufsize, stdin);

    //Here we'll use this input to create a matrix and put it in a list of saved matrices
    Matrix *newMatrix;

    if ((newMatrix = (Matrix*) malloc(sizeof(Matrix))) == NULL){
        fprintf(stderr, "Unable to allocate memory for creation of a new matrix.\n");        
    }

    if (CreateNewMatrix(newMatrix, *m_dimensions, label) == NULL){
        fprintf(stderr, "Error creating the new Matrix\n");
    }

    free(label);
    free(dimensions);
    free(members);
    return;

}

Matrix* CreateNewMatrix(Matrix *newMatrix, MatrixDimensions dimensions, char label[LABELMAXLEN]){
    strncpy(newMatrix->label, label, LABELMAXLEN-1);
    newMatrix->m_dimensions.columns = dimensions.columns;
    newMatrix->m_dimensions.rows = dimensions.rows;

    if ((newMatrix = alloc_matrix_mem(newMatrix)) != NULL){
        return newMatrix;
    } else {
        return NULL;
    }
}

Matrix* alloc_matrix_mem(Matrix *matrix){
    
    if ((matrix->members = (int**) malloc( matrix->m_dimensions.rows * sizeof(int**) )) == NULL){
        fprintf(stderr, "Unable to allocate memory for rows\n");
        return NULL;
    }

    for (int i = 0; i < matrix->m_dimensions.rows; i++){
        if ((matrix->members[i] = (int*) malloc(matrix->m_dimensions.columns * sizeof(int*))) == NULL){
            fprintf(stderr, "Unable to allocate memory within row %i", i);
            return NULL;
        }
    }

    return matrix;
}


MatrixDimensions* ParseDimensionsInput(MatrixDimensions *m_dimensions, char *dimensionsInput){
    m_dimensions->columns = atoi(strtok(dimensionsInput, ","));
    m_dimensions->rows = atoi(strtok(NULL, ","));
    if ( strtok(NULL, ",") == NULL){
        fprintf(stderr, "Incorrect form entered for dimensions\n");
        return NULL;
    }

    return m_dimensions;
}

