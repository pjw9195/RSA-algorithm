#include<iostream>
#include<math.h>
using namespace std;

int gcd(int a, int b) { //소수구하기 위한 최대공약수 계산
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}

int main() {
	int p, q, e, d, N, M;
	long long C,temp;
	cout << "두 소수 p와 q를 설정하시오."<< '\n';
	cin >> p >> q;
	
	N = (p - 1)*(q - 1);

	for (int i = 2; i < 1000000; i++) { //e구하는 과정
										//쉽게 하기 위하여 e는 가장 작은 소수로 정함.
		if (gcd(N, i) == 1) {
			e = i;
			break;
		}
	}
	for (int i = 2; i < 10000000; i++) {//d구하는 과정
		if ((e*i) % N == 1) {
			d = i;
			break;
		}
	}

	cout << "암호화할 숫자를 입력하시오."<<'\n';
	cin >> M;
	temp = pow(M, e);
	C = temp % (p*q);
	cout << "암호화 : " << C << '\n';

	temp = pow(C, d);
	M = temp % (p*q);
	cout << "복호화 : " << M;
}