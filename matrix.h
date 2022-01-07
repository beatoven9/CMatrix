#include <stdlib.h>
#include <stdio.h>

#define LABELMAXLEN 64
#define DIMENSIONSMAXLEN 64
#define MEMBERSMAXLEN 512

typedef struct MatrixDimensions {
    int columns;
    int rows;
} MatrixDimensions;

typedef struct Matrix {
    MatrixDimensions m_dimensions;
    char label[LABELMAXLEN];

    int **members;
} Matrix;

Matrix* CreateNewMatrix(Matrix *newMatrix, MatrixDimensions dimensions, char label[LABELMAXLEN]);

Matrix* alloc_matrix_mem(Matrix *matrix);

MatrixDimensions* ParseDimensionsInput(MatrixDimensions *m_dimensions, char *dimensionsInput);

void MatrixCreationPrompt();
