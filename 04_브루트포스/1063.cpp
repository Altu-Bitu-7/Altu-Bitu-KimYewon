#include <iostream>
#include <utility>

using namespace std;

typedef pair<char, char> cc; //pair<char, char> Ÿ���� ���� ���Ƿ� ����

//king�� ������ ���� king�� ���� ��ġ�� ���ϴ� �Լ�
cc movePos(char ch, char num, string k_move) {

	cc pos;

	if (k_move.find("R") != string::npos) { //k_move ���ڿ��� "R"�� ���ԵǾ� ������
		ch++; //���� + 1
	}
	if (k_move.find("L") != string::npos) { //k_move ���ڿ��� "L"�� ���ԵǾ� ������
		ch--; //���� - 1
	}
	if (k_move.find("B") != string::npos) { //k_move ���ڿ��� "B"�� ���ԵǾ� ������
		num--; //���� - 1
	}
	if (k_move.find("T") != string::npos) { //k_move ���ڿ��� "T"�� ���ԵǾ� ������
		num++; //���� + 1
	}

	pos.first = ch;
	pos.second = num;
	return pos;
}

//king�� ���� ��ġ�� ���������� üũ�ϴ� �Լ�
bool isSamePos(cc k_tmp, cc s_pos) {
	if (k_tmp.first == s_pos.first && k_tmp.second == s_pos.second) { //king�� ���� ��ġ�� ������ true ��ȯ
		return true;
	}
	return false;
}

//king�� ���� ��ġ�� ����(A~H, 1~8)�� ������� üũ�ϴ� �Լ�
bool checkPos(cc pos) {
	if (pos.first >= 'A' && pos.first <= 'H' && pos.second >= '1' && pos.second <= '8') { //���� �ȿ� ���������� ������ true ��ȯ
		return true;
	}
	return false;
}

int main() {

	string king, stone;
	int n;
	string k_move;
	cc k_pos, s_pos;
	cc k_tmp, s_tmp;

	//�Է� & ����
	cin >> king >> stone >> n;

	k_pos.first = king[0];
	k_pos.second = king[1];
	s_pos.first = stone[0];
	s_pos.second = stone[1];

	for (int i = 0; i < n; i++) {
		cin >> k_move;
		k_tmp = movePos(k_pos.first, k_pos.second, k_move);
		if (isSamePos(k_tmp, s_pos)) { //�̵��� king�� ��ġ�� ���� ��ġ�� ������ �� �̵�
			s_tmp = movePos(s_pos.first, s_pos.second, k_move);
			if (checkPos(k_tmp)) { //�̵��� king�� ��ġ�� ���� ��ġ�� ���� �ȿ� ������
				if (checkPos(s_tmp)) {
					k_pos = k_tmp; //�̵� ������Ʈ
					s_pos = s_tmp;
				}
			}
		}
		else {
			if (checkPos(k_tmp)) { //�̵��� king�� ��ġ�� ���� �ȿ� ������(�� �̵�x)
				k_pos = k_tmp; //�̵� ������Ʈ
			}
		}
	}

	//���
	cout << k_pos.first << k_pos.second << "\n";
	cout << s_pos.first << s_pos.second;

	return 0;
}