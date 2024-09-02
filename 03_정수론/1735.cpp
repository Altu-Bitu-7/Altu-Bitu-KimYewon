#include <iostream>
#include <vector>

using namespace std;

int getGcd(int a, int b) {

	//��Ŭ���� ȣ����
	while (a) {
		b %= a;
		swap(a, b);
	}

	return b; //�ִ����� ��ȯ
}

pair<int, int> sum(int a, int b, int c, int d, int lcm) {

	pair<int, int> p;
	int tmp1 = lcm / b;
	int tmp2 = lcm / d;

	a *= tmp1;
	b *= tmp1;
	c *= tmp2;
	d *= tmp2;

	int num = a + c; //����

	p.first = num;
	p.second = b; //�и�(b == d)

	return p;
}

pair<int, int> calculateIrreFrac(int a, int b, int gcd) {
	pair<int, int> irre_frac;

	a /= gcd; //���ڸ� �ִ������� ����
	b /= gcd; //�и� �ִ������� ����
	irre_frac.first = a; //pair�� ����
	irre_frac.second = b;

	return irre_frac;
}

int main() {

	int a, b, c, d;

	//�Է�
	cin >> a >> b; //ù��° ���� ����(���� < �и�), �и�
	cin >> c >> d; //�ι�° ���� ����, �и�

	//����
	int gcd1 = getGcd(b, d); //�и𳢸��� �ִ�����
	int lcm = (b * d) / gcd1; //�и𳢸��� �ּҰ����

	pair<int, int> sum_result = sum(a, b, c, d, lcm); //���ϱ�

	int gcd2 = getGcd(sum_result.first, sum_result.second); //���� ���� ���ڿ� �и��� �ִ�����
	pair<int, int> result = calculateIrreFrac(sum_result.first, sum_result.second, gcd2); //���

	//���
	cout << result.first << " " << result.second;

	return 0;
}