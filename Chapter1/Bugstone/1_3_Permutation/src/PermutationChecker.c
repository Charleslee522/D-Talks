/*
 * PermutationChecker.c
 *
 *  Created on: 2016. 9. 13.
 *      Author: Ãæ¼®
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPermutation(char* input1, char* input2){
	int permutation[256] = {0, };
	int input1Length = strlen(input1);
	int input2Length = strlen(input2);
	int result = 1;
	int i;

	for(i = 0; i < input1Length; i++){
		int inputChar = (int) input1[i];
		permutation[inputChar]++;
	}

	for(i = 0; i < input2Length; i++){
		int inputChar = (int) input2[i];
		permutation[inputChar]--;
		if(permutation[inputChar] < 0){
			result = 0;
			break;
		}
	}
	return result;
}

int main(){
	char input1[1024];
	char input2[1024];
	printf("First input:");
	fgets(input1, sizeof(input1), stdin);
	input1[strlen(input1) - 1] = '\0';

	printf("Second input:");
	fgets(input2, sizeof(input2), stdin);
	input2[strlen(input2) - 1] = '\0';

	if(isPermutation(input1, input2)){
		printf("Permutation - %s : %s\n", input1, input2);
	}else{
		printf("Not permutation - %s : %s\n", input1, input2);
	}
	return 0;
}
