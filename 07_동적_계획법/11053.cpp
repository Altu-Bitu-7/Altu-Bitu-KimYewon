#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getLongIncSubsequence(vector<int>& a) {

	int a_size = a.size();
	vector<int> lis(a_size, 0);

	lis[0] = 1;
	for (int i = 1; i < a_size; i++) {
		lis[i] = 1;
		
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) { //i 이전의 값과 비교
				lis[i] = max(lis[j] + 1, lis[i]);
			}
		}
	}

	sort(lis.begin(), lis.end()); //오름차순 정렬
	return lis[a_size - 1];
}

int main() {

	int n, a_i;
	vector<int> a;

	//입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a_i;
		a.push_back(a_i);
	}

	//연산 & 출력
	cout << getLongIncSubsequence(a);

	return 0;
}