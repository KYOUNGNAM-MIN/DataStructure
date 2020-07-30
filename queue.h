#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class Queue {
public:
	Queue(int queueCapacity = 10);
	// Create an empty queue whose initial capacity is queueCapacity

	bool IsEmpty();
	// If number of elements in the queue is 0, return true else return false.

	T& Front();
	// Return the element at the front of the queue.

	T& Rear();
	// Return the element at the rear of the queue.

	void Push(const T& item);
	// Insert item at the rear of the queue.

	void Pop();
	// Delete the front element of the queue.

private:
	T *queue;           // array for queue elements
	int front,          // one counterclockwise from front
		rear,               // array position of rear element
		capacity;           // capacity of queue array
};

template <class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity)
{
	if (capacity < 1)
		cout << "용량이 0보다 커야함" << endl;
	queue = new T[capacity];
	front = 0;
	rear = 0;
}

template <class T>
bool Queue<T>::IsEmpty() { return front == rear; }

template <class T>
T& Queue<T>::Front()
{
	if (IsEmpty()) throw "비엇음";
	return queue[(front+1) % capacity];
}

template <class T>
T& Queue<T>::Rear()
{
	if (IsEmpty()) throw "비엇음";
	return queue[rear];
}

template <class T>
void Queue<T>::Push(const T& item)
{
	if ((rear + 1) % capacity == front) {
		T* newQueue = new T[2 * capacity];

		int start = (front + 1) % capacity;
		if (start < 2)
			copy(queue + start, queue + start + capacity - 1, newQueue);
		else {
			copy(queue + start, queue + capacity, newQueue);
			copy(queue, queue + rear + 1, newQueue + capacity - start);
		}
		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		delete[] queue;
		queue = newQueue;
	}
	rear = (rear + 1) % capacity;
	queue[rear] = item;
	
}

template <class T>
void Queue<T>::Pop()
{
	queue[++front] = queue[front];

	/*front = (front + 1) % capacity;
	queue[front].~T();*/
}
