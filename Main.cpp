#include <iostream>
#include <chrono>
#include "SingleArray.h"
#include "VectorArray.h"
#include "FactorArray.h"
#include "MatrixArray.h"
#include "list.h"
#include "PriorityQueue.h"

template <typename T>
void print_array(IArray<T>* array) {
	for (int i = 0; i < (array->size()); i++) {
		std::cout << "Array " << (i) << " - " << array->get(i) << std::endl;
	}
}

template <typename T>
void test_add_Array(IArray<T> * array, size_t number) {
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	for (int i = 0; i < number; i++) {
		array->add(i);
	}
	end = std::chrono::system_clock::now();
	std::cout << "Array add " << number << ": " <<
		std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms."<<std::endl;
}

template <typename T>
void test_remove_ind(IArray<T>* array) {
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	size_t size = array->size();
	for (int i = size-1; i >= 0; i--) {
		array->remove(i);
	}
	end = std::chrono::system_clock::now();
	std::cout << "Array rem: " <<
		std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms." << std::endl;
}

template <typename T>
void test_get_ind(IArray<T>* array) {
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	size_t size = array->size();
	for (int i = 0; i < size; i++) {
		array->get(i);
	}
	end = std::chrono::system_clock::now();
	std::cout << "Array get: " <<
		std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms." << std::endl;
}

template <typename T>
void test_add_first(IArray<T>* array) {
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	size_t size = array->size();
	array->add(123, 0);
	end = std::chrono::system_clock::now();
	std::cout << "Array add_first: " <<
		std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms." << std::endl;
}

template <typename T>
void test_add_ind(IArray<T>* array) {
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	size_t size = array->size();
	array->add(123, 100000);
	end = std::chrono::system_clock::now();
	std::cout << "Array add ind 100000: " <<
		std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms." << std::endl;
}

template <typename T>
void test_rem_first(IArray<T>* array) {
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	size_t size = array->size();
	array->remove(0);
	end = std::chrono::system_clock::now();
	std::cout << "Array remove first: " <<
		std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms." << std::endl;
}

template <typename T>
void test_rem_ind(IArray<T>* array) {
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	size_t size = array->size();
	array->remove(100000);
	end = std::chrono::system_clock::now();
	std::cout << "Array remove index: " <<
		std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms." << std::endl;
}

template <typename T>
void test_add_rem_array(IArray<T>* array) {
	std::cout << "size " << (array->size()) << std::endl;
	std::cout << "get " << (array->get(50)) << std::endl;
	std::cout << "add 1 ind 5" << std::endl;
	array->add(1, 50);
	std::cout << "size " << (array->size()) << std::endl;
	std::cout << "get " << (array->get(50)) << std::endl;

	std::cout << "remove " << (array->remove(50)) << std::endl;
	std::cout << "size " << (array->size()) << std::endl;
	std::cout << "get " << (array->get(50)) << std::endl;
}



int main() {
	
	//создаем объекты структыр данных
	IArray<int>* sa = new SingleArray<int>();
	IArray<int>* va = new VectorArray<int>(200);
	IArray<int>* fa = new FactorArray<int>(2);
	IArray<int>* ma = new MatrixArray<int>(100);
	
	//заполнение данными
	test_add_Array(sa, 205500); //120500 долго.
	test_add_Array(va, 1205500);
	test_add_Array(fa, 1205500);
	test_add_Array(ma, 1205500);
	
	//доступ к кажому элементу по индексу
	test_get_ind(sa);
	test_get_ind(va);
	test_get_ind(fa);
	test_get_ind(ma);
	
	//добавляем первый элемент
	test_add_first(sa);
	test_add_first(va);
	test_add_first(fa);
	test_add_first(ma);

	//добавляем элемент в середину
	test_add_ind(sa);
	test_add_ind(va);
	test_add_ind(fa);
	test_add_ind(ma);

	//удаляем первый элемент	
	test_rem_first(sa);
	test_rem_first(va);
	test_rem_first(fa);
	test_rem_first(ma);

	//удаляем элемент по индексу из середины
	test_rem_ind(sa);
	test_rem_ind(va);
	test_rem_ind(fa);
	test_rem_ind(ma);
	
	//удаляем все элементы начиная с последнего элемента
	test_remove_ind(sa);
	test_remove_ind(va);
	test_remove_ind(fa);
	test_remove_ind(ma);

	//проверка размера
	std::cout << sa->size() << std::endl;
	std::cout << va->size() << std::endl;
	std::cout << fa->size() << std::endl;
	std::cout << ma->size() << std::endl;
	
	//тест для очереди с приоритетом. Добавляем 6 элементов с разным приоритетом. 
	//извлекаем и выводим на экран элементы из очереди в порядке приоритета, убеждаемся, что размер очереди стал 0 после извлечения всех элементов.
	PriorityQueue<int> q;
	q.enqueue(3, 1);
	q.enqueue(3, 2);
	q.enqueue(1, 3);
	q.enqueue(1, 4);
	q.enqueue(2, 5);
	q.enqueue(0, 6);

	std::cout << q.dequeue() << std::endl;
	std::cout << q.dequeue() << std::endl;
	std::cout << q.dequeue() << std::endl;
	std::cout << q.dequeue() << std::endl;
	std::cout << q.dequeue() << std::endl;
	std::cout << q.dequeue() << std::endl;
	std::cout << q.size() << std::endl;

	
	

	return 0;
}
