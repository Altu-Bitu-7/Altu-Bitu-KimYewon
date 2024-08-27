#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<string> judgeStr(string str) {

	stack<char> s;
	vector<string> v;

	for (int i = 0; i < str.length(); i++) {
		char ch = str[i];
		if (ch == '(' || ch == '[') {
			s.push(ch);
		}
		else if (ch == ')') {
			if (!s.empty() && s.top() == '(') { //¦�� ������ pop
				s.pop();
			}
			else { //�ް�ȣ ���ų� ¦�� ���� �ʴ� ���
				v.push_back("no");
				return v;
			}
		}
		else if (ch == ']') {
			if (!s.empty() && s.top() == '[') {
				s.pop();
			}
			else { //�ް�ȣ ���ų� ¦�� ���� �ʴ� ���
				v.push_back("no");
				return v;
			}
		}
	}
	if (!s.empty()) { //�� �����µ� stack�� not empty�� ���
		v.push_back("no");
	}
	else {
		v.push_back("yes");
	}

	return v;
}

int main() {

	string str;

	while (true) {
		//�Է�
		getline(cin, str); //���� ����
		if (str == ".") {
			break;
		}

		//����
		vector<string> result = judgeStr(str);

		//���
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << "\n";
		}
	}

	return 0;
}