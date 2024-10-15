#include <iostream>

using namespace std;
const int FROM = 1;

int n, m;
int graph[101][101] = { 0, };
bool visited[101] = { false, };
int answer[101] = { 0, };
int cnt = 0;

//DFS
void getVirusCom(int from) {

	for (int i = 1; i <= n; i++) {
		if (graph[from][i] == 1 && !visited[i]) {
			visited[i] = true;
			cnt++;
			getVirusCom(i); //재귀호출
		}
	}

	return;
}

int main() {

	int x, y;

	//입력
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x][y] = graph[y][x] = 1;
	}

	//연산
	visited[FROM] = true;
	getVirusCom(FROM);

	//출력
	cout << cnt;

	return 0;
}