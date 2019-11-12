#pragma once
#include "IArray.h"
#include <algorithm>

template <typename T>
class FactorArray : public IArray<T>
{
	T* _array;			 ///массив с данными типа Т
	size_t _size;		 ///размер данных, зранипмых в структуре
	size_t _fac = 2;         ///шаг увеличения памяти
	size_t _alloc;

public:
	FactorArray(size_t fac) {
		_size = 0;
		_fac = fac;
		_alloc = 1;
		_array = new T[_alloc];
	};


	//FactorArray(size_t fac) :_fac(fac), _array(new T[fac]), _alloc(fac) {};

	~FactorArray() {
		delete[] _array;
	};

	size_t size() const override {
		return _size;
	};

	void add(T item) override {
		if (_alloc == _size) {
			
			resize(_alloc * _fac);
		}
		_array[_size] = item;
		++_size;
	};

	T get(size_t index) const override {
		return _array[index];
	};

	void add(T item, size_t index) {
		if (_alloc == _size) {
			//_fac *= 2;
			resize(_alloc * _fac);
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
		T* temp = new T[num];
		std::copy(_array, _array + _size, temp);
		delete[] _array;
		_array = temp;
		_alloc = num;
	};


};