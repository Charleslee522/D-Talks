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

	// s2를 절반 잘라서, 왼쪽 오른쪽 중 어디가 포함되는지 확인 O(n)
	// 왼쪽 "erbot"이 wat "erbot" tle로 포함됨
	// erbot 왼쪽 문장을 맨 뒤로 붙이고 확인 O(n)

	// waterbottle, lewaterbott
	// s2를 절반 잘라서, 왼쪽 오른쪽 중 어디가 포함되는지 확인 O(n)
	// 오른쪽 "erbott"이 wat "erbott" tle로 포함됨
	// "erbott" 오른쪽 문장을 맨 앞으로 붙이고 확인 O(n)
	if(s1.length() != s2.length()) {
		return false;
	}

	size_t midIdx = s2.length()/2;
	size_t idx = s1.find(s2.substr(0, midIdx));
	stringstream result;
	if(idx != string::npos) {	// s2의 왼쪽 절반이 s1에 있으므로, s1의 왼쪽 남은 부분을 오른쪽으로 붙이면 s2와 같아야 함
		result << s1.substr(idx);
		result << s1.substr(0, idx);

	} else {	// s2의 왼쪽 절반이 substring이 아니므로
		// s2의 오른쪽 절반이 s1의 substring인지 확인
		size_t subSize = s2.length() - midIdx;	// 오른쪽 절반이므로 subSize의 크기가 midIdx와 다름
		size_t rightIdx = s1.find(s2.substr(midIdx));
		if(rightIdx != string::npos) {	// s2의 오른쪽 절반이 s1에 있으므로, s1의 오른쪽 남은 부분을 왼쪽으로 붙이면 s2와 같아야 함
			result << s1.substr(rightIdx + subSize);
			result << s1.substr(0, rightIdx + subSize);
		} else { // 양 쪽 모두 s1의 subString이 아니면
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
