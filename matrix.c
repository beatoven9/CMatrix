#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matrix.h"

void MatrixCreationPrompt(){
    char *label;
    size_t bufsize = LABELMAXLEN;
    char dimensions[DIMENSIONSMAXLEN];
    char members[MEMBERSMAXLEN];

    if (( label = (char*) malloc(bufsize * sizeof( char))) == NULL){
        fprintf(stderr, "Unable to allocate memory to create label\n");
    }

    printf("How would you like to label your new matrix? ");
    getline(&label, &bufsize, stdin);

    printf("your label: %s\n", label);

    printf("What are the dimensions of your new matrix? enter in comma separated list( x,y )\n");
    scanf("%s", dimensions);

    printf("What are the members of your matrix?\n \
\t-Enter the members separated by spaces.\n \
\t-Separate each row with a semicolon (;)\n");
    scanf("%s", members);
    return;

}

//Matrix* CreateNewMatrix(MatrixDimensions dimensions, char label[LABELMAXLEN]){
//    Matrix *new;
//    strncpy(new->label, label, LABELMAXLEN-1);
//    new->m_dimensions.columns = dimensions.columns;
//    new->m_dimensions.rows = dimensions.rows;
//
//    if ((new = alloc_matrix_mem(new)) != NULL){
//        return new;
//    } else {
//        return NULL;
//    }
//}
//
//Matrix* alloc_matrix_mem(Matrix *matrix){
//    //This can only be called once the matrix's dimensions have been set
//    
//    if ((matrix->members = (int**) malloc( matrix->m_dimensions.rows * sizeof(int**) )) == NULL){
//        fprintf(stderr, "Unable to allocate memory for rows\n");
//        return NULL;
//    }
//
//    for (int i = 0; i < matrix->m_dimensions.rows; i++){
//        if ((matrix->members[i] = (int*) malloc(matrix->m_dimensions.columns * sizeof(int*))) == NULL){
//            fprintf(stderr, "Unable to allocate memory within row %i", i);
//            return NULL;
//        }
//    }
//
//    return matrix;
//}
//
//
//
