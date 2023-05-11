#include <iostream>
#include <vector>

using namespace std;

int n = 50;
vector<bool> isPrime = vector<bool>(51, true);

void eratosthenes()
{
	isPrime[0] = false;
	isPrime[1] = false;
	int sqrtN = sqrt(n);

	for (int i = 2; i <= sqrtN; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= n; j += i)
			{
				isPrime[i] = false;
			}
		}
	}
}

int main()
{

	return 0;
}