#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//최대 과자 길이가 'length'가 되도록 과자를 배분했을 때, 과자를 받은 조카의 수
int cntNephew(int length, vector<int>& snack) {

	int cnt = 0; //cnt값 0으로 초기화

	for (int i = 0; i < snack.size(); i++) {
		if (snack[i] >= length) {
			int tmp = snack[i] / length; //과자를 여러 조각으로 쪼갤 수 있으므로
			cnt += tmp;
		}
	}

	return cnt;
}

int binarySearch(int n, int m, vector<int>& snack) {

	int left = 1;
	int right = snack.back(); //1 ~ 주어진 제일 긴 과자 길이까지의 범위를 탐색
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;

		int distributed = cntNephew(mid, snack);

		if (distributed >= m) { //모든 조카(m명)에게 과자를 나눠줄 수 있으면 -> 과자의 길이를 늘려서 탐색
			left = mid + 1;
		}
		else { //모든 조카(m명)에게 과자를 나눠줄 수 없으면 -> 과자의 길이를 줄여서 탐색
			right = mid - 1;
		}
	}

	//과자의 총 길이 합
	int sum = 0;
	for (int i = 0; i < snack.size(); i++) {
		sum += snack[i];
	}

	if (sum < m) { //모든 조카에게 같은 길이의 과자를 나눠줄 수 없는 경우 0 반환
		return 0;
	}
	else {
		return left - 1; //탐색이 끝난 후 upper bound 값에서 1을 뺌
	}
}

int main() {

	ios_base::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);

	int m, n;

	//입력
	cin >> m >> n;

	vector<int> snack(n);
	for (int i = 0; i < n; i++) {
		cin >> snack[i];
	}

	sort(snack.begin(), snack.end()); //정렬

	//연산 & 출력
	cout << binarySearch(n, m, snack);

	return 0;
}