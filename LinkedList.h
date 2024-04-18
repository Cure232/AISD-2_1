#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class LinkedList {
protected:
	struct Node {
		Node* next;
		Node* prev;
		T data;

		Node(const T& _data, Node* _prev = nullptr, Node* _next = nullptr) {
			data = _data;
			prev = _prev;
			next = _next;
		}
	};

private:
	int length = 0;
	Node* head_ptr = nullptr;
	Node* tail_ptr = nullptr;

public:

	int get_length() const {
		return length;
	}

	LinkedList() {

	}

	LinkedList(const LinkedList& ll) {
		length = ll.length;
		push_tail(ll);
	}

	LinkedList& operator=(const LinkedList& rhs) {
		if (this == &rhs) {
			return *this;
		}

		~this();
		this->push_tail(rhs);

		return *this;
	}

	~LinkedList() {
		if (length > 0) {
			Node* iter_ptr = this->head_ptr;
			Node* next_node;
			for (next_node = iter_ptr->next; iter_ptr != this->tail_ptr; next_node = iter_ptr->next) {
				delete(iter_ptr);
				iter_ptr = next_node;
			}
			delete(iter_ptr);
		}
		tail_ptr = nullptr;
		head_ptr = nullptr;
		length = 0;
	}

	void push_tail(const T& item) {
		this->length += 1;
		Node* node = new Node(item);

		if (tail_ptr != nullptr) {
			tail_ptr->next = node;
			node->prev = tail_ptr;
			tail_ptr = node;
		}
		else {
			tail_ptr = node;
			head_ptr = node;
		}
	}

	void push_tail(const LinkedList& list) {
		if (list.length > 0) {
			Node* iter_ptr;
			for (iter_ptr = list.head_ptr; iter_ptr != list.tail_ptr; iter_ptr = iter_ptr->next) {
				this->push_tail(iter_ptr->data);
			}
			this->push_tail(iter_ptr->data);
		}
	}

	void push_head(const T& item) {
		this->length += 1;
		Node* node = new Node(item);

		if (head_ptr != nullptr) {
			head_ptr->prev = node;
			node->next = head_ptr;
			head_ptr = node;
		}
		else {
			tail_ptr = node;
			head_ptr = node;
		}
	}

	void push_head(const LinkedList& list) {
		if (list.length > 0) {
			Node* iter_ptr;
			for (iter_ptr = list.head_ptr; iter_ptr != list.tail_ptr; iter_ptr = iter_ptr->next) {
				this->push_head(iter_ptr->data);
			}
			this->push_head(iter_ptr->data);
		}
	}

	T pop_head() {
		if (head_ptr != nullptr) {
			T content = head_ptr->data;
			
			if (length > 1) {
				head_ptr = head_ptr->next;
				delete(head_ptr->prev);
				head_ptr->prev = nullptr;
			}
			else {
				delete(this);
				head_ptr = nullptr;
				tail_ptr = nullptr;
			}
			this->length -= 1;
			return content;
		}
		else throw runtime_error("slkdgjos;ag");
	}

	T pop_tail() {
		if (tail_ptr != nullptr) {
			T content = tail_ptr->data;

			if (length > 1) {
				tail_ptr = tail_ptr->prev;
				delete(tail_ptr->next);
				tail_ptr->next = nullptr;
			}
			else {
				delete(tail_ptr);
				head_ptr = nullptr;
				tail_ptr = nullptr;
			}
			this->length -= 1;
			return content;
		}
		else throw runtime_error("dfsgfd");
	}

	void delete_node(const T& to_delete) {
		Node* iter_ptr = head_ptr;
		Node* next_node;
		Node* prev_node;
		while (iter_ptr != nullptr && length > 0) {
			next_node = iter_ptr->next;
			prev_node = iter_ptr->prev;
			if (iter_ptr->data == to_delete) {

				if (next_node != nullptr) {
					next_node->prev = iter_ptr->prev;
				}
				if (prev_node != nullptr) {
					prev_node->next = iter_ptr->next;
				}

				if (iter_ptr == this->head_ptr) {
					head_ptr = next_node;
				}
				if (iter_ptr == this->tail_ptr) {
					head_ptr = prev_node;
				}

				delete(iter_ptr);
				length -= 1;
			}
			iter_ptr = next_node;
		}
	}

	T operator[](const int& i) const {
		if (i >= 0 && i < length) {
			Node* iter_ptr = this->head_ptr;
			for (int j = 0; j < i; j++) {
				iter_ptr = iter_ptr->next;
			}
			return iter_ptr->data;
		}
		else throw out_of_range("sd");
	}

	T& operator[](const int& i) {
		if (i >= 0 && i < length) {
			Node* iter_ptr = this->head_ptr;
			for (int j = 0; j < i; j++) {
				iter_ptr = iter_ptr->next;
			}
			return (iter_ptr->data);
		}
		else throw runtime_error("bs");
	}
};