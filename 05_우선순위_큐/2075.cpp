#include <iostream>
#include <queue>

using namespace std;

//n개의 요소를 가진 최소 힙을 만드는 함수
void makeMinHeap(int num, priority_queue<int, vector<int>, greater<int>>& pq, int n) {

	/* 이렇게 그냥 최대 힙에 다 넣은 다음 구하면 메모리 초과
	for (int i = 0; i < n-1; i++) {
		pq.pop();
	}

	return pq.top();
	*/

	pq.push(num); //값 push

	if (pq.size() > n) { //pq의 요소 수가 n개를 넘으면
		pq.pop(); //가장 작은 수(root 값) pop
	}
	
}

int main() {

	//입출력 향상 코드
	ios::sync_with_stdio(0);
	cin.tie(NULL); 
	cout.tie(NULL);

	int n;
	int num;
	priority_queue<int, vector<int>, greater<int>> pq; //최소 힙

	//입력 & 연산
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			makeMinHeap(num, pq, n);
		}
	}

	//출력
	cout << pq.top(); //상위 n개의 수 중 가장 작은 수가 n번째로 큰 수

	return 0;
}