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
			if (!s.empty() && s.top() == '(') { //짝이 맞으면 pop
				s.pop();
			}
			else { //왼괄호 없거나 짝이 맞지 않는 경우
				v.push_back("no");
				return v;
			}
		}
		else if (ch == ']') {
			if (!s.empty() && s.top() == '[') {
				s.pop();
			}
			else { //왼괄호 없거나 짝이 맞지 않는 경우
				v.push_back("no");
				return v;
			}
		}
	}
	if (!s.empty()) { //다 끝났는데 stack이 not empty인 경우
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
		//입력
		getline(cin, str); //공백 포함
		if (str == ".") {
			break;
		}

		//연산
		vector<string> result = judgeStr(str);

		//출력
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << "\n";
		}
	}

	return 0;
}