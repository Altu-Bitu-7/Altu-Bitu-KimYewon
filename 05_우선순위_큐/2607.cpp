#include <iostream>
#include <vector>

using namespace std;

//ù��° �ܾ��� ���ĺ� ������ vector<int>�� ����
void getFirstWordAlpha(string first_word, vector<int>& first_alphabet) {

	for (int i = 0; i < first_word.length(); i++) {
		first_alphabet[first_word[i] - 'A']++; //�ܾ��� ���ĺ��� ���ڷ� ��ȯ, �ش� �ε����� first_alphabet ���Ͱ��� +1 
	}
}

//ù �ܾ�� �Է����� ���� �ܾ ���� '����� �ܾ�'���� Ȯ���ؼ� ī��Ʈ�ϴ� �Լ�
void getSimilarWord(vector<int> first_alphabet, string word, int& cnt) {

	vector<int> alphabet(26, 0); //���ĺ��� ������ �� ����
	int different = 0; //���̳��� ���ĺ��� ������ �� ����
	int add_cnt = 0; //�� ���ĺ� ���� ���̰� 1�� �������� Ȯ���ϱ� ���� ������(2�� �̻��̸� ����� �ܾ �� �� x)
	int sub_cnt = 0;

	for (int i = 0; i < word.length(); i++) {
		alphabet[word[i] - 'A']++; //�ܾ��� ���ĺ��� ���ڷ� ��ȯ, �ش� �ε����� alphabet ���Ͱ��� +1 
	}

	for (int i = 0; i < first_alphabet.size(); i++) {

		int diff_tmp = first_alphabet[i] - alphabet[i];
		if (diff_tmp != 0) { //���̰� ������
			if (diff_tmp == 1) { //ù �ܾ��� ���ĺ����� �ϳ� ������
				add_cnt++;
			}
			if (diff_tmp == -1) { //ù �ܾ��� ���ĺ����� �ϳ� ������
				sub_cnt++;
			}
			different += abs(diff_tmp); //���̳��� ������ŭ ���ϱ�
		}
	}

	//1. ���̰� ���ų� 
	//2. 1���̰ų�(���ϰų� ���� ������ �� ����) 
	//3. 2���ε� �ٸ� ���ڿ��� 1�����̸�(��ü�ؼ� ������ �� ����)
	if (different == 0 || different == 1 || different == 2 && (add_cnt == 1 && sub_cnt == 1)) {
		cnt++; //����� �ܾ� ī��Ʈ
	}
}

int main() {

	int n;
	string first_word;
	string word;
	vector<int> first_alphabet(26, 0); //ù �ܾ��� ���ĺ��� ������ �� ����
	int cnt = 0; //����� �ܾ��� ������ �� ����

	//�Է� & ����
	cin >> n;
	cin >> first_word;
	getFirstWordAlpha(first_word, first_alphabet);

	for (int i = 0; i < n - 1; i++) {
		cin >> word;
		getSimilarWord(first_alphabet, word, cnt);
	}

	//���
	cout << cnt;

	return 0;
}