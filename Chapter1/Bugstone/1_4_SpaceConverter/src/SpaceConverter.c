/*
 * SpaceConverter.c
 *
 *  Created on: 2016. 9. 13.
 *      Author: Ãæ¼®
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convertSpace(char* input, int length){
	int inputLength = strlen(input);
	int resultIndex = 0;
	int i;
	char* result;
	result = (char*) malloc(length);

	for(i = 0; i < inputLength; i++){
		if(i < length){
			if(input[i] == ' '){
				result[resultIndex++] = '%';
				result[resultIndex++] = '2';
				result[resultIndex++] = '0';
			}else{
				result[resultIndex++] = input[i];
			}
		}else{
			printf("[WARNING] Buffer overflow!! - size: %d\n", length);
			break;
		}
	}
	result[resultIndex] = '\0';

	return result;
}

int main(){
	char input[1024];
	int length;
	char *result;

	fgets(input, sizeof(input), stdin);
	input[strlen(input) - 1] = '\0';
	scanf("%d", &length);

	result = convertSpace(input, length);
	printf("Space to '%%20' : %s\n", result);

	free(result);
	return 0;
}
