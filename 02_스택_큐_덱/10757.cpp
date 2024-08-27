#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> sumAB(int a, int b) {
	int tmp_a, tmp_b, tmp_sum;
	vector<string> v;

	while (a != 0 && b != 0) {
		tmp_a = a % 1000;
		a = a / 1000;
		tmp_b = b % 1000;
		b = b / 1000;

		tmp_sum = tmp_a + tmp_b;
		v.push_back(to_string(tmp_sum));
	}

	/*for (int i = 0; i < v.size(); i++) {
		v[i] += v[i + 1];
	}

	return v[0];*/
	return v;
}

int main() {

	int a, b;

	//입력
	cin >> a >> b;

	//연산
	vector<string> result = sumAB(a, b);

	//출력
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}

	return 0;
}