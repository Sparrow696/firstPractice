#include <stdio.h>
#include <locale.h>
#include "matrix.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	int choise = 0;
	int size = 0;
	printf("1. Нахождение обратной матрицы.");
	printf("\n2. Решение матрицы методом Крамера.\n");
	scanf_s("%d", &choise);
	switch (choise) {
	case 1:
		printf("Введите размер матрицы:");
		scanf_s("%d", &size);
		printf("Введите элементы матрицы:");
		double** matrix1 = malloc(size * sizeof(double*)); // Вводим матрицу
		for (int i = 0; i < size; i++)
		{
			matrix1[i] = malloc(size * sizeof(double));
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				printf("\nA[%d][%d] = ",i+1,j+1);
				scanf_s("%lf", &matrix1[i][j]);
			}
		}
		printf("\nМатрица:");
		printMatrix(matrix1, size);
		double** identity = NULL;
		identity = createIdentity(size);
		inverseMatrix(matrix1, identity, size);
		printf("\n\nОбратная матрица:");
		printMatrix(identity, size);
		free(matrix1);
		free(identity);
		break;
	case 2:
		printf("Введите размер матрицы:");
		scanf_s("%d", &size);
		printf("Введите элементы матрицы:");
		double** matrix2 = malloc(size * sizeof(double*)); // Вводим матрицу
		for (int i = 0; i < size; i++)
		{
			matrix2[i] = malloc(size * sizeof(double));
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				printf("\nA[%d][%d] = ", i + 1, j + 1);
				scanf_s("%lf", &matrix2[i][j]);
			}
		}
		printf("Введите свободные члены матрицы:");
		double* freeMembers = malloc(size * sizeof(double));
		for (int i = 0; i < size; i++)
		{
			scanf_s("%lf", &freeMembers[i]);
		}
		printf("\nМатрица:");
		printMatrix(matrix2, size);
		determinantAll(matrix2, size);
		break;
	}
	return 0;
}