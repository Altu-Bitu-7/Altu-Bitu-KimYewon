#include <iostream>
#include <vector>

using namespace std;

int charToint(char ch) { //char -> int ��ȯ �Լ�
    return (ch - '0'); //char������ '0'�� ���� int������ ��ȯ��(*�ƽ�Ű�ڵ�)
}

vector<int> calcPlus(string& a, string& b) { //a + b ����ϴ� �Լ�. �Ű������� &�� ���̸� ������ ����
    int idx_a = a.size() - 1; //a�� ���� �ڸ� �ε���
    int idx_b = b.size() - 1; //b�� ���� �ڸ� �ε���
    bool carry = false; //�ø� ��(=carry) ó���� ���� ����
    vector<int> ans; //��ȯ�� ���� �����

    while (idx_b >= 0) { //b(�� ���� �ڸ����� ���� ��)�� ��� �ڸ����� ����� ���� ������ �ݺ�
        int num = charToint(a[idx_a--]) + charToint(b[idx_b--]); //���ڸ� ���ڷ� �ٲپ� ���ϰ�, �ε��� ����

        num += carry;            //num�� carry �����ֱ�. (carry�� ������ 1 �ƴϸ� 0)
        carry = num / 10;        //num�� ���� 10 �̻��̸� carry�� 1, �ƴϸ� 0
        ans.push_back(num % 10); //�ø��� ������ ���� ���ÿ� push
    }

    //a(�� �ڸ����� ū ��)���� ���� ���� �ݿ�
    while (idx_a >= 0) { //a�� �ڸ����� �����ִ� ����
        int num = charToint(a[idx_a--]); //���� ���ڸ� int�� �ٲپ� num�� �����ϰ�, �ε��� ����

        num += carry; //num�� carry �����ֱ�
        carry = num / 10; //num�� ���� 10 �̻��̸� carry�� 1, �ƴϸ� 0
        ans.push_back(num % 10); //�ø��� ������ ���� ���ÿ� push
    }

    //���� �ø� Ȯ��
    if (carry) { //carry�� ������
        ans.push_back(1); //���� �ø� ���� ���ÿ� push
    }

    return ans; //a + b�� ���� ����� ��ȯ
}

int main() {
    ios::sync_with_stdio(0); //����� �ӵ� ��� �ڵ�
    cin.tie(0);

    string a, b; //ū �� a, b -> string���� �Է¹���(int, long�� ���� �� �����÷ο�)
    vector<int> ans; //a + b�� ����� ������ vector ����

    //�Է�
    cin >> a >> b;

    //����
    if (a.length() < b.length()) { // b�� ���̰� �� ��ٸ�(a�� �� ū �ڸ����� ���� ���� �����ϱ� ����)
        swap(a, b); //a�� b�� swap
    }

    ans = calcPlus(a, b); //a + b�� ���� ans ������ ����

    //���
    while (!ans.empty()) { //ans ���Ͱ� ������� ���� ����
        cout << ans.back(); //ans�� �ڿ� �ִ� ������(���� ū �ڸ������� �������) ���
        ans.pop_back(); //����� �� pop
    }
}