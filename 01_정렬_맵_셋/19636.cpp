#include <iostream>
#include <cmath>

using namespace std;

int main() {

	//�Է�
	int w0, i0, t, a0 = 0; //���̾�Ʈ ��
	int d;
	int i, a; //���̾�Ʈ ��
	int w1, w2, i2; //���̾�Ʈ ��
	int w3;

	cin >> w0 >> i0 >> t;
	cin >> d >> i >> a;

	//���
	//���ʴ�緮 ��ȭ ��� x
	w1 = w0;
	while (d--) {
		w1 += i - (i0 + a);
	}
	
	if (w1 <= 0 || i0 <= 0) {
		cout << "Danger Diet" << '\n';
	}
	else {
		cout << w1 << " " << i0 << '\n';
	}

	//���ʴ�緮 ��ȭ ��� o
	w2 = w0;
	i2 = i0;
	while (d--) {
		w2 += i - (i2 + a);
		if (abs(i - (i2 + a)) > t) {
			i2 += float(i - (i2 + a)) / 2.0;
		}
	}

	if (w2 <= 0 || i2 <= 0) {
		cout << "Danger Diet" << '\n';
	}
	else {
		w3 = w2;
		w3 += (i0 - (i2 + a0));
		if (w3 > w2) {
			cout << w2 << " " << i2 << " " << "YOYO" << '\n';
		}
		else {
			cout << w2 << " " << i2 << " " << "NO" << '\n';
		}
	}

	return 0;
}