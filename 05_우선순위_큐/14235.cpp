#include <iostream>
#include <queue>

using namespace std;

int main() {

	int n; //���̵�� ������ �湮�� Ƚ��
	int a, present;
	priority_queue<int> present_pq; //������ ��ġ ������ ���� �켱���� ť(�ִ� ��)

	//�Է� & ���� & ���
	cin >> n;
	while (n--) {
		cin >> a;
		if (a == 0) { //���̵鿡�� �� ������ ��ġ ���
			if (present_pq.empty()) { //���̵鿡�� �� ������ ������
				cout << -1 << "\n";
			}
			else { //���̵鿡�� �� ������ ������
				cout << present_pq.top() << "\n"; //�� ����(���� ��ġ�� ū)�� ��ġ ���
				present_pq.pop(); //�� ���� ����
			}
		}
		else {
			while (a--) {
				cin >> present;
				present_pq.push(present); //a���� ������ ��ġ�� �켱���� ť�� push
			}
		}
	}

	return 0;
}