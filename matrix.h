#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * @brief ��������� �������� �������.
 * @param matrix_ �������
 * @param identity_ ��������� � matrix_
 * @param size_ ������ �������
 * @return �������� �������.
*/
int inverseMatrix(double** matrix_, double** identity_, int size_);

/**
 * @brief ������ ��������� �������.
 * @param size_ ������ �������
 * @return ��������� ������� � �������� size_
*/
double** createIdentity(int size_);

/**
 * @brief ������� ������� � �������.
 * @param matrix_ �������
 * @param size_ ������ �������
*/
void printMatrix(double** matrix_, int size_);

/**
 * @brief ������� ������������ ��� ������� size_ �������.
 * @param matrix_ �������
 * @param size ������
 * @return ������������
*/
double determinantAll(double** matrix_, int size_);

/**
 * @brief ������� ������������ ������� �������� 3 �� 3.
 * @param matrix_�������
 * @param size
 * @return ������������
*/
double determinant(double** matrix_);