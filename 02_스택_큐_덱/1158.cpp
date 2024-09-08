#include <iostream>
#include <queue>

using namespace std;

vector<int> calculatePer(queue<int> q, int n, int k) {
	vector<int> v(n, 0);
	int m,j = 0;

	for (int i = 1; i <= n; i++) { //큐에 순서대로 값 push
		q.push(i);
	}

	while (!q.empty()) { //큐가 empty가 아닌 동안
		for (int i = 0; i < k - 1; i++) { //k-1번 pop해서 k번째 원소에 도달
			m = q.front();
			q.pop();
			q.push(m); //처음에 pop한 원소들 다시 뒤에 push
		}

		v[j++] = q.front(); //k번째 원소 반환 및 벡터에 저장
		q.pop(); //반환했으니 삭제
	}

	return v;
}

int main() {
	
	int n, k;
	queue<int> q;

	//입력
	cin >> n >> k;

	//연산
	vector<int> result = calculatePer(q, n, k);

	//출력
	cout << "<" << result[0];
	for (int i = 1; i < n; i++) {
		cout << ", " << result[i];
	}
	cout << ">";

	return 0;
}