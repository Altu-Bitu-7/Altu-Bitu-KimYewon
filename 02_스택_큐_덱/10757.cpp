#include <iostream>
#include <vector>

using namespace std;

int charToint(char ch) { //char -> int 변환 함수
    return (ch - '0'); //char값에서 '0'을 빼면 int형으로 변환됨(*아스키코드)
}

vector<int> calcPlus(string& a, string& b) { //a + b 계산하는 함수. 매개변수에 &를 붙이면 원본을 참조
    int idx_a = a.size() - 1; //a의 일의 자리 인덱스
    int idx_b = b.size() - 1; //b의 일의 자리 인덱스
    bool carry = false; //올림 값(=carry) 처리를 위한 변수
    vector<int> ans; //반환할 최종 결과값

    while (idx_b >= 0) { //b(더 작은 자릿수를 가진 수)의 모든 자릿수의 계산이 끝날 때까지 반복
        int num = charToint(a[idx_a--]) + charToint(b[idx_b--]); //문자를 숫자로 바꾸어 더하고, 인덱스 변경

        num += carry;            //num에 carry 더해주기. (carry는 어차피 1 아니면 0)
        carry = num / 10;        //num의 값이 10 이상이면 carry가 1, 아니면 0
        ans.push_back(num % 10); //올림을 제외한 값만 스택에 push
    }

    //a(더 자릿수가 큰 수)에서 남은 숫자 반영
    while (idx_a >= 0) { //a의 자릿수가 남아있는 동안
        int num = charToint(a[idx_a--]); //남은 숫자를 int로 바꾸어 num에 저장하고, 인덱스 변경

        num += carry; //num에 carry 더해주기
        carry = num / 10; //num의 값이 10 이상이면 carry가 1, 아니면 0
        ans.push_back(num % 10); //올림을 제외한 값만 스택에 push
    }

    //남은 올림 확인
    if (carry) { //carry가 있으면
        ans.push_back(1); //남은 올림 값을 스택에 push
    }

    return ans; //a + b의 최종 결과값 반환
}

int main() {
    ios::sync_with_stdio(0); //입출력 속도 향상 코드
    cin.tie(0);

    string a, b; //큰 수 a, b -> string으로 입력받음(int, long은 연산 시 오버플로우)
    vector<int> ans; //a + b의 결과를 저장할 vector 선언

    //입력
    cin >> a >> b;

    //연산
    if (a.length() < b.length()) { // b의 길이가 더 길다면(a를 더 큰 자릿수를 가진 수로 고정하기 위함)
        swap(a, b); //a와 b를 swap
    }

    ans = calcPlus(a, b); //a + b의 값을 ans 변수에 저장

    //출력
    while (!ans.empty()) { //ans 벡터가 비어있지 않은 동안
        cout << ans.back(); //ans의 뒤에 있는 값부터(제일 큰 자릿수부터 순서대로) 출력
        ans.pop_back(); //출력한 값 pop
    }
}