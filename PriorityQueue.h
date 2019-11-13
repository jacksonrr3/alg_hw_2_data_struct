#pragma once

#include "list.h"
#include "VectorArray.h"

template <typename T>
struct PrNode {
	size_t _priority;
	Queue<T> _queue;
	PrNode(size_t priority):_priority(priority) {}
	~PrNode() = default;
};

template <typename T>
class PriorityQueue {
	VectorArray<PrNode<T>* > _array;

public:
	PriorityQueue() = default;
	~PriorityQueue() = default;

	void enqueue(int priority, T item) {
		for (int i = 0; i < _array.size(); i++) {
			if (_array.get(i)->_priority == priority) {
				_array.get(i)->_queue.enqueue(item);
				return;
			}
			if (_array.get(i)->_priority > priority) {
				PrNode<T>* _new = new PrNode<T>(priority);
				_new->_queue.enqueue(item);
				_array.add(_new, i);
				return;
			}
		}
		PrNode<T>* _new = new PrNode<T>(priority);
		_new->_queue.enqueue(item);
		_array.add(_new);
	}

	T dequeue() {
		if (_array.size() == 0) { return 0; }
		T ret = _array.get(0)->_queue.dequeue();
		if (_array.get(0)->_queue.isEmpty()) {
			_array.remove(0);
		}
		return ret;
	}

	size_t size() const {
		return _array.size();
	};

};
