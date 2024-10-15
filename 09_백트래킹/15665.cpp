#include <iostream>
#include <vector>
#include <set>

using namespace std;
const int MAX_N_M = 7;
const int MAX_NUM = 10000;

int n, m;
set<int> num_s; //�ڵ����� ������ ����
vector<int> sequence(MAX_N_M, 0);

//���� ����ϴ� �Լ�
void printSequence() {
	for (int i = 0; i < m; i++) {
		cout << sequence[i] << " ";
	}
	cout << "\n";
	return;
}

//�ߺ� ���� ����� �Լ�
void getSequence(int cnt) {

	//���� ����: M���� ���ڸ� ��� ���� ���
	if (cnt == m) {
		printSequence();
		return;
	}

	for (set<int>::iterator iter = num_s.begin(); iter != num_s.end(); iter++) { //set ��ȸ�� iter ���
		sequence[cnt] = *iter;
		getSequence(cnt + 1);
	}
}

int main() {

	int num;
	
	//�Է�
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		num_s.insert(num);
	}

	//���� & ���
	getSequence(0);

	return 0;
}