#include <iostream>

using namespace std;

// 유클리드의 호제법, 알고리즘
// => 최대공약수

// p, q 두 수읠 최대공약수
// 이 때 p > q

// 15 6
// 9 6
// 6 3
// 3 3
// gcd(p, q) == gcd(p - q, q)

int gcd(int p, int q)
{
	if (q == 0) return p;
	return gcd(q, p % q);
}

int main()
{
	cout << gcd(21, 6) << endl;

	return 0;
}