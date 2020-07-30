//----------------------------ť-------------------------------
#include <iostream>
using namespace std;

class queue
{
private:
	int *Queue;
	int QSize;
	int head, tail;

public:
	void InitQueue(int size)
	{
		QSize = size;
		Queue = new int[QSize];
		head = 0;
		tail = 0;
	}

	void FreeQueue()
	{
		delete[] Queue;
	}

	bool Insert(int data)
	{
		if ((tail + 1) % QSize == head)
		{
			return false;
		}
		Queue[tail] = data;
		tail = (tail + 1) % QSize;
		return true;
	}

	int Delete()
	{
		int data;
		if (head == tail)
		{
			return -1;
		}
		data = Queue[head];
		head = (head + 1) % QSize;
		return data;
	}
};
#include <iostream>
using namespace std;
#include "queue.h"

int main(){
	Queue<int> S(2);
	S.Push(2);
	S.Push(5);
	S.Push(6);

	cout << S.Front() << endl;
	cout << S.Rear() << endl;

	S.Pop();
	S.Push(7);

	cout << S.Front() << endl;
	cout << S.Rear() << endl;

	return 0;
}