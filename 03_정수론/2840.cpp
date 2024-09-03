#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

pair<vector<char>, int> luckyWheel(int s, char ch, pair<vector<char>, int>& p) {
	
	int idx = p.second + s; //가리키는 인덱스 저장
	vector<char> result = p.first;

	if (idx >= result.size()) { //인덱스가 벡터의 크기를 넘어가면
		idx %= result.size(); //나머지 연산
	}

	if (result[idx] != '?') { //해당 칸에 이미 값이 있으면
		if (result[idx] != ch) { //다른 글자이면 행운의 바퀴 성립x 이므로 ! 출력(*그 값이 같은 글자이면 그냥 넘어감)
			cout << "!";
			exit(0); //종료
		}
	}
	else {
		result[idx] = ch;
	}

	p.first = result;
	p.second = idx;
	
	return p;
}

//벡터에 중복된 값이 있는지 확인하는 함수(*중복 문자가 존재하면 행운의 바퀴 성립x)
bool hasDuplicates(vector<char>& v) {
	
	unordered_set<char> s; //set 이용

	//벡터의 각 요소를 순회
	for (char ch : v) {

		// '?'는 무시(중복이어도 괜찮음)
		if (ch == '?') {
			continue;
		}

		//값이 이미 set에 존재하는지 확인
		if (s.find(ch) != s.end()) {
			return true; // 중복 값 존재 시 true 반환
		}
		//현재 값을 s에 추가
		s.insert(ch);
	}

	// 모든 요소를 순회한 후 중복이 없으면 false 반환
	return false;
}

int main() {

	int n, k, s;
	char ch;

	//입력 & 연산
	cin >> n >> k;
	vector<char> result(n, '?'); //n개의 칸, ?로 초기화
	pair<vector<char>, int> p;
	p.first = result;
	p.second = 0;

	for (int i = 0; i < k; i++) {
		cin >> s >> ch;
		p = luckyWheel(s, ch, p);
	}

	//출력
	result = p.first;
	int idx = p.second;

	if (hasDuplicates(result)) { //다른 칸인데 중복 글자 존재하는 경우
		cout << "!";
		exit(0);
	}

	while (n--) { //n번동안
		if (idx == result.size()-1) { //인덱스가 제일 끝에 있으면 역순으로 출력(역순 == 시계방향)
			cout << result[idx--];
		}
		else {
			cout << result[idx--];
			if (idx < 0) { //인덱스가 음수가 되면
				idx += result.size(); //맨 끝으로 이동
			}
		}
	}

	return 0;
}