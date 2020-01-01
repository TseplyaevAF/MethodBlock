#include <iostream>
#include "formulas4blockMethod.h"

using namespace std;

int main()
{
	vector_float A = {{1, 1, 1, -1},
					{0, 1, 1, -1},
					{1, 1, 0, -3},
					{-1, -1, -1, 0}};

	vector_float M = {{1, 1},
					{0, 1}};

	vector_float N = {{1, -1},
					{1, -1}};

	vector_float P = {{1, 1},
					{-1, -1}};

	vector_float Q = {{0, -3}, 
					{-1, 0}};  

	vector_float Q1; // Обратная матрица к Q
	vector_float M1; // Обратная матрица к M

	Q1 = reverse(Q); // Q^-1
	M1 = reverse(M); // M^-1

	// получение матрицы X по формуле X = (M - NQ^-1*P)^-1
	vector_float X = formula_XV(M, N, Q1, P);

	// получение матрицы V по формуле V = (Q - PM^-1*N)^-1
	vector_float V = formula_XV(Q, P, M1, N);

	// получение матрицы U по формуле U = -VPM^-1
	vector_float U = formula_UY(V, P, M1);

	// получение матрицы Y по формуле Y = -XNQ^-1
	vector_float Y = formula_UY(X, N, Q1);

	printVector(X);
	printVector(Y);
	printVector(U);
	printVector(V);

	return 0;
}
