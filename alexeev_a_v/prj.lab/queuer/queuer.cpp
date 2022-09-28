#include "queuer.h"

QueueR::QueueR() :first_node{ nullptr }, size_q{0} {}
QueueR::~QueueR() { delete first_node; }
void QueueR::push(const int value) {
	size_q++;
	Node* new_node = new Node(value);
	if (first_node == nullptr) {
		new_node->next_node = first_node;
		first_node = new_node;
	}
	else {
		if (empty() || (first_node->value > value)) {
			new_node->next_node = first_node;
			first_node = new_node;
		}
		else {
			Node* n = first_node;
			while ((n->next_node != nullptr) && (n->next_node->value < value)) {
				n = n->next_node;
			}
			new_node->next_node = n->next_node;
			n->next_node = new_node;
		}
	}
};
int QueueR::pop() {
	if (empty()) throw std::out_of_range("ERROR");
	int n_value = first_node->value;
	Node* n_next = first_node->next_node;
	first_node->next_node = nullptr;
	delete first_node;
	first_node = n_next;
	return n_value;
}
QueueR::QueueR(const std::vector<int>& v) {
	for (int i : v) {
		push(i);
	}
}

QueueR::Node::Node(const int n, Node* next) :value{ n }, next_node{ next } {}
QueueR::Node::~Node() { delete next_node; }