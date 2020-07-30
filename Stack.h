#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Stack
{
private:
	int* array;
	int capacity;
	int top;
public:
	Stack(int StackCapacity);
	T& Top();
	void Push(T& item);
	void Pop();
	bool isEmpty();
};

template <typename T>
T& Stack<T>::Top() {
	return array[top];
}

template <typename T>
Stack<T>::Stack(int StackCapacity) :capacity(StackCapacity)
{
	if (capacity < 1)
		cout << "�뷮�� 0���� Ŀ����" << endl;
	array = new int[capacity];
	top = -1;
}

template <typename T>
void Stack<T>::Push(T& item)
{
	if (capacity == top + 1)
	{
		cout << "�����÷ο�" << endl;
	}
	array[++top] = item;
}

template <typename T>
void Stack<T>::Pop()
{
	if (isEmpty())
		cout << "������ �� ���� �� �����ϴ�." << endl;
	else
		top--;
}

template <typename T>
bool Stack<T>::isEmpty()
{
	return array[0] == 0;
}
