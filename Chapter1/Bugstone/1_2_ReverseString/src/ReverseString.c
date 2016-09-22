/*
 * bugstone_1_2.c
 *
 *  Created on: 2016. 9. 12.
 *      Author: bugstone
 *
 */

#include <stdio.h>
#include <string.h>

void reverse(char* input){
	int inputLength = strlen(input);
	int halfLength = inputLength / 2;
	int endIndex = inputLength - 1;

	char temp;
	int i;
	for(i = 0; i < halfLength; i++){
		temp = input[endIndex - i];
		input[endIndex - i] = input[i];
		input[i] = temp;
	}
}

int main(){
	char input[1024];

	fgets(input, sizeof(input), stdin);
	input[strlen(input) - 1] = '\0';

	printf("Your input: %s\n", input);
	reverse(input);
	printf("Reverse: %s\n", input);
	return 0;
}
