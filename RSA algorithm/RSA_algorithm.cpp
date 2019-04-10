#include<iostream>
#include<math.h>
using namespace std;

int gcd(int a, int b) { //�Ҽ����ϱ� ���� �ִ����� ���
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
	cout << "�� �Ҽ� p�� q�� �����Ͻÿ�."<< '\n';
	cin >> p >> q;
	
	N = (p - 1)*(q - 1);

	for (int i = 2; i < 1000000; i++) { //e���ϴ� ����
										//���� �ϱ� ���Ͽ� e�� ���� ���� �Ҽ��� ����.
		if (gcd(N, i) == 1) {
			e = i;
			break;
		}
	}
	for (int i = 2; i < 10000000; i++) {//d���ϴ� ����
		if ((e*i) % N == 1) {
			d = i;
			break;
		}
	}

	cout << "��ȣȭ�� ���ڸ� �Է��Ͻÿ�."<<'\n';
	cin >> M;
	temp = pow(M, e);
	C = temp % (p*q);
	cout << "��ȣȭ : " << C << '\n';

	temp = pow(C, d);
	M = temp % (p*q);
	cout << "��ȣȭ : " << M;
}