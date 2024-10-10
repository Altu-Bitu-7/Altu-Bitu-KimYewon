#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix; //�ٵ����� ���� 2���� ���� Ÿ�� ����
const int SIZE = 20, EMPTY = 0; //�ٵ��� ����� ����� ����(20, index 1������ ����), ����ִٸ�(= �ٵϾ�x) 0

//���⿡ ���� ��ǥ ������
//�� ���� ���� ��ġ�� �ٵϾ��� �������� �˻��ϱ� ������ ������+�Ʒ������� ���ϴ� ���⸸ ����
const vector<int> dx = { -1, 0, 1, 1 };
const vector<int> dy = { 1, 1, 1, 0 };

//������ �ٵϾ��� ���� ��ȿ���� Ȯ���ϴ� �Լ�
bool isValid(matrix& board, int x, int y, int color) {
    return (x > 0 && x < SIZE && y > 0 && y < SIZE && board[x][y] == color);
}

//�ش� ��ǥ(x, y)���� ���������� 5���� ���̴��� Ȯ���ϴ� �Լ�
bool checkWin(matrix& board, int x, int y) {
    int color = board[x][y]; //Ȯ���ϴ� ��(1 = ��, 2 = ��)

    //���⿡ ���� �˻�
    for (int idx = 0; idx < 4; idx++) {
        int cnt = 1;    //cnt: ���� ���⿡ ���� ���� �� ���� ��
        int prev_x = x - dx[idx], prev_y = y - dy[idx]; //Ž���ϴ� �ݴ� ������ x, y
        int next_x = x + dx[idx], next_y = y + dy[idx]; //Ž���ϴ� ������ x, y

        //���� ���⿡�� �� �������� ���� �� ���� �־��ٸ� �н�(-> ���� �� �̻� ���̴� ��츦 �����ϱ� ���ؼ�)
        if (isValid(board, prev_x, prev_y, color)) {
            continue;
        }

        //���������� ���� 5���� ���� ������ Ȯ��
        while (isValid(board, next_x, next_y, color) && cnt < 6) {
            next_x += dx[idx];
            next_y += dy[idx];
            cnt++; //���� ���̶�� cnt�� �÷���
        }

        //cnt�� 5�� ���� true ��ȯ(-> �ټ� �˺��� ���ų� �ټ� �˺��� ���� ���̴� ��츦 ����)
        if (cnt == 5) {
            return true;
        }
    }
    //�¸����� �ʾ��� ��� false ��ȯ
    return false;
}

int main() {

    matrix board(SIZE, vector<int>(SIZE, 0)); //�ٵ��� ����

    //�Է�
    for (int i = 1; i < SIZE; i++)
        for (int j = 1; j < SIZE; j++)
            cin >> board[i][j]; //�־����� �Է´�� �ٵ��ǿ� �ٵϾ� ����

    //���� & ���
    for (int y = 1; y < SIZE; y++) { //�ٵ��� ���ʷ� ���鼭 Ȯ��
        for (int x = 1; x < SIZE; x++) {
            if (board[x][y] == EMPTY) { //�� ĭ�̸� �н�
                continue;
            }
            if (checkWin(board, x, y)) { //�ش� ��ǥ(x, y)���� ���������� 5���� �����ٸ� ��� ���
                cout << board[x][y] << '\n' //�̱� ���� ���
                    << x << ' ' << y; //���� ���ʿ� �ִ� �ٵϾ� ��ǥ ���
                return 0;
            }
        }
    }
    cout << 0; //Ȯ���� ���������� �¸��� �������� �ʾҴٸ� 0 ���

    return 0;
}