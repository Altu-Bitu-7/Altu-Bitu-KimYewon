#include <deque>
#include <iostream>

using namespace std;

struct info { //내구도와 로봇 존재 여부를 struct으로 관리
    int power; //내구도 변수
    bool is_on; //로봇의 존재 여부 변수
};

//벨트를 한 칸 회전시키는 함수
void rotateBelt(deque<info>& belt, int n) {
    belt.push_front(belt.back()); //가장 마지막 원소를 가장 앞에 놓으면 회전한 것과 같음
    belt.pop_back(); //가장 마지막 원소 삭제
    belt[n - 1].is_on = false; //로봇이 내리는 위치(n-1)에서 무조건 내림
}

//로봇을 한 칸 이동시키는 함수
void moveRobot(deque<info>& belt, int n) {
    for (int i = n - 2; i >= 0; i--) { //0 ~ n-2까지만 체크하면 됨(n-1은 내리는 위치)
        if (!belt[i].is_on) { //해당 칸에 로봇이 없으면 다음으로
            continue;
        }

        //해당 칸에 로봇이 있을 때
        if (!belt[i + 1].is_on && (belt[i + 1].power >= 1)) { //다음 칸에 로봇이 없고, 내구도가 1 이상 남아 있다면 이동
            belt[i].is_on = false; //원래 있던 칸에서 이동하므로 false로 체크
            belt[i + 1].is_on = true; //이동할 칸(다음 칸) true로 체크
            belt[i + 1].power--; //이동할 칸(다음 칸) 내구도 1 감소
        }

        belt[n - 1].is_on = false; //로봇이 내리는 위치(n-1)이면 무조건 내림
    }
}

//올리는 칸에 로봇을 올리는 함수
void putRobot(deque<info>& belt) {
    if (!belt[0].is_on && belt[0].power >= 1) { //올리는 칸(0)에 로봇이 없고, 내구도가 1 이상 남아 있다면 로봇을 새로 올림
        belt[0].is_on = true; //올리는 칸(0) true로 체크
        belt[0].power--; //올리는 칸(0) 내구도 1 감소
    }
}

//벨트의 내구도를 체크하는 함수
bool checkFinish(deque<info>& belt, int n, int k) {
    int count = 0; //count를 0으로 초기화

    for (int i = 0; i < 2 * n; i++) { //0부터 2n-1까지 벨트 전체를 돌면서
        if (belt[i].power == 0) { //해당 칸의 내구도가 0이면
            count++; //count값 +1
        }
    }

    return count >= k; //count값이 주어진 k개 이상이면 true 반환
}

//1 ~ 3번 과정을 진행하고, 과정이 종료되었을 때 진행 중이었던 단계를 반환하는 함수
int solution(deque<info>& belt, int n, int k) {
    int step = 1; //step을 1로 초기화
    while (true) { //if문에 걸릴 때까지 반복
        //벨트 회전시키기
        rotateBelt(belt, n);
        //로봇 이동시키기
        moveRobot(belt, n);
        //로봇 올리기
        putRobot(belt);

        //벨트 내구도 체크하기
        if (checkFinish(belt, n, k)) { //내구도가 0인 칸의 개수가 k개 이상이어서 true가 반환된 경우
            return step; //과정 종료, 그 때의 step을 반환
        }
        step++; //문제의 1 ~ 3번까지 완료했으므로 step + 1
    }
}

int main() {
    //입력
    int n, k;
    cin >> n >> k; //벨트의 길이와 종료 조건(내구도 0인 칸의 개수 조건) 입력
    deque<info> belt(2 * n); //컨베이어 벨트의 내구도와 로봇 존재 여부 저장
    for (int i = 0; i < 2 * n; i++) {
        cin >> belt[i].power; //2n개의 벨트 내구도 입력
        belt[i].is_on = false; //로봇 존재 여부 false로 초기화
    }

    //연산
    int answer = solution(belt, n, k); //answer에 과정이 종료되었을 때의 단계가 담김

    //출력
    cout << answer; //answer 출력
}