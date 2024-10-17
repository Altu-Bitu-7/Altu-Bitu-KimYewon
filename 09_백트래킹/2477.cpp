/* Ǫ�� �� */
#include <iostream>
#include <vector>

using namespace std;
const int EAST = 1;
const int WEST = 2;
const int SOUTH = 3;
const int NORTH = 4;
const int SIDE_NUM = 6;
typedef pair<int, int> ii;

int calNumOfKMelon(vector<ii> side, int k) {

	//��, ������ �ִ� ���ϱ�
	int max_width = 0;
	int max_height = 0;

	for (int i = 0; i < SIDE_NUM; i++) {
		if (side[i].first == EAST || side[i].first == WEST) {
			max_width = max(max_width, side[i].second);
		}
		else { //side[i], first == SOUTH || side[i], first == NORTH
			max_height = max(max_height, side[i].second);
		}
	}

	int area = max_height * max_width; //���簢�� ���̸� �켱������ ���
	
	int sub = 0;
	if (side[1].second < side[5].second) { //2��° ���������� ���̰� 6��° ���������� ���̺��� ���� ��� (�� �Ǵ¦�)
		if (side[0].second < side[4].second) { //1��° ���������� ���̰� 5��° ���������� ���̺��� ���� ���(��)
			sub = side[1].second * side[2].second;
		}
		else { //1��° ���������� ���̰� 5��° ���������� ���̺��� ū ���(��)
			sub = side[2].second * side[3].second;
		}
	}
	else { //2��° ���������� ���̰� 6��° ���������� ���̺��� ū ��� (�� �Ǵ� ��)
		if (side[0].second < side[2].second) { //1��° ���������� ���̰� 3��° ���������� ���̺��� ���� ���(��)
			sub = side[4].second * side[5].second;
		}
		else { //1��° ���������� ���̰� 3��° ���������� ���̺��� ū ���(��)
			sub = side[3].second * side[4].second;
		}
	}

	if (side[i].first == EAST) {

	}

	switch (side[i].first) {
	case 1: 
	}

	area -= sub; //�� �׸� ���� ����
	
	return area * k; //������ �� ���� ��ȯ
}

int main() {

	int k;
	int direction, length;
	vector<ii> side(SIDE_NUM);

	//�Է�
	cin >> k;
	for (int i = 0; i < SIDE_NUM; i++) {
		cin >> direction >> length;
		side[i].first = direction;
		side[i].second = length;
	}

	//���� & ���
	cout << calNumOfKMelon(side, k);

	return 0;
}