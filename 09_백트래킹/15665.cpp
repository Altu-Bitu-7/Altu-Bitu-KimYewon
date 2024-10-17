#include <iostream>
#include <vector>
#include <set>

using namespace std;
const int MAX_N_M = 7;
const int MAX_NUM = 10000;

int n, m;
set<int> num_s; //자동으로 사전순 정렬
vector<int> sequence(MAX_N_M, 0);

//수열 출력하는 함수
void printSequence() {
	for (int i = 0; i < m; i++) {
		cout << sequence[i] << " ";
	}
	cout << "\n";
	return;
}

//중복 수열 만드는 함수
void getSequence(int cnt) {

	//기저 조건: M개의 숫자를 모두 뽑은 경우
	if (cnt == m) {
		printSequence();
		return;
	}

	for (set<int>::iterator iter = num_s.begin(); iter != num_s.end(); iter++) { //set 순회는 iter 사용
		sequence[cnt] = *iter;
		getSequence(cnt + 1);
	}
}

int main() {

	int num;
	
	//입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		num_s.insert(num);
	}

	//연산 & 출력
	getSequence(0);

	return 0;
}