#include "Matrix.h"

Matrix createMatrix(int width, int height)
{
    Matrix m;
    int i;

    m.width = width;
    m.height = height;

    m.data = malloc(height * sizeof(double *));
    for (i = 0; i < height; i++)
        m.data[i] = malloc(width * sizeof(double));
    return m;
}
void fillRandom(Matrix m)
{
    int i, j;
    for (i = 0; i < m.height; i++) {
        for (j = 0; j < m.width; j++) {
            m.data[i][j] = rand() % 100;
        }
    }
}
void printMatrix(Matrix m)
{
    int i, j;
    for (i = 0; i < m.height; i++) {
        for (j = 0; j < m.width; j++) {
            printf("%lf ", m.data[i][j]);
        }
        printf("\n");
    }
}
