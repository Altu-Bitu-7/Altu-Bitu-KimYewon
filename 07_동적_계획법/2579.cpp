#include <iostream>
#include <vector>

using namespace std;

int calcMaxScore(vector<int>& score_v) {

	int n = score_v.size();
	vector<int> dp(n, 0); //���� ��ܱ����� ���� �ִ��� ������ ����

	//3��° ��� ����
	dp[0] = score_v[0];
	dp[1] = score_v[0] + score_v[1];
	dp[2] = max(score_v[0], score_v[1]) + score_v[2];

	//����
	for (int i = 3; i < n; i++) {
		dp[i] = score_v[i] + max(dp[i - 3] + score_v[i - 1], dp[i - 2]); //��������� ���� + ���� ������ �ִ�
	}

	return dp[n-1];
}

int main() {

	int stair, score;
	vector<int> score_v;

	//�Է�
	cin >> stair;
	for (int i = 0; i < stair; i++) {
		cin >> score;
		score_v.push_back(score);
	}

	//���� & ���
	cout << calcMaxScore(score_v);

	return 0;
}