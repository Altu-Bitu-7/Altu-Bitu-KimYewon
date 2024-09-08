#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//시리얼번호의 모든 자리수 합 구하기
int sum(string sn1) {
	int result = 0;

	for (int i = 0; i < sn1.length(); i++) {
		int num = sn1[i] - '0';//string -> int
		if (num >= 0 && num <= 9) { //숫자이면
			result = result + num;
		}
	}
	return result;
}

bool cmp(string sn1, string sn2) {

	if (sn1.length() != sn2.length()) { //길이가 다르면
		return sn1.length() < sn2.length(); //sn1이 길면 swap
	}
	else {
		int sum1 = sum(sn1);
		int sum2 = sum(sn2);

		if (sum1 != sum2) { //자리수의 합이 다르면
			return sum1 < sum2; // sum1이 크면 swap
		}
		else { //위의 두 조건으로 비교가 불가능하면
			return sn1 < sn2; //사전순
		}
	}
}

int main() {

	//입력
	int n; //기타 개수
	string serial_num_arr[50]; //시리얼넘버

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> serial_num_arr[i];
	}

	//연산
	sort(serial_num_arr, serial_num_arr + n, cmp);

	//출력
	for (int i = 0; i < n; i++) {
		cout << serial_num_arr[i] << '\n';
	}

	return 0;
}