#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

string babbling[4] = { "aya", "ye", "woo", "ma" };
vector<string> result;
vector<bool> visited;

void DFS(int start, string word)
{
	if (word.size() >= 10)
		return;

	string makeWord = word + babbling[start];
	result.push_back(makeWord);
	visited[start] = true;

	for (int i = 0; i < 4; i++)
	{
		if (start == i)
			continue;
		if (visited[i] == true)
			continue;

		DFS(i, makeWord);
	}

	visited[start] = false;
}

//unordered_map<string, bool> visited;
//void DFS(string a, string t)
//{
//	t += a;
//	result.push_back(t);
//	visited[a] = true;
//
//	for (string s : babbling)
//	{
//		if (visited[s] == true)
//			continue;
//
//		DFS(s, t);
//	}
//
//	visited[a] = false;
//}

int main()
{
	//for (string s : babbling)
	//	visited.emplace(s, false);

	for (int i = 0; i < 4; i++)
	{
		visited = vector<bool>(4, false);
		DFS(i, "");
	}

	return 0;
}