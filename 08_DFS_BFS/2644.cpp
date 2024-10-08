#include <iostream>
#include <queue>

using namespace std;

int n, m;
int person1, person2;

int graph[101][101] = { 0, }; //�׷��� �迭
bool visited[101] = { false, }; //�湮 �迭
int answer[101] = { 0, };
int idx = 1;

//BFS
int getRelatives(int person1, int person2) {

	queue<int> q;
	q.push(person1);
	visited[person1] = true;
	answer[person1] = 0; // �������� �̼��� 0

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (graph[now][i] == 1 && !visited[i]) {
				visited[i] = true;
				answer[i] = answer[now] + 1; // �̼�(�Ÿ�) ����
				q.push(i);

				// person2�� ã���� �̼��� ��ȯ
				if (i == person2) {
					return answer[i];
				}
			}
		}
	}

	return -1; // ģô ���谡 ���ٸ� -1 ��ȯ
}

int main() {
	
	int x, y;

	//�Է�
	cin >> n;
	cin >> person1 >> person2;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x][y] = graph[y][x] = 1;
	}

	//���� & ���
	cout << getRelatives(person1, person2);	

	return 0;
}