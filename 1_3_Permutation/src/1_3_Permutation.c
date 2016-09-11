/*
 ============================================================================
 Name        : 1_3_Permutation.c
 Author      : Charles
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 256

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


unsigned int isValid(char * str)
{
	if( ! isAllUnique(str) ) {
		puts("[FAIL]Input strings are not unique!!!");
		return 0;
	}
	return 1;
}

unsigned int setAlphabetArray(char * str, unsigned char * alphabetArray)
{
	size_t size = strlen(str);
	for(size_t i = 0; i < size; ++i) {
		alphabetArray[(int)str[i]] = 1U;
	}
	return 1;
}

unsigned int isPermutationOf(unsigned char * alphabetArray, unsigned char * alphabetArray2)
{
	size_t size = ALPHABET_SIZE;
	for(size_t i = 0; i < size; ++i) {
		if( (alphabetArray2[i] == 1U) && (alphabetArray[i] == 0U) ) {
			return 0;
		}
	}
	return 1;
}

unsigned int checkPermutation(char * str, char * str2)
{
	unsigned char alphabetArray[ALPHABET_SIZE] = {0, };
	unsigned char alphabetArray2[ALPHABET_SIZE] = {0, };
	setAlphabetArray(str, alphabetArray);
	setAlphabetArray(str2, alphabetArray2);

	if(strlen(str) > strlen(str2)) {
		return isPermutationOf(alphabetArray, alphabetArray2);
	} else {
		return isPermutationOf(alphabetArray2, alphabetArray);
	}

	return 1;

}

int main(void) {

	char inputStr[1024] = "";
	char inputStr2[1024] = "";
	gets(inputStr);
	gets(inputStr2);

	if( ! isValid(inputStr) || ! isValid(inputStr2) ) {
		puts("[FAIL]");
		return EXIT_FAILURE;
	}

	if(checkPermutation(inputStr, inputStr2)) {
		puts("Success!!\n");
	}
	else {
		puts("Fail!!\n");
	}

	return EXIT_SUCCESS;
}
