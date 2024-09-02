#include <iostream>
#include <vector>

using namespace std;

int getGcd(int a, int b) {

	//유클리드 호제법
	while (a) {
		b %= a;
		swap(a, b);
	}

	return b; //최대공약수 반환
}

pair<int, int> sum(int a, int b, int c, int d, int lcm) {

	pair<int, int> p;
	int tmp1 = lcm / b;
	int tmp2 = lcm / d;

	a *= tmp1;
	b *= tmp1;
	c *= tmp2;
	d *= tmp2;

	int num = a + c; //분자

	p.first = num;
	p.second = b; //분모(b == d)

	return p;
}

pair<int, int> calculateIrreFrac(int a, int b, int gcd) {
	pair<int, int> irre_frac;

	a /= gcd; //분자를 최대공약수로 나눔
	b /= gcd; //분모를 최대공약수로 나눔
	irre_frac.first = a; //pair에 저장
	irre_frac.second = b;

	return irre_frac;
}

int main() {

	int a, b, c, d;

	//입력
	cin >> a >> b; //첫번째 수의 분자(분자 < 분모), 분모
	cin >> c >> d; //두번째 수의 분자, 분모

	//연산
	int gcd1 = getGcd(b, d); //분모끼리의 최대공약수
	int lcm = (b * d) / gcd1; //분모끼리의 최소공배수

	pair<int, int> sum_result = sum(a, b, c, d, lcm); //더하기

	int gcd2 = getGcd(sum_result.first, sum_result.second); //더한 값의 분자와 분모의 최대공약수
	pair<int, int> result = calculateIrreFrac(sum_result.first, sum_result.second, gcd2); //약분

	//출력
	cout << result.first << " " << result.second;

	return 0;
}