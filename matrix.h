#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * @brief вычисляет обратную матрицу.
 * @param matrix_ матрица
 * @param identity_ единичная к matrix_
 * @param size_ размер матрицы
 * @return обратную матрицу.
*/
int inverseMatrix(double** matrix_, double** identity_, int size_);

/**
 * @brief создаёт единичную матрицу.
 * @param size_ размер матрицы
 * @return единичную матрицу с размером size_
*/
double** createIdentity(int size_);

/**
 * @brief Выводит матрицу в консоль.
 * @param matrix_ матрица
 * @param size_ размер матрицы
*/
void printMatrix(double** matrix_, int size_);

/**
 * @brief находит определитель для матрицы size_ размера.
 * @param matrix_ матрица
 * @param size размер
 * @return определитель
*/
double determinantAll(double** matrix_, int size_);

/**
 * @brief находит определитель матрицы размером 3 на 3.
 * @param matrix_матрица
 * @param size
 * @return определитель
*/
double determinant(double** matrix_);