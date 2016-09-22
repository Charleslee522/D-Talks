/*
 * StringCompress.c
 *
 *  Created on: 2016. 9. 17.
 *      Author: Ãæ¼®
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int position(int input){
	int count = 0;

	do{
		input = (input / 10);
		count++;
	}while(input > 0);

	return count;
}


void writeCount(char* result, int *cursor, int count){
	char* copyTarget;
	int copyLength;
	int j;

	copyTarget = (char*) malloc(position(count));
	sprintf(copyTarget, "%d", count);
	copyLength = strlen(copyTarget);

	for(j = 0; j < copyLength; j++){
		result[(*cursor)++] = copyTarget[j];
	}

	free(copyTarget);
}

char* compress(char* input){
	int length = strlen(input);
	char* result;
	int i;
	int cursor = 0;
	int count = 1;
	char temp;

	result = (char *) malloc (length * 2) + 1;

	temp = input[0];

	for(i = 1; i < length; i++){
		if(temp != input[i]){
			result[cursor++] = temp;
			writeCount(result, &cursor, count);
			temp = input[i];
			count = 1;

		}else{
			count++;
		}

		if(i == (length - 1)){
			result[cursor++] = temp;
			writeCount(result, &cursor, count);
		}
	}

	result[cursor] = '\0';
	if(strlen(result) != 0 && length > strlen(result)){
		return result;
	}else{
		return input;
	}
}



int main(){
	char input[1024];
	char* result;

	fgets(input, sizeof(input), stdin);
	input[strlen(input) - 1] = '\0';

	result = compress(input);
	printf("Compress : %s\n", result);

	free(result);
	return 0;
}
