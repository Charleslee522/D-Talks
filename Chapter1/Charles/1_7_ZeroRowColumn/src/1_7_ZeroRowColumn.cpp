//============================================================================
// Name        : 1_7_ZeroRowColumn.cpp
// Author      : Charles
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define M 4
#define N 3


template <size_t m, size_t n>
void printArray(unsigned int imageArray[m][n])
{
	for(unsigned int i = 0U; i < m; ++i) {
		for(unsigned int j = 0U; j < n; ++j) {
			cout << imageArray[i][j] << '\t';
		}
		cout << '\n';
	}
}


template <size_t m, size_t n>
void toZeroRowColumn(unsigned int imageArray[m][n])
{
	bool rowArray[m] = {false, };
	bool columnArray[n] = {false, };
	for(unsigned int i = 0U; i < m; ++i) {
		for(unsigned int j = 0U; j < n; ++j) {
			if(imageArray[i][j] == 0) {
				rowArray[i] = columnArray[j] = true;
			}
		}
	}

	for(unsigned int i = 0U; i < m; ++i) {
		for(unsigned int j = 0U; j < n; ++j) {
			if((rowArray[i] == true) || (columnArray[j] == true)) {
				imageArray[i][j] = 0;
			}
		}
	}

}

int main() {

	srand((unsigned int) time(NULL));
//	unsigned int mnArray[M][N] = {0U, };
	unsigned int mnArray[4][3] = { {0, 0, 5}, {10, 1, 3}, {0, 0, 5}, {8, 4, 9}};

//	for(unsigned int i = 0U; i < M; ++i) {
//		for(unsigned int j = 0U; j < N; ++j) {
//			mnArray[i][j] = rand() % (M * N);
//		}
//	}

	cout << "Original Array!" << endl;
	printArray<M, N>(mnArray);

	toZeroRowColumn<M, N>(mnArray);

	cout << "Changed Array!" << endl;
	printArray<M, N>(mnArray);
	return 0;
}
