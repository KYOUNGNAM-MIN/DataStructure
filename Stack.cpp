//--------------------------스택-------------------------------
#include "Stack.h"
#include <iostream>
using namespace std;
template <typename T>

int main() {
	Stack<int> S(3);
	S.Push(2);
	S.Push(4);
	S.Push(7);
	cout << S.Top() << endl;
	S.Push(9);
	cout << S.Top() << endl;
	S.Pop();
	cout << S.Top() << endl;
	return 0;
}




//----------------------------큐-------------------------------
//#include <iostream>
//using namespace std;
//
//class queue
//{
//private:
//	int *Queue;
//	int QSize;
//	int head, tail;
//
//public:
//	void InitQueue(int size)
//	{
//		QSize = size;
//		Queue = new int[QSize];
//		head = 0;
//		tail = 0;
//	}
//
//	void FreeQueue()
//	{
//		delete[] Queue;
//	}
//
//	bool Insert(int data)
//	{
//		if ((tail + 1) % QSize == head)
//		{
//			return false;
//		}
//		Queue[tail] = data;
//		tail = (tail + 1) % QSize;
//		return true;
//	}
//
//	int Delete()
//	{
//		int data;
//		if (head == tail)
//		{
//			return -1;
//		}
//		data = Queue[head];
//		head = (head + 1) % QSize;
//		return data;
//	}
//};
//void main()
//{
//	queue qu;
//	int i;
//	qu.InitQueue(8);
//	for (i = 1; i <= 7; i++)
//	{
//		qu.Insert(i);
//	}
//	for (i = 1; i <= 7; i++)
//	{
//		cout << qu.Delete() << endl;
//	}//데이터 삭제하면서 출력
//	qu.FreeQueue();
//}
