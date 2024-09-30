#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//이긴 사람 결정
string winner(deque<int>& do_dec, deque<int>& su_dec) {

	int do_dec_size = do_dec.size();
	int su_dec_size = su_dec.size();

	if (do_dec_size > su_dec_size) {
		return "do";
	}
	else if (su_dec_size > do_dec_size) {
		return "su";
	}
	else { //카드의 개수가 같으면
		return "dosu";
	}
}

//그라운드의 카드를 덱에 합치는 함수
void mergeCard(deque<int>& dec, deque<int>& ground) {
	while (!ground.empty()) {
		dec.push_back(ground.back()); //그라운드의 카드 더미를 뒤집어서 합침
		ground.pop_back();
	}
}

//종을 치는 함수(종 친 횟수 카운트)
void ringABell(string who, deque<int>& do_dec, deque<int>& su_dec, deque<int>& do_ground, deque<int>& su_ground) {

	if (who == "do") { //가장 위에 위치한 카드의 숫자가 5가 나오면 도도 종
		mergeCard(do_dec, su_ground); //상대 그라운드의 카드 더미를 덱에 합침
		mergeCard(do_dec, do_ground); //본인 그라운드의 카드 더미를 덱에 합침
	} 
	else if (who == "su") { //가장 위에 위치한 카드의 숫자의 합이 5가 되면 수연이 종
		mergeCard(su_dec, do_ground);
		mergeCard(su_dec, su_ground);
	}
}

//종을 칠 수 있는 사람 찾는 함수
string canRing(deque<int>& do_ground, deque<int>& su_ground){

	if (!do_ground.empty() && do_ground.front() == 5) {
		return "do";
	}
	if (!su_ground.empty() && su_ground.front() == 5) {
		return "do";
	}
	if (!do_ground.empty() && !su_ground.empty() && do_ground.front() + su_ground.front() == 5) {
		return "su";
	}
	return "can't";
}

string playHalliGalli(deque<int>& do_dec, deque<int>& su_dec, int m) {
	
	deque<int> do_ground, su_ground;
	bool turn = 0; //turn: 0이면 도도 턴, 1이면 수연이 턴

	while (m--) { //m번의 게임 진행
		if (turn == 0) { //도도 턴이면
			do_ground.push_front(do_dec.front()); //도도가 그라운드에 맨 위 카드를 내려놓음
			do_dec.pop_front();
		}
		else { //수연이 턴이면
			su_ground.push_front(su_dec.front()); //수연이가 그라운드에 맨 위 카드를 내려놓음
			su_dec.pop_front();
		}

		if (do_dec.empty() || su_dec.empty()) { //한 사람이라도 덱의 카드 수가 0이면 종료
			break;
		}

		string who = canRing(do_ground, su_ground);
		if (who != "can't") {
			ringABell(who, do_dec, su_dec, do_ground, su_ground);
		}

		// 턴 교체
		turn = 1 - turn;

	}
	return winner(do_dec, su_dec);
}

int main() {

	int n, m;
	int do_num, su_num;
	deque<int> do_dec, su_dec;

	//입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> do_num >> su_num;
		do_dec.push_front(do_num);
		su_dec.push_front(su_num);
	}

	//연산 & 출력
	cout << playHalliGalli(do_dec, su_dec, m);

	return 0;
}