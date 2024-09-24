#include <iostream>
#include <string>

using namespace std;

int calculate(int& s, string operation) {

	int x = 0;
	int pos = operation.find(" "); //공백 기준으로 분할할 것임
	string oper = operation.substr(0, pos); // 연산 종류

	if (pos != string::npos) { // 공백이 있으면 숫자 추출(*공백을 찾지 못하면 npos 반환)
		x = stoi(operation.substr(pos + 1)); // 공백 이후의 숫자, string -> int, x값
	}

	int x_bit = 1 << x; //x를 비트마스크로 표현

	if (oper == "add") {
		s |= x_bit; //x 추가, or 연산(합집합)
	}
	else if (oper == "remove") {
		s &= ~x_bit; //x 제거, 차집합
	}
	else if (oper == "check") {
		if ((s & x_bit) == x_bit) { //s과 x의 and 연산(교집합)이 x라면(== s에 x가 있다면) 1 반환
			return 1;
		}
		else { //x가 없다면 0 반환
			return 0;
		}
	}
	else if (oper == "toggle") {
		if ((s & x_bit) == x_bit) { //s과 x의 and 연산(교집합)이 x라면(== s에 x가 있다면)
			s &= ~x_bit; //x 제거
		}
		else { //x가 없다면
			s |= x_bit; //x 추가
		}
	}
	else if (oper == "all") {
		s = 0; //전부 제거 후
		for (int i = 1; i <= 20; i++) { //1부터 20까지 추가
			int tmp_bit = 1 << i;
			s |= tmp_bit; //합집합
		}
	}
	else if (oper == "empty") {
		s = 0; //전부 제거(== s를 공집합으로)
	}

	return 2; //check가 아니면 2 반환
}

int main() {

	//입출력 속도 향상
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	string operation;
	int s = 0;
	int check_result;

	//입력 & 연산
	cin >> m;
	cin.ignore(); //개행 문자 제거

	for (int i = 0; i < m; i++) {
		getline(cin, operation); //공백 포함 입력
		check_result = calculate(s, operation);

		//출력
		if (check_result == 0 || check_result == 1) { //check_result가 0 또는 1이면(== check 연산이면)
			cout << check_result << "\n";
		}
	}

	return 0;
}