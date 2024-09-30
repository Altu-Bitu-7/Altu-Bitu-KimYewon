#include <iostream>
#include <vector>

using namespace std;

void compareSpeed(int& v_tmp, int planet_v) {
	
	int multi = 2;

	if (v_tmp < planet_v * multi) {
		while (v_tmp < planet_v * multi) {
			multi++;
		}
		v_tmp = planet_v * multi;
	}
	else {
		v_tmp = planet_v;
	}
}

int getSpeed(vector<int> planet) {
	
	int v_tmp = planet[0]; //지구에서 올려야 하는 최소 속도를 첫 번째 행성의 최소 속도로 초기화
	int multi = 2; //배수값
	int answer = 0;

	for (int i = 1; i <= planet.size(); i++) { //2번째 값(=1번 인덱스)부터
		if (v_tmp < planet[i]) { //v_tmp가 행성의 최소 속도보다 작으면 v_tmp값을 배수값으로 변경
			while (v_tmp < planet[i]) { //v_tmp가 행성의 최소 속도보다 커질 때까지 배수곱
				v_tmp *= multi;
				multi++;
				answer = v_tmp;
			}
			compareSpeed(v_tmp, planet[i]);
		}
		else { //answer이 행성의 최소 속도보다 크면
			compareSpeed(v_tmp, planet[i]);
		}
	}
}

int main() {

	int n;
	int v;
	vector<int> planet;

	//입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v;
		planet.push_back(v);
	}

	//연산 & 출력
	cout << getSpeed(planet);

	return 0;
}