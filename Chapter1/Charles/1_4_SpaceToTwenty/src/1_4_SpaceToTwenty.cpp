//============================================================================
// Name        : 1_4_SpaceToTwenty.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
using namespace std;

string spaceToTwenty(const string& str, int size)
{
	string::const_iterator i = str.begin();
	stringstream stream;
	for(;i != str.end(); ++i) {
		char character = *i;
		if(character == ' ') {
			stream << "%20";
		} else {
			stream << character;
		}
	}
	return stream.str();
}

int main() {
	string inputStr;
	std::getline(std::cin, inputStr);
	string result = spaceToTwenty(inputStr, inputStr.length());
	cout << result;
	return 0;
}
