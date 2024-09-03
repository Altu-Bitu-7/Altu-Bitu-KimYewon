#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//�ø����ȣ�� ��� �ڸ��� �� ���ϱ�
int sum(string sn1) {
	int result = 0;

	for (int i = 0; i < sn1.length(); i++) {
		if (isdigit(sn1[i])) { //�����̸�
			result += sn1[i] - '0'; //char -> int
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
	cin >> n;
	vector<string> serial_num_arr(n, ""); //�ø���ѹ�

	for (int i = 0; i < n; i++) {
		cin >> serial_num_arr[i];
	}

	//����
	sort(serial_num_arr.begin(), serial_num_arr.end(), cmp);

	//���
	for (int i = 0; i < n; i++) {
		cout << serial_num_arr[i] << '\n';
	}

	return 0;
}