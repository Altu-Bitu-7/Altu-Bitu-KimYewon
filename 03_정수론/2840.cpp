#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

pair<vector<char>, int> luckyWheel(int s, char ch, pair<vector<char>, int>& p) {
	
	int idx = p.second + s; //����Ű�� �ε��� ����
	vector<char> result = p.first;

	if (idx >= result.size()) { //�ε����� ������ ũ�⸦ �Ѿ��
		idx %= result.size(); //������ ����
	}

	if (result[idx] != '?') { //�ش� ĭ�� �̹� ���� ������
		if (result[idx] != ch) { //�ٸ� �����̸� ����� ���� ����x �̹Ƿ� ! ���(*�� ���� ���� �����̸� �׳� �Ѿ)
			cout << "!";
			exit(0); //����
		}
	}
	else {
		result[idx] = ch;
	}

	p.first = result;
	p.second = idx;
	
	return p;
}

//���Ϳ� �ߺ��� ���� �ִ��� Ȯ���ϴ� �Լ�(*�ߺ� ���ڰ� �����ϸ� ����� ���� ����x)
bool hasDuplicates(vector<char>& v) {
	
	unordered_set<char> s; //set �̿�

	//������ �� ��Ҹ� ��ȸ
	for (char ch : v) {

		// '?'�� ����(�ߺ��̾ ������)
		if (ch == '?') {
			continue;
		}

		//���� �̹� set�� �����ϴ��� Ȯ��
		if (s.find(ch) != s.end()) {
			return true; // �ߺ� �� ���� �� true ��ȯ
		}
		//���� ���� s�� �߰�
		s.insert(ch);
	}

	// ��� ��Ҹ� ��ȸ�� �� �ߺ��� ������ false ��ȯ
	return false;
}

int main() {

	int n, k, s;
	char ch;

	//�Է� & ����
	cin >> n >> k;
	vector<char> result(n, '?'); //n���� ĭ, ?�� �ʱ�ȭ
	pair<vector<char>, int> p;
	p.first = result;
	p.second = 0;

	for (int i = 0; i < k; i++) {
		cin >> s >> ch;
		p = luckyWheel(s, ch, p);
	}

	//���
	result = p.first;
	int idx = p.second;

	if (hasDuplicates(result)) { //�ٸ� ĭ�ε� �ߺ� ���� �����ϴ� ���
		cout << "!";
		exit(0);
	}

	while (n--) { //n������
		if (idx == result.size()-1) { //�ε����� ���� ���� ������ �������� ���(���� == �ð����)
			cout << result[idx--];
		}
		else {
			cout << result[idx--];
			if (idx < 0) { //�ε����� ������ �Ǹ�
				idx += result.size(); //�� ������ �̵�
			}
		}
	}

	return 0;
}