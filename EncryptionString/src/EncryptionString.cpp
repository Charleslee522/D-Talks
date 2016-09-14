//============================================================================
// Name        : EncryptionString.cpp
// Author      : Charles
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <map>
using namespace std;

string encryption(const string& str) {

//	map<char, int> resultMap;
//
//	for(string::const_iterator i = str.begin(); i != str.end(); ++i) {
//		char c = *i;
//		resultMap.insert()
//		resultMap[c] = resultMap[c] + 1;
//	}
//
//	stringstream result;
//
//	for(map<char, int>::iterator i = resultMap.begin(); i != resultMap.end(); ++i) {
//		char c = i->first;
//		int n = i->second;
//
//		result << c << n;
//	}
//
//	return result.str();

	stringstream result;

	char prevChar = '\0';
	int count = 1;
	for(string::const_iterator i = str.begin(); i != str.end(); ++i) {
		char c = *i;
		if(c == prevChar) {
			++count;
		} else {
			if(i != str.begin()) {
				result << prevChar << count;
				count = 1;
			}
		}
		prevChar = c;
	}

	result << prevChar << count;

	if(str.length() > result.str().length()) {
		return result.str();
	} else {
		return str;
	}
}

int main() {

	string inputStr;

	std::getline(std::cin, inputStr);

	string result = encryption(inputStr);

	cout << inputStr << "->" << result << endl;

	return 0;
}
