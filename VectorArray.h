#pragma once
#include "IArray.h"
#include <algorithm>

template <typename T>
class VectorArray :	public IArray<T>
{
	T* _array;			 ///ìàññèâ ñ äàííûìè òèïà Ò
	size_t _size;		 ///ðàçìåð äàííûõ, çðàíèïìûõ â ñòðóêòóðå
	const size_t _vec=100;   ///øàã óâåëè÷åíèÿ ïàìÿòè
	size_t _alloc;		 ///ðàçìåð àëëîöèðîâàííîãî ïðîñòàíñòâà ïàìÿòè, óâåëè÷èâàåòñÿ íà ðàçìåð _vec

public:
	VectorArray() {
		_size = 0;
		_array = new T[_size];
		_alloc = 0;
	};

	VectorArray(size_t vec):_vec(vec) {
		_size = 0;
		_array = new T[vec];
		_alloc = vec;
	};

	~VectorArray() {
		delete[] _array;
	};

	size_t size() const override {
		return _size;
	};

	void add(T item) override {
		if (_alloc == _size) {
			resize(_vec);
		}
		_array[_size] = item;
		++_size;
	};

	T get(size_t index) const override {
		return _array[index];
	};

	void add(T item, size_t index) {
		if (_alloc == _size) {
			resize(_vec);
		}
		std::move_backward(_array + index, _array + _size, _array + _size + 1);
		_array[index] = item;
		++_size;
	};

	T remove(size_t index) {
		T rem = _array[index];
		std::move(_array + index + 1, _array + _size, _array + index);
		--_size;
		return rem;
	};


private:

	void resize(size_t num) override {
		T* temp = new T[_alloc + num];
		std::copy(_array, _array + _size, temp);
		delete[] _array;
		_array = temp;
		_alloc += num;
	};

};

