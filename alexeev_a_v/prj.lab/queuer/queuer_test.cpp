#include <queuer/queuer.h>
int main() {
	std::vector<int> v{ 1, 2, 4, 3 };
	QueueR q(v);
	std::cout << q.pop() << " " << q.pop() << " " << q.pop();
}