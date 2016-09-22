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
 * �Է� ���ڿ��� ���ڵ��� ����ũ�� �������� Ȯ���ϴ� �Լ�
 */
int isUnique(char* input){
	char checker[256] = {0, };	//���ڰ� �Է����� ���Ծ������� üũ�ϴ� ����
	int i = 0;
	int inputLength = strlen(input);
	int result = 1;

	// ASCII ���ڷ� ������ ���ڿ��� 256�� �̻��̸� ������ �ߺ����� �Ǵ�
	if(inputLength > 256){
		return 0;
	}

	for(i = 0; i < inputLength; i++){
		int charater = (int) input[i];
		if(checker[charater] == 1){		//���ڰ� �ѹ��̶� �������� ������ �ߺ����� ���� ���ڷ� �Ǵ�
			printf("\'%c\' is duplicate.\n", input[i]);
			result = 0;		//����� ���з� ����
			break;
		}else{
			checker[charater] = 1;	// �Էµ� ���ڸ� üũ
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
