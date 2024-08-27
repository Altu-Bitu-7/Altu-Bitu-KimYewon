#include <iostream>
#include <queue>

using namespace std;

vector<int> calculatePer(queue<int> q, int n, int k) {
	vector<int> v(n, 0);
	int m,j = 0;

	for (int i = 1; i <= n; i++) { //ť�� ������� �� push
		q.push(i);
	}

	while (!q.empty()) { //ť�� empty�� �ƴ� ����
		for (int i = 0; i < k - 1; i++) { //k-1�� pop�ؼ� k��° ���ҿ� ����
			m = q.front();
			q.pop();
			q.push(m); //ó���� pop�� ���ҵ� �ٽ� �ڿ� push
		}

		v[j++] = q.front(); //k��° ���� ��ȯ �� ���Ϳ� ����
		q.pop(); //��ȯ������ ����
	}

	return v;
}

int main() {
	
	int n, k;
	queue<int> q;

	//�Է�
	cin >> n >> k;

	//����
	vector<int> result = calculatePer(q, n, k);

	//���
	cout << "<" << result[0];
	for (int i = 1; i < n; i++) {
		cout << ", " << result[i];
	}
	cout << ">";

	return 0;
}