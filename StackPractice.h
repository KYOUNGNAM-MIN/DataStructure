#pragma once
#include <algorithm>
using namespace std;

template <typename T>
class stack {
private:
	int* array;
	int capacity;
	int top;
public:
	stack(int stackcapacity);
	void push(T item);
	void pop();
	T& Top();
	void ChangeSize1D(T*&, const int, const int);
	bool isEmpty();
};

template <typename T>
void stack<T>::ChangeSize1D(T*& a, const int oldSize, const int newSize)
{
	if (newSize < 0) throw "New length must be >= 0";

	T* temp = new T[newSize];                                  // new array
	int number = min(oldSize, newSize);  // number to copy
	copy(a, a + number, temp);
	delete[] a;                             // deallocate old memory
	a = temp;
}
template <typename T>
stack<T>::stack(int stackcapacity) : capacity(stackcapacity) {
	if (capacity < 1)
		cout << "크키가 1이상이어야 함" << endl;
	else {
		top = -1;
		array = new int[capacity];
	}
}

template <typename T>
T& stack<T>::Top() {
	return array[top];
}

template <typename T>
void stack<T>::push(T item) {
	if (capacity == top + 1) {
		ChangeSize1D(array, capacity, capacity * 2);
		capacity *= 2;
	}
	array[++top] = item;
}

template <typename T>
void stack<T>::pop() {
	if (isEmpty())
		cout << "비어있음" << endl;
	else
		top--;
}

template <typename T>
bool stack<T>::isEmpty() {
	return (top == -1);
}