/*
 * IsSubString.c
 *
 *  Created on: 2016. 9. 22.
 *      Author: Ãæ¼®
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSubString(char* input1, char* input2){
	int length = strlen(input1);
	int length2 = strlen(input2);
	char checkInput[length * 2];
	char *cutString;
	int i, j;
	int result = 0;

	for(i = 0; i < length * 2; i++){
		checkInput[i] = input1[i % length];
	}

	for(i = 0; i + length2 < length * 2; i++){
		cutString = &checkInput[i];
		result = 1;
		for(j = 0; j < length2; j++){
			if(cutString[j] != input2[j]){
				result = 0;
				break;
			}
		}

		if(result == 1){
			break;
		}
	}
	return result;
}

int main(){
	char input1[1024];
	char input2[1024];

	fgets(input1, sizeof(input1), stdin);
	input1[strlen(input1) - 1] = '\0';

	fgets(input2, sizeof(input2), stdin);
	input2[strlen(input2) - 1] = '\0';

	if(isSubString(input1, input2)){
		printf("true");
	}else{
		printf("False");
	}
	return 0;
}
