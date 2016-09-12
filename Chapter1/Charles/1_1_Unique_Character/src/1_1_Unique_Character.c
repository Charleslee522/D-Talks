/*
 ============================================================================
 Name        : 1_1_Unique_Character.c
 Author      : Charles
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isAllUnique(char * str)
{
	unsigned char alphabetArray[256] = {0, };
	size_t size = strlen(str);
	for(size_t i = 0; i < size; ++i) {
		printf("%c\n", str[i]);
		if(alphabetArray[(int)str[i]] == 1U) {
			return 0;
		}
		alphabetArray[(int)str[i]] = 1U;
	}
	return 1;
}

int main(void) {

	char inputStr[1024] = "";
	gets(inputStr);

	if(isAllUnique(inputStr)) {
		puts("Success!!\n");
	}
	else {
		puts("Fail!!\n");
	}
	return EXIT_SUCCESS;
}
