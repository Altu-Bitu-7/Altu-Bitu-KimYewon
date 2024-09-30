#include <iostream>
#include <vector>

using namespace std;

int calcMaxScore(vector<int>& score_v) {

	int n = score_v.size();
	vector<int> dp(n, 0); //현재 계단까지의 점수 최댓값을 저장할 벡터

	//3번째 계단 까지
	dp[0] = score_v[0];
	dp[1] = score_v[0] + score_v[1];
	dp[2] = max(score_v[0], score_v[1]) + score_v[2];

	//이후
	for (int i = 3; i < n; i++) {
		dp[i] = score_v[i] + max(dp[i - 3] + score_v[i - 1], dp[i - 2]); //현재까지의 점수 + 이전 점수의 최댓값
	}

	return dp[n-1];
}

int main() {

	int stair, score;
	vector<int> score_v;

	//입력
	cin >> stair;
	for (int i = 0; i < stair; i++) {
		cin >> score;
		score_v.push_back(score);
	}

	//연산 & 출력
	cout << calcMaxScore(score_v);

	return 0;
}