#include <iostream>
#include <utility>

using namespace std;

typedef pair<char, char> cc; //pair<char, char> 타입을 많이 쓰므로 선언

//king을 움직인 후의 king과 돌의 위치를 구하는 함수
cc movePos(char ch, char num, string k_move) {

	cc pos;

	if (k_move.find("R") != string::npos) { //k_move 문자열에 "R"이 포함되어 있으면
		ch++; //문자 + 1
	}
	if (k_move.find("L") != string::npos) { //k_move 문자열에 "L"이 포함되어 있으면
		ch--; //문자 - 1
	}
	if (k_move.find("B") != string::npos) { //k_move 문자열에 "B"가 포함되어 있으면
		num--; //숫자 - 1
	}
	if (k_move.find("T") != string::npos) { //k_move 문자열에 "T"가 포함되어 있으면
		num++; //숫자 + 1
	}

	pos.first = ch;
	pos.second = num;
	return pos;
}

//king과 돌의 위치가 같아지는지 체크하는 함수
bool isSamePos(cc k_tmp, cc s_pos) {
	if (k_tmp.first == s_pos.first && k_tmp.second == s_pos.second) { //king과 돌의 위치가 같으면 true 반환
		return true;
	}
	return false;
}

//king과 돌의 위치가 범위(A~H, 1~8)를 벗어나는지 체크하는 함수
bool checkPos(cc pos) {
	if (pos.first >= 'A' && pos.first <= 'H' && pos.second >= '1' && pos.second <= '8') { //범위 안에 정상적으로 있으면 true 반환
		return true;
	}
	return false;
}

int main() {

	string king, stone;
	int n;
	string k_move;
	cc k_pos, s_pos;
	cc k_tmp, s_tmp;

	//입력 & 연산
	cin >> king >> stone >> n;

	k_pos.first = king[0];
	k_pos.second = king[1];
	s_pos.first = stone[0];
	s_pos.second = stone[1];

	for (int i = 0; i < n; i++) {
		cin >> k_move;
		k_tmp = movePos(k_pos.first, k_pos.second, k_move);
		if (isSamePos(k_tmp, s_pos)) { //이동한 king의 위치와 돌의 위치가 같으면 돌 이동
			s_tmp = movePos(s_pos.first, s_pos.second, k_move);
			if (checkPos(k_tmp)) { //이동한 king의 위치와 돌의 위치가 범위 안에 있으면
				if (checkPos(s_tmp)) {
					k_pos = k_tmp; //이동 업데이트
					s_pos = s_tmp;
				}
			}
		}
		else {
			if (checkPos(k_tmp)) { //이동한 king의 위치가 범위 안에 있으면(돌 이동x)
				k_pos = k_tmp; //이동 업데이트
			}
		}
	}

	//출력
	cout << k_pos.first << k_pos.second << "\n";
	cout << s_pos.first << s_pos.second;

	return 0;
}