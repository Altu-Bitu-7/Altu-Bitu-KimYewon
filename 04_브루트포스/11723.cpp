#include <iostream>
#include <string>

using namespace std;

int calculate(vector<int> s, string operation) {

	int x = stoi(operation.substr(operation.find(" "))); //���� �������� ����, string -> int, x��
	int pos = operation.find(" ");
	string oper = operation.substr(0, pos); //���� ����

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

	//�Է� & ����
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> operation;
		calculate(s, operation)
	}

	//���

	return 0;
}