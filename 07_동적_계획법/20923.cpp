#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//�̱� ��� ����
string winner(deque<int>& do_dec, deque<int>& su_dec) {

	int do_dec_size = do_dec.size();
	int su_dec_size = su_dec.size();

	if (do_dec_size > su_dec_size) {
		return "do";
	}
	else if (su_dec_size > do_dec_size) {
		return "su";
	}
	else { //ī���� ������ ������
		return "dosu";
	}
}

//�׶����� ī�带 ���� ��ġ�� �Լ�
void mergeCard(deque<int>& dec, deque<int>& ground) {
	while (!ground.empty()) {
		dec.push_back(ground.back()); //�׶����� ī�� ���̸� ����� ��ħ
		ground.pop_back();
	}
}

//���� ġ�� �Լ�(�� ģ Ƚ�� ī��Ʈ)
void ringABell(string who, deque<int>& do_dec, deque<int>& su_dec, deque<int>& do_ground, deque<int>& su_ground) {

	if (who == "do") { //���� ���� ��ġ�� ī���� ���ڰ� 5�� ������ ���� ��
		mergeCard(do_dec, su_ground); //��� �׶����� ī�� ���̸� ���� ��ħ
		mergeCard(do_dec, do_ground); //���� �׶����� ī�� ���̸� ���� ��ħ
	} 
	else if (who == "su") { //���� ���� ��ġ�� ī���� ������ ���� 5�� �Ǹ� ������ ��
		mergeCard(su_dec, do_ground);
		mergeCard(su_dec, su_ground);
	}
}

//���� ĥ �� �ִ� ��� ã�� �Լ�
string canRing(deque<int>& do_ground, deque<int>& su_ground){

	if (!do_ground.empty() && do_ground.front() == 5) {
		return "do";
	}
	if (!su_ground.empty() && su_ground.front() == 5) {
		return "do";
	}
	if (!do_ground.empty() && !su_ground.empty() && do_ground.front() + su_ground.front() == 5) {
		return "su";
	}
	return "can't";
}

string playHalliGalli(deque<int>& do_dec, deque<int>& su_dec, int m) {
	
	deque<int> do_ground, su_ground;
	bool turn = 0; //turn: 0�̸� ���� ��, 1�̸� ������ ��

	while (m--) { //m���� ���� ����
		if (turn == 0) { //���� ���̸�
			do_ground.push_front(do_dec.front()); //������ �׶��忡 �� �� ī�带 ��������
			do_dec.pop_front();
		}
		else { //������ ���̸�
			su_ground.push_front(su_dec.front()); //�����̰� �׶��忡 �� �� ī�带 ��������
			su_dec.pop_front();
		}

		if (do_dec.empty() || su_dec.empty()) { //�� ����̶� ���� ī�� ���� 0�̸� ����
			break;
		}

		string who = canRing(do_ground, su_ground);
		if (who != "can't") {
			ringABell(who, do_dec, su_dec, do_ground, su_ground);
		}

		// �� ��ü
		turn = 1 - turn;

	}
	return winner(do_dec, su_dec);
}

int main() {

	int n, m;
	int do_num, su_num;
	deque<int> do_dec, su_dec;

	//�Է�
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> do_num >> su_num;
		do_dec.push_front(do_num);
		su_dec.push_front(su_num);
	}

	//���� & ���
	cout << playHalliGalli(do_dec, su_dec, m);

	return 0;
}