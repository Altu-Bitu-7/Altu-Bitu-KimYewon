#include <iostream>
#include <string>

using namespace std;

int getNumOfApo(int n) {

	int cnt = 0;
	for (int i = 0; i < 10000000; i++) { //n <= 10,000이라는 조건이 있으므로 브루트포스 가능
		if (to_string(i).find("666") != string::npos) { //i에 666이 포함되어 있으면 카운트
			cnt++;
		}
		if (cnt == n) { //n번째 수에 도달하면
			return i;
		}
	}

	return 0;
}

int main() {

	int n;

	//입력
	cin >> n;

	//연산 & 출력
	cout << getNumOfApo(n);

	return 0;
}