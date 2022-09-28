#include <queuep/queuep.h>
int main() {
	std::vector<int> v{ 1, 2, 4, 3 };
	QueueP q(v);
	std::cout << q.pop() << " ";
	std::cout << q.pop() << " ";
	std::cout << q.pop() << " ";
	std::cout << q.pop();
}