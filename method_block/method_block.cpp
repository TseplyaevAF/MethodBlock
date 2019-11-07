#include <iostream>
#include <vector>

using namespace std;

using vector_float = vector<vector<float>>;

//нахождение обратной матрицы 2x2
vector_float reverse(vector<vector<float>> A) {

	float buf = A[0][0];
	//определитель
	float det = A[0][0] * A[1][1] - A[1][0] * A[0][1];

	A[0][0] = A[1][1]; A[0][1] = -A[0][1];
	A[1][0] = -A[1][0]; A[1][1] = buf;
	for (unsigned i = 0; i < 2; i++) {
		for (unsigned j = 0; j < 2; j++) {
			A[i][j] *= (1 / det);
	}
	}
	return A;
}

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

	Q1 = reverse(Q);
	M1 = reverse(M);



	return 0;
}
