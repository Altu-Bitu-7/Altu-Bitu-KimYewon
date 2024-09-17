#include <iostream>
#include <vector>

using namespace std;

//첫번째 단어의 알파벳 구성을 vector<int>로 저장
void getFirstWordAlpha(string first_word, vector<int>& first_alphabet) {

	for (int i = 0; i < first_word.length(); i++) {
		first_alphabet[first_word[i] - 'A']++; //단어의 알파벳을 숫자로 변환, 해당 인덱스의 first_alphabet 벡터값을 +1 
	}
}

//첫 단어와 입력으로 들어온 단어가 서로 '비슷한 단어'인지 확인해서 카운트하는 함수
void getSimilarWord(vector<int> first_alphabet, string word, int& cnt) {

	vector<int> alphabet(26, 0); //알파벳의 개수를 셀 벡터
	int different = 0; //차이나는 알파벳의 개수를 셀 변수
	int add_cnt = 0; //각 알파벳 개수 차이가 1개 이하임을 확인하기 위한 변수들(2개 이상이면 비슷한 단어가 될 수 x)
	int sub_cnt = 0;

	for (int i = 0; i < word.length(); i++) {
		alphabet[word[i] - 'A']++; //단어의 알파벳을 숫자로 변환, 해당 인덱스의 alphabet 벡터값을 +1 
	}

	for (int i = 0; i < first_alphabet.size(); i++) {

		int diff_tmp = first_alphabet[i] - alphabet[i];
		if (diff_tmp != 0) { //차이가 있으면
			if (diff_tmp == 1) { //첫 단어의 알파벳보다 하나 적으면
				add_cnt++;
			}
			if (diff_tmp == -1) { //첫 단어의 알파벳보다 하나 많으면
				sub_cnt++;
			}
			different += abs(diff_tmp); //차이나는 개수만큼 더하기
		}
	}

	//1. 차이가 없거나 
	//2. 1개이거나(더하거나 빼서 같아질 수 있음) 
	//3. 2개인데 다른 문자에서 1개씩이면(교체해서 같아질 수 있음)
	if (different == 0 || different == 1 || different == 2 && (add_cnt == 1 && sub_cnt == 1)) {
		cnt++; //비슷한 단어 카운트
	}
}

int main() {

	int n;
	string first_word;
	string word;
	vector<int> first_alphabet(26, 0); //첫 단어의 알파벳의 개수를 셀 벡터
	int cnt = 0; //비슷한 단어의 개수를 셀 변수

	//입력 & 연산
	cin >> n;
	cin >> first_word;
	getFirstWordAlpha(first_word, first_alphabet);

	for (int i = 0; i < n - 1; i++) {
		cin >> word;
		getSimilarWord(first_alphabet, word, cnt);
	}

	//출력
	cout << cnt;

	return 0;
}