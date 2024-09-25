#include <iostream>
#include <queue>

using namespace std;

int main() {

	int n; //아이들과 거점을 방문한 횟수
	int a, present;
	priority_queue<int> present_pq; //선물의 가치 순으로 담을 우선순위 큐(최대 힙)

	//입력 & 연산 & 출력
	cin >> n;
	while (n--) {
		cin >> a;
		if (a == 0) { //아이들에게 준 선물의 가치 출력
			if (present_pq.empty()) { //아이들에게 준 선물이 없으면
				cout << -1 << "\n";
			}
			else { //아이들에게 준 선물이 있으면
				cout << present_pq.top() << "\n"; //준 선물(가장 가치가 큰)의 가치 출력
				present_pq.pop(); //준 선물 삭제
			}
		}
		else {
			while (a--) {
				cin >> present;
				present_pq.push(present); //a개의 선물의 가치를 우선순위 큐에 push
			}
		}
	}

	return 0;
}