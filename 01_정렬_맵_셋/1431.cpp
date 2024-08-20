#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//�ø����ȣ�� ��� �ڸ��� �� ���ϱ�
int sum(string sn1) {
	int result = 0;

	for (int i = 0; i < sn1.length(); i++) {
		int num = sn1[i] - '0';//string -> int
		if (num >= 0 && num <= 9) { //�����̸�
			result = result + num;
		}
	}
	return result;
}

bool cmp(string sn1, string sn2) {

	if (sn1.length() != sn2.length()) { //���̰� �ٸ���
		return sn1.length() < sn2.length(); //sn1�� ��� swap
	}
	else {
		int sum1 = sum(sn1);
		int sum2 = sum(sn2);

		if (sum1 != sum2) { //�ڸ����� ���� �ٸ���
			return sum1 < sum2; // sum1�� ũ�� swap
		}
		else { //���� �� �������� �񱳰� �Ұ����ϸ�
			return sn1 < sn2; //������
		}
	}
}

int main() {

	//�Է�
	int n; //��Ÿ ����
	string serial_num_arr[50]; //�ø���ѹ�

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> serial_num_arr[i];
	}

	//����
	sort(serial_num_arr, serial_num_arr + n, cmp);

	//���
	for (int i = 0; i < n; i++) {
		cout << serial_num_arr[i] << '\n';
	}

	return 0;
}