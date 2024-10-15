#include <iostream>
#include <vector>

using namespace std;
const int PLUS = 1;
const int MINUS = 2;
const int MULTIPLE = 3;
const int DIVISION = 4;
const int MAX_N = 11;
const int MAX_OPER = 5;

int n;
int a[MAX_N];
int oper[MAX_OPER]; //1번 인덱스 = 덧셈, 2번 인덱스 = 뺄셈, 3번 인덱스 = 곱셈, 4번 인덱스 = 나눗셈

int max_num = -1000000000; //최대 10억, 최소 -10억
int min_num = 1000000000;

//수식을 계산하는 함수
int calculate(int oper, int result, int cnt) {

	if (oper == PLUS) {
		result += a[cnt + 1];
	}
	else if (oper == MINUS) {
		result -= a[cnt + 1];
	}
	else if (oper == MULTIPLE) {
		result *= a[cnt + 1];
	}
	else { //나눗셈
		result /= a[cnt + 1];
	}

	return result;
}

//최댓값, 최소값을 갱신하는 함수
void updateAns(int new_result) {
	max_num = max(max_num, new_result);
	min_num = min(min_num, new_result);
}

//수식을 만드는 함수
void makeExpression(int result, int cnt) {

	//기저 조건: n-1개의 연산자를 모두 사용한 경우 
	if (cnt == n - 1) {
		updateAns(result);
		return;
	}

	for (int i = 1; i <= 4; i++) {
		if (oper[i] > 0) { //해당 연산자 사용횟수가 남은 경우에만
			oper[i]--; //연산자 사용 체크
			int new_result = calculate(i, result, cnt);

			makeExpression(new_result, cnt + 1);

			//돌려놓기
			oper[i]++;
		}
	}
}

int main() {

	//입력
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i]; //수열 a
	}

	oper[0] = 0;
	for (int i = 1; i < MAX_OPER; i++) {
		cin >> oper[i]; //연산자 저장
	}

	//연산
	makeExpression(a[0], 0); //result 초기값: 첫 번째 숫자

	//출력
	cout << max_num << "\n" << min_num;

	return 0;
}