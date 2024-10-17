#include <deque>
#include <iostream>

using namespace std;

struct info { //�������� �κ� ���� ���θ� struct���� ����
    int power; //������ ����
    bool is_on; //�κ��� ���� ���� ����
};

//��Ʈ�� �� ĭ ȸ����Ű�� �Լ�
void rotateBelt(deque<info>& belt, int n) {
    belt.push_front(belt.back()); //���� ������ ���Ҹ� ���� �տ� ������ ȸ���� �Ͱ� ����
    belt.pop_back(); //���� ������ ���� ����
    belt[n - 1].is_on = false; //�κ��� ������ ��ġ(n-1)���� ������ ����
}

//�κ��� �� ĭ �̵���Ű�� �Լ�
void moveRobot(deque<info>& belt, int n) {
    for (int i = n - 2; i >= 0; i--) { //0 ~ n-2������ üũ�ϸ� ��(n-1�� ������ ��ġ)
        if (!belt[i].is_on) { //�ش� ĭ�� �κ��� ������ ��������
            continue;
        }

        //�ش� ĭ�� �κ��� ���� ��
        if (!belt[i + 1].is_on && (belt[i + 1].power >= 1)) { //���� ĭ�� �κ��� ����, �������� 1 �̻� ���� �ִٸ� �̵�
            belt[i].is_on = false; //���� �ִ� ĭ���� �̵��ϹǷ� false�� üũ
            belt[i + 1].is_on = true; //�̵��� ĭ(���� ĭ) true�� üũ
            belt[i + 1].power--; //�̵��� ĭ(���� ĭ) ������ 1 ����
        }

        belt[n - 1].is_on = false; //�κ��� ������ ��ġ(n-1)�̸� ������ ����
    }
}

//�ø��� ĭ�� �κ��� �ø��� �Լ�
void putRobot(deque<info>& belt) {
    if (!belt[0].is_on && belt[0].power >= 1) { //�ø��� ĭ(0)�� �κ��� ����, �������� 1 �̻� ���� �ִٸ� �κ��� ���� �ø�
        belt[0].is_on = true; //�ø��� ĭ(0) true�� üũ
        belt[0].power--; //�ø��� ĭ(0) ������ 1 ����
    }
}

//��Ʈ�� �������� üũ�ϴ� �Լ�
bool checkFinish(deque<info>& belt, int n, int k) {
    int count = 0; //count�� 0���� �ʱ�ȭ

    for (int i = 0; i < 2 * n; i++) { //0���� 2n-1���� ��Ʈ ��ü�� ���鼭
        if (belt[i].power == 0) { //�ش� ĭ�� �������� 0�̸�
            count++; //count�� +1
        }
    }

    return count >= k; //count���� �־��� k�� �̻��̸� true ��ȯ
}

//1 ~ 3�� ������ �����ϰ�, ������ ����Ǿ��� �� ���� ���̾��� �ܰ踦 ��ȯ�ϴ� �Լ�
int solution(deque<info>& belt, int n, int k) {
    int step = 1; //step�� 1�� �ʱ�ȭ
    while (true) { //if���� �ɸ� ������ �ݺ�
        //��Ʈ ȸ����Ű��
        rotateBelt(belt, n);
        //�κ� �̵���Ű��
        moveRobot(belt, n);
        //�κ� �ø���
        putRobot(belt);

        //��Ʈ ������ üũ�ϱ�
        if (checkFinish(belt, n, k)) { //�������� 0�� ĭ�� ������ k�� �̻��̾ true�� ��ȯ�� ���
            return step; //���� ����, �� ���� step�� ��ȯ
        }
        step++; //������ 1 ~ 3������ �Ϸ������Ƿ� step + 1
    }
}

int main() {
    //�Է�
    int n, k;
    cin >> n >> k; //��Ʈ�� ���̿� ���� ����(������ 0�� ĭ�� ���� ����) �Է�
    deque<info> belt(2 * n); //�����̾� ��Ʈ�� �������� �κ� ���� ���� ����
    for (int i = 0; i < 2 * n; i++) {
        cin >> belt[i].power; //2n���� ��Ʈ ������ �Է�
        belt[i].is_on = false; //�κ� ���� ���� false�� �ʱ�ȭ
    }

    //����
    int answer = solution(belt, n, k); //answer�� ������ ����Ǿ��� ���� �ܰ谡 ���

    //���
    cout << answer; //answer ���
}