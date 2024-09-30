#include <iostream>
#include <vector>

using namespace std;

void compareSpeed(int& v_tmp, int planet_v) {
	
	int multi = 2;

	if (v_tmp < planet_v * multi) {
		while (v_tmp < planet_v * multi) {
			multi++;
		}
		v_tmp = planet_v * multi;
	}
	else {
		v_tmp = planet_v;
	}
}

int getSpeed(vector<int> planet) {
	
	int v_tmp = planet[0]; //�������� �÷��� �ϴ� �ּ� �ӵ��� ù ��° �༺�� �ּ� �ӵ��� �ʱ�ȭ
	int multi = 2; //�����
	int answer = 0;

	for (int i = 1; i <= planet.size(); i++) { //2��° ��(=1�� �ε���)����
		if (v_tmp < planet[i]) { //v_tmp�� �༺�� �ּ� �ӵ����� ������ v_tmp���� ��������� ����
			while (v_tmp < planet[i]) { //v_tmp�� �༺�� �ּ� �ӵ����� Ŀ�� ������ �����
				v_tmp *= multi;
				multi++;
				answer = v_tmp;
			}
			compareSpeed(v_tmp, planet[i]);
		}
		else { //answer�� �༺�� �ּ� �ӵ����� ũ��
			compareSpeed(v_tmp, planet[i]);
		}
	}
}

int main() {

	int n;
	int v;
	vector<int> planet;

	//�Է�
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v;
		planet.push_back(v);
	}

	//���� & ���
	cout << getSpeed(planet);

	return 0;
}