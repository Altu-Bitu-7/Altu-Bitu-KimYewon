#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int streetLamp(int n, int m, vector<int> x) {

	int x_size = x.size();

	int max_distance = max((x[1] - x[0]), (x[x_size - 1] - x[x_size - 2]));
	
	for (int i = 1; i < x_size - 2; i++) {

		int tmp_distance = ceil(double((x[i + 1] - x[i])) / 2); ////가로등 사이의 간격이 홀수일 경우 때문에 반올림 필요
		
		max_distance = max(max_distance, tmp_distance); //가로등 간격의 최댓값 갱신
	}

	return max_distance; //가로등 간격의 최댓값이 가로등 높이의 최솟값
}

int main() {

	int n, m; // 굴다리의 길이, 가로등의 개수
	vector<int> x; //설치할 수 있는 가로등의 위치
	int x_tmp;

	//입력
	cin >> n;
	cin >> m;

	x.push_back(0);
	for (int i = 1; i <= m; i++) {
		cin >> x_tmp;
		x.push_back(x_tmp);
	}
	x.push_back(n);

	//연산 & 출력
	cout << streetLamp(n, m, x);

	return 0;
}