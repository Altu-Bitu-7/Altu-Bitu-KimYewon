#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

const int MAX = 1000000;

//�����佺�׳׽��� ü
void getPrime(vector<bool>& is_prime) {

	is_prime[0] = is_prime[1] = false; //0�� 1�� �Ҽ�x

	for (int i = 2; i * i <= MAX; i++) {
		if (is_prime[i]) { //i�� �Ҽ����
			for (int j = i * i; j <= MAX; j += i) {
				is_prime[j] = false; //i�� ��� ����
			}
		}
	}

	/* ó���� �õ���, �Ҽ��� ���� �����ϰ� �� ������ ���غ��� ��� -> �ð� ���⵵�� �ʹ� Ŀ���� �ð� �ʰ��� ��
	vector<int> v;
	for (int i = 2; i < MAX; i++) {
		if (is_prime[i] == true) {
			v.push_back(i); //�Ҽ��� �����ϴ� ����
		}
	}

	return v;
	*/

}

//���� n�� �Ǵ� �� Ȧ�� �Ҽ� ã�� �Լ�
tuple<int, int, int> goldbach(int n, vector<bool>& is_prime) {
	
	/* ó���� �õ���, �Ҽ��� ���� �����ϰ� �� ������ ���غ���(b-a�� ���� ū �� ã�ƾ� �ϹǷ�) ��� -> �ð� ���⵵�� �ʹ� Ŀ���� �ð� �ʰ��� ��
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

	for (int i = 0; i <= n / 2; i++) { //n/2������ Ȯ���ϸ� ��(�� ������ ¦�� �̷�� ����. ex. 8 = 3 + 5 = 5 + 3
		if (is_prime[i]) { //i�� �Ҽ��̸�
			if (is_prime[n - i]) { //n-i�� �Ҽ��̸�(���� n�� �Ǵ� �ٸ� ���� �Ҽ����� Ȯ��)
				return make_tuple(n, i, n - i);
			}
		}
	}

	return make_tuple(0, 0, 0); //�� Ȧ�� �Ҽ��� ã�� ���� ��� tuple<0, 0, 0>�� ��ȯ
}

int main() {

	//����� �ӵ� ���
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<tuple<int, int, int>> result; //����� ������ tuple<�־��� �Է� ���� n, Ȧ�� �Ҽ� a, Ȧ�� �Ҽ� b>

	//�Է� & ����
	vector<bool> is_prime(MAX + 1, true);
	getPrime(is_prime); //1 ~ MAX�� ���� �Ҽ� �Ǻ�

	while (true) {
		cin >> n;
		if (n == 0) {
			break; // 0 �Է� �� ����
		}

		tuple<int, int, int> value = goldbach(n, is_prime);

		result.push_back(value); //����� n, a, b�� tuple�� ���Ϳ� ����
	}

	//���
	for (int i = 0; i < result.size(); i++) {
		if (get<0>(result[i]) == 0) { //tuple�� ù��° ���� 0�� ��� �ش��ϴ� �� Ȧ�� �Ҽ��� ã�� ���� ��.
			cout << "Goldbach's conjecture is wrong.\n";
		}
		cout << get<0>(result[i]) << " = " << get<1>(result[i]) << " + " << get<2>(result[i]) << "\n";
	}

	return 0;
}