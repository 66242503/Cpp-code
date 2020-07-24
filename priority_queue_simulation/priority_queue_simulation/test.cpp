#include "priority_queue_simulation.hpp"

using namespace pri_qu;

void test_priority_queue()
{
	// priority_queue<int> pq;

	priority_queue<int, std::vector<int>, greater<int>> pq;
	pq.push(3);
	pq.push(1);
	pq.push(9);
	pq.push(4);
	pq.push(2);

	while (!pq.empty())
	{
		std::cout << pq.top() << " ";
		pq.pop();
	}
	std::cout << std::endl;
}
int main()
{
	test_priority_queue();
	return 0;
}