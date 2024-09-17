#include <iostream>
#include <map>

using namespace std;

void findStr(string str, map<string, int>& s, int& cnt) {

	auto iter = s.find(str); //키 값(str) 존재하는지 순회하면서 확인
	if (iter != s.end()) { //**존재하지 않으면 s.end() 반환
		cnt++; //키 값 존재하면 cnt 증가
	}
}

int main() {

	//입력 & 연산
	int n, m;
	string str;
	map<string, int> s;
	int val = 0;
	int cnt = 0;

	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) { //map으로 n개의 문자열 집합 저장
		cin >> str;
		s[str] = val;
	}
	for (int i = 0; i < m; i++) {
		cin >> str;
		findStr(str, s, cnt);
	}

	//출력
	cout << cnt;

	return 0;
}