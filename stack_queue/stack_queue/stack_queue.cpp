#if 0
#include <iostream>
#include <stack>
using namespace std;

void test_stack()
{
	stack<int> st;
	st.push(1); // 压栈
	st.push(2);
	st.push(3);
	st.push(4);
	st.emplace(5); // C++11
	cout << st.size() << endl;
	// 没有迭代器
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();  // 出栈
	}
	cout << endl;
}

int main()
{
	test_stack();
	return 0;
}
#endif

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void test_queue()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.emplace(5);

	cout << q.size() << endl;
	// queue没有迭代器
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

int main()
{
	test_queue();
	return 0;
}