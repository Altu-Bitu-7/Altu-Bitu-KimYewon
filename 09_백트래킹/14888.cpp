#include <iostream>
#include <vector>

using namespace std;
const int PLUS = 1;
const int MINUS = 2;
const int MULTIPLE = 3;
const int DIVISION = 4;
const int MAX_N = 11;
const int MAX_OPER = 5;

int n;
int a[MAX_N];
int oper[MAX_OPER]; //1�� �ε��� = ����, 2�� �ε��� = ����, 3�� �ε��� = ����, 4�� �ε��� = ������

int max_num = -1000000000; //�ִ� 10��, �ּ� -10��
int min_num = 1000000000;

//������ ����ϴ� �Լ�
int calculate(int oper, int result, int cnt) {

	if (oper == PLUS) {
		result += a[cnt + 1];
	}
	else if (oper == MINUS) {
		result -= a[cnt + 1];
	}
	else if (oper == MULTIPLE) {
		result *= a[cnt + 1];
	}
	else { //������
		result /= a[cnt + 1];
	}

	return result;
}

//�ִ�, �ּҰ��� �����ϴ� �Լ�
void updateAns(int new_result) {
	max_num = max(max_num, new_result);
	min_num = min(min_num, new_result);
}

//������ ����� �Լ�
void makeExpression(int result, int cnt) {

	//���� ����: n-1���� �����ڸ� ��� ����� ��� 
	if (cnt == n - 1) {
		updateAns(result);
		return;
	}

	for (int i = 1; i <= 4; i++) {
		if (oper[i] > 0) { //�ش� ������ ���Ƚ���� ���� ��쿡��
			oper[i]--; //������ ��� üũ
			int new_result = calculate(i, result, cnt);

			makeExpression(new_result, cnt + 1);

			//��������
			oper[i]++;
		}
	}
}

int main() {

	//�Է�
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i]; //���� a
	}

	oper[0] = 0;
	for (int i = 1; i < MAX_OPER; i++) {
		cin >> oper[i]; //������ ����
	}

	//����
	makeExpression(a[0], 0); //result �ʱⰪ: ù ��° ����

	//���
	cout << max_num << "\n" << min_num;

	return 0;
}