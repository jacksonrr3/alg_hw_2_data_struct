#pragma once

template <typename T>
struct Node {
	T _item;
	Node* _next;
	
	Node(const T& item) {
		_next = nullptr;
		_item = item;
	}

	Node(const T item, Node<T>* next) {
		_next = next;
		_item = item;
	}
	   
	~Node() {}

	T getItem() const {
		return _item;
	}

	Node<T>* getNext() {
		return _next;
	}

	void setNext(Node<T>* next) {
		_next = next;
	}

	//friend class Queue;
};


template <typename T>
class Queue {
	Node<T>* _head;
	Node<T>* _tail;

public:
	Queue() {
		_head = nullptr;
		_tail = nullptr;
	}

	bool isEmpty() const {
		return _head == nullptr;
	}

	Node<T>* getHead() const {
		return _head;
	}

	void enqueue(const T& item) {
		Node<T>* node = new Node<T>(item);
		if (isEmpty()) {
			_head = node;
			_tail = node;
		}
		else {
			_tail->setNext(node);
			_tail = node;
		}
	}

	T dequeue() {
		if (isEmpty()) return 0;
		T item = _head->getItem();
		Node<T>* temp_head = _head;
		_head = _head->getNext();
		delete temp_head;
		return item;
	}

};

