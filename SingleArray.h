#pragma once

#include "IArray.h"
#include <algorithm>

template <typename T>
class SingleArray: public IArray<T> {
	T* _array;
	size_t _size;
public:

	SingleArray() {
		_size = 0;
		_array = new T[_size];
	};

	~SingleArray() {
		delete[] _array;
	}
	
	size_t size() const override {
		return _size;
	};

	void add(T item) override {
		resize(1);
		_array[_size-1] = item;
	};

	T get(size_t index) const override {
		return _array[index];
	};

	void add(T item, size_t index) {
		T* temp = new T[_size + 1];
		std::copy(_array, _array + index, temp);
		temp[index] = item;
		std::copy(_array + index, _array + _size, temp + index + 1);
		delete[] _array;
		_array = temp;
		++_size;
	};

	T remove(size_t index) { 
		T ret_el = _array[index];
		T* temp = new T[_size - 1];
		std::copy(_array, _array + index, temp);
		std::copy(_array + index + 1, _array + _size, temp + index);
		delete[] _array;
		_array = temp;
		--_size;
		return ret_el; };

private:
	
	void resize(size_t num) override {
		T* temp = new T[_size + num];
		std::copy(_array, _array + _size, temp);
		delete[] _array;
		_array = temp;
		_size += num;
	};
	
};