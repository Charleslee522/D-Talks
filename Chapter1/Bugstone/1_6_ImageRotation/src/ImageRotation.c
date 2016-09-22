/*
 * ImageRotation.c
 *
 *  Created on: 2016. 9. 20.
 *      Author: 충석
 */

#include <stdio.h>
#define SIZE_N 10

void rotate(int (*imageMatrix)[SIZE_N]){
	int temp;
	int row;
	int col;

	for(row = 0; row < SIZE_N - 1; row++){
		for(col = row; col < SIZE_N - 1 - row; col++){
			temp = imageMatrix[row][col];
			imageMatrix[row][col] = imageMatrix[SIZE_N - 1 - col][row];
			imageMatrix[SIZE_N - 1 - col][row] = imageMatrix[SIZE_N - 1 - row][SIZE_N - 1 - col];
			imageMatrix[SIZE_N - 1 - row][SIZE_N - 1 - col] = imageMatrix[col][SIZE_N - 1 - row];
			imageMatrix[col][SIZE_N - 1 - row] = temp;
		}
	}
}

int main(){
	int imageMatrix[SIZE_N][SIZE_N];
	int count = 0;
	int i = 0;
	int j = 0;

	for(i = 0; i < SIZE_N; i++){
		for(j = 0; j < SIZE_N; j++){
			imageMatrix[i][j] = count++;
		}
	}

	// 입력값 출력
	printf("Input: \n");
	for(i = 0; i < SIZE_N; i++){
		for(j = 0; j < SIZE_N; j++){
			printf("%d ", imageMatrix[i][j]);
		}
		printf("\n");
	}

	rotate(imageMatrix);

	printf("\nRotate Result: \n");
	for(i = 0; i < SIZE_N; i++){
		for(j = 0; j < SIZE_N; j++){
			printf("%d ", imageMatrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
