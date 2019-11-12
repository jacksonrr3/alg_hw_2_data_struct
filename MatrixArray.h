#pragma once
#include "IArray.h"
#include "SingleArray.h"
#include <algorithm>

template <typename T>
class MatrixArray : public IArray<T>
{
	SingleArray<VectorArray<T>* > _array;			 ///массив с данными типа Т
	size_t _size;		 ///размер данных, хранимых в структуре
	size_t _vec;         ///размер векторов

public:
	MatrixArray(size_t vec):_vec(vec) {
		_size = 0;
	}

	~MatrixArray() {
		delete[] _array;
	};

	size_t size() const override {
		return _size;
	};

	T get(size_t index) const override {
		return _array.get(index / _vec)->get(index % _vec);
	};

	void add(T item) override {
		add(item, _size);
	};

	void add(T item, size_t index) override {
		if (_size == _array.size() * _vec)
			_array.add(new VectorArray<T>(_vec));
		int binToIn = index / _vec;
		for (int i = _array.size() - 1; i > binToIn; --i) {
			_array.get(i)->add(_array.get(i - 1)->get(_array.get(i - 1)->size() - 1), 0);
			_array.get(i - 1)->remove(_array.get(i - 1)->size() - 1);
		}
		_array.get(binToIn)->add(item, index % _vec);
		++_size;
	}

	T remove(size_t index) override {
		int binToRem = index / _vec;
		T rem = _array.get(binToRem)->remove(index % _vec);
		for (int i = binToRem + 1; i < _array.size(); ++i) {
			_array.get(i - 1)->add(_array.get(i)->get(0));
			_array.get(i)->remove(0);
		}
		if (_array.get(_array.size() - 1)->size() == 0) {
			_array.remove(_array.size() - 1);
		}
		--_size;
		return rem;
	}

private:
	void resize(size_t num = 0) override {
		_array.add(new VectorArray<T>(_vec));
	};
	   
};
