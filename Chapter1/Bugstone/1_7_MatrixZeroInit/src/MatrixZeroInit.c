/*
 * MatrixZeroInit.c
 *
 *  Created on: 2016. 9. 22.
 *      Author: 충석
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE_N 5
#define SIZE_M 4

void matrixZeroInit(int (*matrix)[SIZE_M]){
	int row;
	int col;
	int initX[SIZE_N] = {0,};
	int initY[SIZE_M] = {0,};

	for(row = 0; row < SIZE_N; row++){
		for(col = 0; col < SIZE_M; col++){
			if(matrix[row][col] == 0){
				initX[row] = 1;
				initY[col] = 1;
			}
		}
	}

	for(row = 0; row < SIZE_N; row++){
		for(col = 0; col < SIZE_M; col++){
			if(initX[row] == 1 || initY[col] == 1){
				matrix[row][col] = 0;
			}
		}
	}
}

int main() {
	int matrix[SIZE_N][SIZE_M];
	int i = 0;
	int j = 0;
	long seed;

	seed = time(NULL);
	srand(seed);

	for (i = 0; i < SIZE_N; i++) {
		for (j = 0; j < SIZE_M; j++) {

			matrix[i][j] = (rand() % 2);
		}
	}

	// 입력값 출력
	printf("Input: \n");
	for (i = 0; i < SIZE_N; i++) {
		for (j = 0; j < SIZE_M; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	matrixZeroInit(matrix);

	printf("\nZero Init Result: \n");
	for (i = 0; i < SIZE_N; i++) {
		for (j = 0; j < SIZE_M; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
