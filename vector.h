
#define LENMAXLEN 512
#define ELEMENTSMAXLEN 512 
#define LINEMAX 512
#define VECLABELMAXLEN 512

typedef struct Vector{
    char* label;
    int length;
    double *elements;
} Vector;

Vector* AddVectors(Vector vectorA, Vector vectorB, Vector *result);
void VectorUserPrompt(Vector *newVector);
int CreateNewVector(Vector *newVector, char* labelInput, int vectorLength, double *elementsArray);

double* ParseElementsInput(double *elementsArray, char *elementsInput);
int ParseLengthInput(char *lengthInput);
