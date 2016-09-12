//============================================================================
// Name        : StringReverse.cpp
// Author      : Charles
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>

using namespace std;

void reverse(char * str) {
	size_t size = strlen(str);
	char temp = 0x0;
	for(size_t i = 0; i < size / 2; ++i) {
		temp = str[i];
		str[i] = str[size - 1 - i];
		str[size - 1 - i] = temp;
	}

	return;
}

int main() {

	char inputStr[1024];
	cin >> inputStr;
	cout << "Before: " << inputStr << endl;
	reverse(inputStr);
	cout << "After: " << inputStr << endl;

	return 0;
}
