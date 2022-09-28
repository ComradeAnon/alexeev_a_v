#pragma once
#ifndef QueueR_QueueR_H_20220915
#define QueueR_QueueR_H_20220915

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

class QueueR {
public:
	class Node {
	public:
		friend class QueueR;
		~Node();
	private:
		Node( const int n, Node* next = nullptr);
		int value = 0;
		Node* next_node{ nullptr };
	};
	explicit QueueR(const std::vector<int> & v);
	QueueR();
	~QueueR();
	bool empty() { return size_q == 0; }
	int pop();
	void push(const int value);
	size_t size() { return size_q; }
	const Node* top() { return first_node; };

private:
	Node* first_node{ nullptr };
	size_t size_q = 0;
};

#endif