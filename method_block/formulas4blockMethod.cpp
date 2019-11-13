#include "formulas4blockMethod.h"
#include <iostream>

//нахождение обратной матрицы 2x2
vector_float reverse(vector_float A) {

	// запоминаем первый элемент
	float first_el = A[0][0]; 
	// находим определитель
	float det = A[0][0] * A[1][1] - A[1][0] * A[0][1]; 

	A[0][0] = A[1][1]; A[0][1] = -A[0][1]; // меняем значения
	A[1][0] = -A[1][0]; A[1][1] = first_el; // элементов
	// находим элементы для обратной матрицы
	for (unsigned i = 0; i < 2; i++) {
		for (unsigned j = 0; j < 2; j++) {
			A[i][j] *= (1 / det);
		}
	}
	return A;
}

// Функция нахождения X и V
vector_float formula_XV(vector_float M, vector_float N, vector_float Q1, vector_float P) {
	
	vector_float C;
	C = memoVector(C, N.size(), N[0].size());
	C = mul(C, N, Q1);
	C = mul(C, C, P);

	for (unsigned i = 0; i < N.size(); i++)
		for (unsigned j = 0; j < N[i].size(); j++)
			C[i][j] = M[i][j] - C[i][j];

	C = reverse(C);

	return C;
}

// Умножение матрицы 2x2
vector_float mul(vector_float C, vector_float N, vector_float Q1) {
	float S;
	for (unsigned i = 0; i < N.size(); i++)
		for (unsigned j = 0; j < N[i].size(); j++) {
			S = 0;
			for (unsigned k = 0; k < N[i].size(); k++)
				S += N[i][k] * Q1[k][j];
			C[i][j] = S;
		}
	return C;
}

vector_float formula_UY(vector_float V, vector_float P, vector_float M1) {

	vector_float C;
	C = memoVector(C, V.size(), V[0].size());
	C = mul(C, V, P);
	C = mul(C, C, M1);

	for (unsigned i = 0; i < C.size(); i++)
		for (unsigned j = 0; j < C[i].size(); j++)
			C[i][j] *= -1;

	return C;
}

vector_float memoVector(vector_float A, unsigned n, unsigned m) {
	A.resize(n);
	for (unsigned i = 0; i < A.size(); i++) {
		A[i].resize(m);
	}
	return A;
}

// Вывод на экран
void printVector(vector_float A) {
	for (unsigned i = 0; i < A.size(); i++) {
		for (unsigned j = 0; j < A[i].size(); j++)
			std::cout << A[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}