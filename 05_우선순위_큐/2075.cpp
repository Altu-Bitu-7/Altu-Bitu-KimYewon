#include <iostream>
#include <queue>

using namespace std;

//n���� ��Ҹ� ���� �ּ� ���� ����� �Լ�
void makeMinHeap(int num, priority_queue<int, vector<int>, greater<int>>& pq, int n) {

	/* �̷��� �׳� �ִ� ���� �� ���� ���� ���ϸ� �޸� �ʰ�
	for (int i = 0; i < n-1; i++) {
		pq.pop();
	}

	return pq.top();
	*/

	pq.push(num); //�� push

	if (pq.size() > n) { //pq�� ��� ���� n���� ������
		pq.pop(); //���� ���� ��(root ��) pop
	}
	
}

int main() {

	//����� ��� �ڵ�
	ios::sync_with_stdio(0);
	cin.tie(NULL); 
	cout.tie(NULL);

	int n;
	int num;
	priority_queue<int, vector<int>, greater<int>> pq; //�ּ� ��

	//�Է� & ����
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			makeMinHeap(num, pq, n);
		}
	}

	//���
	cout << pq.top(); //���� n���� �� �� ���� ���� ���� n��°�� ū ��

	return 0;
}