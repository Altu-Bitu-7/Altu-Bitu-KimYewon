#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

const int MAX = 1000000;

//에라토스테네스의 체
void getPrime(vector<bool>& is_prime) {

	is_prime[0] = is_prime[1] = false; //0과 1은 소수x

	for (int i = 2; i * i <= MAX; i++) {
		if (is_prime[i]) { //i가 소수라면
			for (int j = i * i; j <= MAX; j += i) {
				is_prime[j] = false; //i의 배수 제거
			}
		}
	}

	/* 처음에 시도한, 소수를 따로 저장하고 양 끝부터 더해보는 방식 -> 시간 복잡도가 너무 커져서 시간 초과가 남
	vector<int> v;
	for (int i = 2; i < MAX; i++) {
		if (is_prime[i] == true) {
			v.push_back(i); //소수를 저장하는 벡터
		}
	}

	return v;
	*/

}

//합이 n이 되는 두 홀수 소수 찾는 함수
tuple<int, int, int> goldbach(int n, vector<bool>& is_prime) {
	
	/* 처음에 시도한, 소수를 따로 저장하고 양 끝부터 더해보는(b-a가 가장 큰 걸 찾아야 하므로) 방식 -> 시간 복잡도가 너무 커져서 시간 초과가 남
	int begin_idx = 0;
	int end_idx = prime.size() - 1;

	while (begin_idx <= end_idx) {
		int sum = prime[begin_idx] + prime[end_idx];

		if (sum == n) {
			return make_tuple(n, prime[begin_idx], prime[end_idx]);
		}
		else {
			begin_idx++;
			end_idx--;
		}
	}
	*/

	for (int i = 0; i <= n / 2; i++) { //n/2까지만 확인하면 됨(반 나눠서 짝을 이루기 때문. ex. 8 = 3 + 5 = 5 + 3
		if (is_prime[i]) { //i가 소수이면
			if (is_prime[n - i]) { //n-i도 소수이면(합이 n이 되는 다른 수도 소수인지 확인)
				return make_tuple(n, i, n - i);
			}
		}
	}

	return make_tuple(0, 0, 0); //두 홀수 소수를 찾기 못할 경우 tuple<0, 0, 0>을 반환
}

int main() {

	//입출력 속도 향상
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<tuple<int, int, int>> result; //결과값 저장할 tuple<주어진 입력 정수 n, 홀수 소수 a, 홀수 소수 b>

	//입력 & 연산
	vector<bool> is_prime(MAX + 1, true);
	getPrime(is_prime); //1 ~ MAX의 수의 소수 판별

	while (true) {
		cin >> n;
		if (n == 0) {
			break; // 0 입력 시 종료
		}

		tuple<int, int, int> value = goldbach(n, is_prime);

		result.push_back(value); //결과값 n, a, b의 tuple을 벡터에 저장
	}

	//출력
	for (int i = 0; i < result.size(); i++) {
		if (get<0>(result[i]) == 0) { //tuple의 첫번째 값이 0일 경우 해당하는 두 홀수 소수를 찾기 못한 것.
			cout << "Goldbach's conjecture is wrong.\n";
		}
		cout << get<0>(result[i]) << " = " << get<1>(result[i]) << " + " << get<2>(result[i]) << "\n";
	}

	return 0;
}