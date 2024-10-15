#include <iostream>
#include <queue>

using namespace std;

int n, m;
int person1, person2;

int graph[101][101] = { 0, }; //그래프 배열
bool visited[101] = { false, }; //방문 배열
int answer[101] = { 0, };
int idx = 1;

//BFS
int getRelatives(int person1, int person2) {

	queue<int> q;
	q.push(person1);
	visited[person1] = true;
	answer[person1] = 0; // 시작점의 촌수는 0

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (graph[now][i] == 1 && !visited[i]) {
				visited[i] = true;
				answer[i] = answer[now] + 1; // 촌수(거리) 증가
				q.push(i);

				// person2를 찾으면 촌수를 반환
				if (i == person2) {
					return answer[i];
				}
			}
		}
	}

	return -1; // 친척 관계가 없다면 -1 반환
}

int main() {
	
	int x, y;

	//입력
	cin >> n;
	cin >> person1 >> person2;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x][y] = graph[y][x] = 1;
	}

	//연산 & 출력
	cout << getRelatives(person1, person2);	

	return 0;
}