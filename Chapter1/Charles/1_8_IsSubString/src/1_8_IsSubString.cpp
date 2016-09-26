//============================================================================
// Name        : 1_8_IsSubString.cpp
// Author      : Charles
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool isSubString(string s1, string s2) {

	// waterbottle, erbottlewat

	// s2�� ���� �߶�, ���� ������ �� ��� ���ԵǴ��� Ȯ�� O(n)
	// ���� "erbot"�� wat "erbot" tle�� ���Ե�
	// erbot ���� ������ �� �ڷ� ���̰� Ȯ�� O(n)

	// waterbottle, lewaterbott
	// s2�� ���� �߶�, ���� ������ �� ��� ���ԵǴ��� Ȯ�� O(n)
	// ������ "erbott"�� wat "erbott" tle�� ���Ե�
	// "erbott" ������ ������ �� ������ ���̰� Ȯ�� O(n)
	if(s1.length() != s2.length()) {
		return false;
	}

	size_t midIdx = s2.length()/2;
	size_t idx = s1.find(s2.substr(0, midIdx));
	stringstream result;
	if(idx != string::npos) {	// s2�� ���� ������ s1�� �����Ƿ�, s1�� ���� ���� �κ��� ���������� ���̸� s2�� ���ƾ� ��
		result << s1.substr(idx);
		result << s1.substr(0, idx);

	} else {	// s2�� ���� ������ substring�� �ƴϹǷ�
		// s2�� ������ ������ s1�� substring���� Ȯ��
		size_t subSize = s2.length() - midIdx;	// ������ �����̹Ƿ� subSize�� ũ�Ⱑ midIdx�� �ٸ�
		size_t rightIdx = s1.find(s2.substr(midIdx));
		if(rightIdx != string::npos) {	// s2�� ������ ������ s1�� �����Ƿ�, s1�� ������ ���� �κ��� �������� ���̸� s2�� ���ƾ� ��
			result << s1.substr(rightIdx + subSize);
			result << s1.substr(0, rightIdx + subSize);
		} else { // �� �� ��� s1�� subString�� �ƴϸ�
			return false;
		}
	}

	return s2 == result.str();
}

int main() {
	string inputString1;
	string inputString2;

	cout << "Input s1: ";
	cin >> inputString1;
	//inputString1 = "waterbottle";
	//inputString1 = "charlesleee";

	cout << "Input s2: ";
	cin >> inputString2;
	//inputString2 = "erbottlewat";
	//inputString2 = "lewaterbtot";
	//inputString2 = "leeecharles";


	cout << "Is the \"" << inputString2 << "\" substring of the" <<
			" \"" << inputString1 << "\"?" << endl;

	if(isSubString(inputString1, inputString2)) {
		cout << "Yes!" << endl;
	} else {
		cout << "No!" << endl;
	}

	return 0;
}
