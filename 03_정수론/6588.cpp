#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

const int MAX = 1000000;

vector<int> getPrime(vector<bool>& is_prime) {
	vector<int> v;

	is_prime[0] = is_prime[1] = false; //0�� 1�� �Ҽ�x

	for (int i = 2; i * i <= MAX; i++) {
		if (is_prime[i]) { //i�� �Ҽ����
			for (int j = i * i; j <= MAX; j += i) {
				is_prime[j] = false; //i�� ��� ����
			}
		}
	}

	for (int i = 2; i < MAX; i++) {
		if (is_prime[i] == true) {
			v.push_back(i); //�Ҽ��� �����ϴ� ����
		}
	}

	return v;
}

tuple<int, int, int> goldbach(int n, vector<int>& prime) {
	int begin_idx = 0;
	int end_idx = prime.size() - 1;

	while (begin_idx <= end_idx) {
		int sum = prime[begin_idx] + prime[end_idx];

		if (sum == n) {
			return make_tuple(n, prime[begin_idx], prime[end_idx]);
		}
		else if (sum < n) {
			begin_idx++;
		}
		else {
			end_idx--;
		}
	}

	return make_tuple(0, 0, 0);
}

int main() {

	//����� �ӵ� ���
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<tuple<int, int, int>> result;

	//�Է� & ����
	vector<bool> is_prime(MAX + 1, true);
	vector<int> prime = getPrime(is_prime);

	while (true) {
		cin >> n;
		if (n == 0) break; // 0 �Է� �� ����

		/*vector<bool> is_prime(n+1, true);
		prime = getPrime(n, is_prime);*/
		tuple<int, int, int> value = goldbach(n, prime);

		result.push_back(value);
	}

	//���
	for (int i = 0; i < result.size(); i++) {
		if (get<0>(result[i]) == 0) {
			cout << "Goldbach's conjecture is wrong.\n";
		}
		cout << get<0>(result[i]) << " = " << get<1>(result[i]) << " + " << get<2>(result[i]) << "\n";
	}

	return 0;
}