#include <iostream>
#include <string>

using namespace std;

int calculate(vector<int> s, string operation) {

	int x = stoi(operation.substr(operation.find(" "))); //공백 기준으로 분할, string -> int, x값
	int pos = operation.find(" ");
	string oper = operation.substr(0, pos); //연산 종류

	if (oper == "add") {

	}
	else if (oper == "remove") {

	}
	else if (oper == "check") {

	}
	else if (oper == "toggle") {

	}
	else if (oper == "all") {

	}
	else if (oper == "empty") {

	}

	return 0;
}

int main() {

	int m;
	string operation;
	vector<int> s;

	//입력 & 연산
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> operation;
		calculate(s, operation)
	}

	//출력

	return 0;
}