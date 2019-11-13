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

	Q1 = reverse(Q); // шаг первый
	M1 = reverse(M); // шаг второй

	// шаг третий
	// получение матрицы X по формуле X = (M - NQ^-1*P)^-1
	vector_float X = formula_XV(M, N, Q1, P);

	return 0;
}
