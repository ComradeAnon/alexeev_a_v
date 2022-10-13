#include <queuep/queuep.h>
int main() {
	int a = 5, b = 3;
	auto v = std::make_unique<int>(a);
	std::cout << *v;
}