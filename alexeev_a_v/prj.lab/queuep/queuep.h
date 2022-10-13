#pragma once
#ifndef QueueP_QueueP_H_20220928
#define QueueP_QueueP_H_20220928

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <memory>

class QueueP {
public:
	class Node {
	public:
		friend class QueueP;
		~Node();
	private:
		Node( const int n);
		int value = 0;
		std::unique_ptr<Node> next = nullptr;
	};
	explicit QueueP(const std::vector<int> & v);
	QueueP();
	~QueueP();
	bool isEmpty() const noexcept;
	void pop() noexcept;
	void push(const int value);
	const int & top() const;

private:
	std::unique_ptr<Node> first_node = nullptr;
};

#endif