#include <iostream>
#include <map>

using namespace std;

void findStr(string str, map<string, int>& s, int& cnt) {

	auto iter = s.find(str); //Ű ��(str) �����ϴ��� ��ȸ�ϸ鼭 Ȯ��
	if (iter != s.end()) { //**�������� ������ s.end() ��ȯ
		cnt++; //Ű �� �����ϸ� cnt ����
	}
}

int main() {

	//�Է� & ����
	int n, m;
	string str;
	map<string, int> s;
	int val = 0;
	int cnt = 0;

	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) { //map���� n���� ���ڿ� ���� ����
		cin >> str;
		s[str] = val;
	}
	for (int i = 0; i < m; i++) {
		cin >> str;
		findStr(str, s, cnt);
	}

	//���
	cout << cnt;

	return 0;
}