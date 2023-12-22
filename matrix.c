#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

void inverseMatrix()
{
	int size, i, j, k;
	printf("Write matrix size: ");
	scanf_s("%d", &size);
	double** matrix = malloc(size * sizeof(double)); 
	double** matrixBuff = malloc(size * sizeof(double));
	for (int i = 0; i < size; i++)
	{
		matrix[i] = malloc(size * sizeof(double));
		matrixBuff[i] = malloc(size * sizeof(double));
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			scanf_s("%lf", &matrix[i][j]);
			if (i == j)
			{
				matrixBuff[i][j] = 1;
			}
			else
			{
				matrixBuff[i][j] = 0;
			}
		}
	}
	for (k = 0; k < size; k++) {
		double scalar = matrix[k][k];
		for (j = 0; j < size; j++) {
			matrix[k][j] /= scalar;
			matrixBuff[k][j] /= scalar;
		}

		for (i = 0; i < size; i++) {
			if (i != k) {
				double temp = matrix[i][k];
				for (j = 0; j < size; j++) {
					matrix[i][j] -= temp * matrix[k][j];
					matrixBuff[i][j] -= temp * matrixBuff[k][j];
				}
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		printf("\n");
		for (int j = 0; j < size; j++)
		{
			printf("%lf ",matrixBuff[i][j]);
		}
	}
}
