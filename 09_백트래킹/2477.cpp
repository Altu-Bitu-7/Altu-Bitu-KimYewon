/* 푸는 중 */
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

	//폭, 높이의 최댓값 구하기
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

	int area = max_height * max_width; //직사각형 넓이를 우선적으로 계산
	
	int sub = 0;
	if (side[1].second < side[5].second) { //2번째 동쪽으로의 길이가 6번째 서쪽으로의 길이보다 작은 경우 (ㄱ 또는┏)
		if (side[0].second < side[4].second) { //1번째 남쪽으로의 길이가 5번째 북쪽으로의 길이보다 작은 경우(ㄱ)
			sub = side[1].second * side[2].second;
		}
		else { //1번째 남쪽으로의 길이가 5번째 북쪽으로의 길이보다 큰 경우(┏)
			sub = side[2].second * side[3].second;
		}
	}
	else { //2번째 동쪽으로의 길이가 6번째 서쪽으로의 길이보다 큰 경우 (┗ 또는 ┛)
		if (side[0].second < side[2].second) { //1번째 남쪽으로의 길이가 3번째 북쪽으로의 길이보다 작은 경우(┛)
			sub = side[4].second * side[5].second;
		}
		else { //1번째 남쪽으로의 길이가 3번째 북쪽으로의 길이보다 큰 경우(┗)
			sub = side[3].second * side[4].second;
		}
	}

	if (side[i].first == EAST) {

	}

	switch (side[i].first) {
	case 1: 
	}

	area -= sub; //빈 네모 넓이 제외
	
	return area * k; //참외의 총 개수 반환
}

int main() {

	int k;
	int direction, length;
	vector<ii> side(SIDE_NUM);

	//입력
	cin >> k;
	for (int i = 0; i < SIDE_NUM; i++) {
		cin >> direction >> length;
		side[i].first = direction;
		side[i].second = length;
	}

	//연산 & 출력
	cout << calNumOfKMelon(side, k);

	return 0;
}