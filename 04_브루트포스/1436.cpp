#include <iostream>
#include <string>

using namespace std;

int getNumOfApo(int n) {

	int cnt = 0;
	for (int i = 0; i < 10000000; i++) { //n <= 10,000�̶�� ������ �����Ƿ� ���Ʈ���� ����
		if (to_string(i).find("666") != string::npos) { //i�� 666�� ���ԵǾ� ������ ī��Ʈ
			cnt++;
		}
		if (cnt == n) { //n��° ���� �����ϸ�
			return i;
		}
	}

	return 0;
}

int main() {

	int n;

	//�Է�
	cin >> n;

	//���� & ���
	cout << getNumOfApo(n);

	return 0;
}