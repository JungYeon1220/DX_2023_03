#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <stack>
#include <deque>

using namespace std;

// Stack
template <typename T, typename Container = vector<T>>
class Stack
{
public:
	void push(const T& value)
	{
		_stack.push_back(value);
	}

	void pop()
	{
		_stack.pop_back();
	}

	const T& top()
	{
		return _stack.back();
	}

	bool empty()
	{
		return _stack.empty();
	}

private:
	Container _stack;

};

int main()
{

	Stack<int, deque<int>> a;
	a.push(3);
	a.push(2);
	a.push(1);
	a.push(0);

	while (true)
	{
		if (a.empty())
			break;

		cout << a.top() << endl;
		a.pop();
	}

	return 0;
}