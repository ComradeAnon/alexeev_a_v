#include "queuep.h"

QueueP::QueueP() {};
QueueP::~QueueP() { };
bool QueueP::isEmpty() const noexcept { return (first_node == nullptr); }
void QueueP::push(const int value) {
	std::unique_ptr<Node> new_node{ new Node(value) };
    if (isEmpty() || ((first_node->value) > value)) {
        (new_node->next) = std::move(first_node);
        first_node = std::move(new_node);
    }
    else {
        auto temp = &first_node;
        while ((((*temp)->next) != nullptr) && (((*temp)->next->value) < value))
            temp = &((*temp)->next);
        (new_node->next) = std::move((*temp)->next);
        ((*temp)->next) = std::move(new_node);
    }
};

void QueueP::pop() {
	if (isEmpty()) throw std::out_of_range("ERROR");
	first_node = std::move(first_node->next);
}
QueueP::QueueP(const std::vector<int>& v) {
	for (int i : v) {
		push(i);
	}
}

const int & QueueP::top() const {
    if (isEmpty()) throw std::out_of_range("No items in queue!");
    return first_node->value;
}

QueueP::Node::Node(const int n) :value{ n } {}
QueueP::Node::~Node() { };