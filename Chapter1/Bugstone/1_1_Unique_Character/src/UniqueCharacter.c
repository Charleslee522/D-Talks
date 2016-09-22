/*
 * bugstone_1_1.c
 *
 *  Created on: 2016. 9. 12.
 *      Author: bugstone
 *
 */

#include <stdio.h>
#include <string.h>

/*
 * 입력 문자열의 문자들이 유니크한 문자인지 확인하는 함수
 */
int isUnique(char* input){
	char checker[256] = {0, };	//문자가 입력으로 들어왔었는지를 체크하는 변수
	int i = 0;
	int inputLength = strlen(input);
	int result = 1;

	// ASCII 문자로 구성된 문자열이 256자 이상이면 무조건 중복으로 판단
	if(inputLength > 256){
		return 0;
	}

	for(i = 0; i < inputLength; i++){
		int charater = (int) input[i];
		if(checker[charater] == 1){		//문자가 한번이라도 나온적이 있으면 중복으로 들어온 문자로 판단
			printf("\'%c\' is duplicate.\n", input[i]);
			result = 0;		//결과를 실패로 저장
			break;
		}else{
			checker[charater] = 1;	// 입력된 문자를 체크
		}
	}
	return result;
}

int main(){
	char input[1024];

	fgets(input, sizeof(input), stdin);
	input[strlen(input) - 1] = '\0';

	if(isUnique(input)){
		printf("Unique charater!! - %s\n", input);
	}else{
		printf("Duplicate charater!! - %s\n", input);
	}
	return 0;
}
