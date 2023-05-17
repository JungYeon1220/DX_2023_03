#include <iostream>
#include <vector>

using namespace std;

// 잠조 무결성 함수
// 입력값이 같을 때 무조건 같은 값이 나와야한다.

// LIS (최장 부분 증가 수열 찾기)
// Longest Increasing SubSequence

// 부분 수열 : 인접에 상관 없이 순서에 맞는 부분 수열
// {1, 2, 8, 5, 3, 7, 10} v
// {1, 2, 8} 부분 수열 (O)
// {1, 5, 7} 부분 수열 (O)
// {5, 1, 2, 8, 7} 부분 수열 (X)

// 부분 증가 수열 : 부분 수열이면서 수열이 증가하는 형태를 띄는 수열
// { 1, 2, 8 } O
// { 1, 8, 3, 7 } X

// 퇴장 부분 증가 수열 : 부분 증가 수열 중에 제일 긴 것
// { 1, 2, 5, 7, 10 }
// { 1, 2, 3, 7, 10 }

vector<int> cache = vector<int>(100, -1);

int LIS(vector<int>& v, int n)
{
	if (n == v.size() - 1)
		return 1;

	int& ref = cache[n];
	if (ref != -1)
		return ref;

	ref = 1;
	for (int i = n + 1; i < v.size(); i++)
	{
		if (v[n] < v[i])
		{
			ref = max(ref, LIS(v, i) + 1);
		}
	}

	return ref;
}

int LIS_ALL(vector<int>& v, int n)
{
	cache = vector<int>(100, -1);

	int result = 0;
	for (int i = n; i < v.size(); i++)
	{
		result = max(result, LIS(v, i));
	}

	return result;
}

int main()
{
	vector<int> v0 = { 5, 1, 3 };
	vector<int> v1 = { 1, 2, 8, 5, 3, 7, 10 };
	vector<int> v2 = { 5, 6, 7, 8, 1, 2, 3 };

	cout << LIS_ALL(v1, 0) << endl;

	return 0;
}