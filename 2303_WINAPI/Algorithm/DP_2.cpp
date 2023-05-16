#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ENCHANT
// 0강에서 부터 시작

// +1
// +2
// +3

// n강을 할 때 강화하는 모든 경우의 수

vector<int> cache = vector<int>(100, -1);

int Enchant(int n)
{
	if (n == 1)
		return 1;

	if (n == 2)
		return 2;

	if (n == 3)
		return 4;

	if (cache[n] != -1)
		return cache[n];

	return cache[n] = Enchant(n - 3) + Enchant(n - 2) + Enchant(n - 1);
}

int main()
{
	cout << Enchant(6) << endl;
	cout << Enchant(10) << endl;

	return 0;
}