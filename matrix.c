#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** createIdentity(int size_)
{
	double** identityMatrix = malloc(size_ * sizeof(double*));
	if (!identityMatrix)
	{
		free(identityMatrix);
		return 0;
	}
	for (int i = 0; i < size_; i++)
	{
		identityMatrix[i] = malloc(size_*sizeof(double));
		if (!identityMatrix[i])
		{
			return 0;
		}
	}
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
		{
			if (i == j)
			{
				identityMatrix[i][j] = 1;
			}
			else
			{
				identityMatrix[i][j] = 0;
			}
		}
	}
	return identityMatrix;
}

int inverseMatrix(double** matrix_, double** identity_, int size_)
{
	int k, j, i;
	for (k = 0; k < size_; k++)
	{
		double scalar = matrix_[k][k];
		for (j = 0; j < size_; j++)
		{
			matrix_[k][j] /= scalar;
			identity_[k][j] /= scalar;
		}
		for (i = 0; i < size_; i++)
		{
			if (i != k) {
				double temp = matrix_[i][k];
				for (j = 0; j < size_; j++)
				{
					matrix_[i][j] -= temp * matrix_[k][j];
					identity_[i][j] -= temp * identity_[k][j];
				}
			}
		}
	}
	return 0;
}

void printMatrix(double** matrix_, int size_)
{
	for (int i = 0; i < size_; i++)
	{
		printf("\n");
		for (int j = 0; j < size_; j++)
		{
			printf("%.3lf ", matrix_[i][j]);
		}
	}
}

double determinantAll(double** matrix_, int size_) //Ќахождени€ определител€ дл€ нужного размера
{
	int k = 0;
	int l = 0;
	int s = 0;
	int tempSize = size_;
	int ones = 1;
	while (tempSize != 3)
	{
		for (k = s; k < size_; k++)
		{
			double temp = matrix_[k][0];
			for (l = s; l < size_; l++)
			{
				matrix_[k][l] = matrix_[k][l] / temp;
			}
		}
		for (k = s; k < tempSize - 1; k++)
		{
			for (l = s; l < tempSize; l++)
			{
				matrix_[k][l] = matrix_[k][l] - matrix_[tempSize - 1][l];
			}
		}
		tempSize -= 1;
		ones *= pow(-1, (1 + (l)));
		s++;
	}

	//printMatrix(matrix_, size_);

	double** matrixTemp = malloc(3 * sizeof(double*));
	for (int i = 0; i < 3; i++)
	{
		matrixTemp[i] = malloc(3 * sizeof(double));
	}
	k = 0;
	l = s;
	for (size_t i = 0; i < 3; i++)
	{
		l = s;
		for (size_t j = 0; j < 3; j++)
		{
			matrixTemp[i][j] = matrix_[k][l];
			l++;
		}
		k++;
	}
	printMatrix(matrixTemp, 3);
	printf("\n%lf", determinant(matrixTemp));

	return 0;
}

double determinant(double** matrix_) //Ќахождение определител€ дл€ матрицы 3 на 3
{
	double determinantM = 0;
	determinantM =
		(matrix_[0][0] * matrix_[1][1] * matrix_[2][2]) +
		(matrix_[0][1] * matrix_[1][2] * matrix_[2][0]) +
		(matrix_[1][0] * matrix_[2][1] * matrix_[0][2]) +
		(-(matrix_[0][2] * matrix_[1][1] * matrix_[2][0]) -
			(matrix_[0][1] * matrix_[1][0] * matrix_[2][2]) -
			(matrix_[0][0] * matrix_[1][2] * matrix_[2][1]));
	return determinantM;
}