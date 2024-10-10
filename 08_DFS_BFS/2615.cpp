#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix; //바둑판을 받을 2차원 벡터 타입 선언
const int SIZE = 20, EMPTY = 0; //바둑판 사이즈를 상수로 선언(20, index 1번부터 시작), 비어있다면(= 바둑알x) 0

//방향에 따른 좌표 증가량
//맨 왼쪽 위에 위치한 바둑알을 기준으로 검사하기 때문에 오른쪽+아래쪽으로 향하는 방향만 정의
const vector<int> dx = { -1, 0, 1, 1 };
const vector<int> dy = { 1, 1, 1, 0 };

//범위와 바둑알의 색이 유효한지 확인하는 함수
bool isValid(matrix& board, int x, int y, int color) {
    return (x > 0 && x < SIZE && y > 0 && y < SIZE && board[x][y] == color);
}

//해당 좌표(x, y)부터 연속적으로 5알이 놓이는지 확인하는 함수
bool checkWin(matrix& board, int x, int y) {
    int color = board[x][y]; //확인하는 색(1 = 검, 2 = 흰)

    //방향에 대해 검사
    for (int idx = 0; idx < 4; idx++) {
        int cnt = 1;    //cnt: 같은 방향에 놓인 같은 색 돌의 수
        int prev_x = x - dx[idx], prev_y = y - dy[idx]; //탐색하는 반대 방향의 x, y
        int next_x = x + dx[idx], next_y = y + dy[idx]; //탐색하는 방향의 x, y

        //같은 방향에서 그 이전에도 같은 색 돌이 있었다면 패스(-> 여섯 알 이상 놓이는 경우를 제외하기 위해서)
        if (isValid(board, prev_x, prev_y, color)) {
            continue;
        }

        //연속적으로 놓인 5알이 같은 색인지 확인
        while (isValid(board, next_x, next_y, color) && cnt < 6) {
            next_x += dx[idx];
            next_y += dy[idx];
            cnt++; //같은 색이라면 cnt값 플러스
        }

        //cnt가 5일 때만 true 반환(-> 다섯 알보다 적거나 다섯 알보다 많이 놓이는 경우를 제외)
        if (cnt == 5) {
            return true;
        }
    }
    //승리하지 않았을 경우 false 반환
    return false;
}

int main() {

    matrix board(SIZE, vector<int>(SIZE, 0)); //바둑판 선언

    //입력
    for (int i = 1; i < SIZE; i++)
        for (int j = 1; j < SIZE; j++)
            cin >> board[i][j]; //주어지는 입력대로 바둑판에 바둑알 저장

    //연산 & 출력
    for (int y = 1; y < SIZE; y++) { //바둑판 차례로 돌면서 확인
        for (int x = 1; x < SIZE; x++) {
            if (board[x][y] == EMPTY) { //빈 칸이면 패스
                continue;
            }
            if (checkWin(board, x, y)) { //해당 좌표(x, y)부터 연속적으로 5알이 놓였다면 결과 출력
                cout << board[x][y] << '\n' //이긴 색깔 출력
                    << x << ' ' << y; //가장 왼쪽에 있는 바둑알 좌표 출력
                return 0;
            }
        }
    }
    cout << 0; //확인이 끝났음에도 승리가 결정되지 않았다면 0 출력

    return 0;
}