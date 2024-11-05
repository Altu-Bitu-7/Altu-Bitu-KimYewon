#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int n, int key_num, vector<int>& card_num) {

	int left = 0;
	int right = n - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		
		if (card_num[mid] == key_num) { // 카드 정수에 해당 값이 존재하면 1 반환
			return 1;
		}
		else if (card_num[mid] > key_num) { //왼쪽(더 작은 쪽) 탐색
			right = mid - 1;
		}
		else { //오른쪽(더 큰 쪽) 탐색
			left = mid + 1;
		}
	}

	return 0; //존재하지 않으면 0 반환
}

int main() {

	ios_base::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);

	int n, m;
	int key_num;

	//입력
	cin >> n;
	vector<int> card_num(n);
	for (int i = 0; i < n; i++) {
		cin >> card_num[i];
	}

	sort(card_num.begin(), card_num.end()); //정렬

	cin >> m;
	while(m--) {
		cin >> key_num;
		//연산 & 출력
		cout << binarySearch(n, key_num, card_num) << " ";
	}

	return 0;
}