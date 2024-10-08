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
			getVirusCom(i); //���ȣ��
		}
	}

	return;
}

int main() {

	int x, y;

	//�Է�
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x][y] = graph[y][x] = 1;
	}

	//����
	visited[FROM] = true;
	getVirusCom(FROM);

	//���
	cout << cnt;

	return 0;
}