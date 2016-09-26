//============================================================================
// Name        : 1_6_ImageRotation.cpp
// Author      : Charles
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define N 8

template <size_t n>
void printImage(unsigned int imageArray[n][n])
{
	for(unsigned int i = 0U; i < n; ++i) {
		for(unsigned int j = 0U; j < n; ++j) {
			cout << imageArray[i][j] << '\t';
		}
		cout << '\n';
	}
}

template <size_t n>
void rotateImage(unsigned int (&imageArray)[n][n])
{
	//	(0,0)	(0,1)	(0,2)	(0,3)
	//	(1,0)	(1,1)	(1,2)	(1,3)
	//	(2,0)	(2,1)	(2,2)	(2,3)
	//	(3,0)	(3,1)	(3,2)	(3,3)

	//	(3,0)	(2,0)	(1,0)	(0,0)
	//	(3,1)	(2,1)	(1,1)	(0,1)
	//	(3,2)	(2,2)	(1,2)	(0,2)
	//	(3,3)	(2,3)	(1,3)	(0,3)

	// ���� �ܰ� ���� 0,0���� �� ���� ������ ���� ����.
		//1. 0,0 �� �ӽú����� ����
		//2. 3,0�� 0,0 �ڸ���
		//3. 3,3�� 3,0 �ڸ���
		//4. 0,3�� 3,3 �ڸ���
		//5. �ӽú����� 0,3 �ڸ���
	// ���� 0,1 -> 0,2 �ϸ� �ܰ� ���� �Ϸ�.
	size_t temp = 0U;

	for(size_t i = 0; i < n - 1; ++i) {
		for(size_t j = i; j < n - 1 -i; ++j) {
			temp = imageArray[i][j];
			imageArray[i][j] = imageArray[n-1-j][i];
			imageArray[n-1-j][i] = imageArray[n-1-i][n-1-j];
			imageArray[n-1-i][n-1-j] = imageArray[j][n-1-i];
			imageArray[j][n-1-i] = temp;
		}
		cout << "debugging: " << i << endl;
		printImage<n>(imageArray);
	}
	return ;
}

int main() {

	unsigned int imageArray[N][N] = {0U, };

	unsigned int count = 0U;
	for(unsigned int i = 0U; i < N; ++i) {
		for(unsigned int j = 0U; j < N; ++j) {
			imageArray[i][j] = count;
			++count;
		}
	}

	cout << "Original Array" << endl;
	printImage<N>(imageArray);

	rotateImage<N>(imageArray);

	// print
	cout << "Rotated Image" << endl;
	printImage<N>(imageArray);


	return 0;
}
