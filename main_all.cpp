#include <iostream>
#include "queue.h"
#include "stack.h"
#include "linkedList.h"
#include "binaryTree.h"
#include <list>
using namespace std;

int main() {
	//****이진트리 예제
	Tree t;
	t.Create();
	t.preorder(t.getRoot());

	//이진트리 예제 끝
	cout << "----------------" << endl;
	//****Linked List Example
	Chain c;
	Chain d;
	int arr[5] = { 2,8,10,20,30 };
	int arr2[8] = { 1,2,3,4,5,6,7,8 };
	c.CreateArr(arr);
	d.CreateArr(arr2);
	cout << c.Length() << endl;
	c.PrintAll();

	c.InsertSort(13);
	c.PrintAll();
	//c.Merge(d);
	
	cout << endl;
	//****End Linked List Example
	cout << "---------------" << endl;
	//****Stack Example
	Stack<int> S(2);
	S.Push(3);
	S.Push(10);
	cout << S.Top() << endl;

	S.Push(4);
	cout << S.Top() << endl;

	S.Pop();
	cout << S.Top() << endl;

	//**** End Stack Example
	cout << "------------" << endl;
	//****Queue Example
	Queue<int> Q(2);

	Q.Push(2);
	Q.Push(5);
	Q.Push(6);
	
	cout << Q.Front() << endl;
	cout << Q.Rear() << endl;
	
	Q.Pop();
	Q.Push(7);

	cout << Q.Front() << endl;
	cout << Q.Rear() << endl;
	//**** End Queue Example
	return 0;
}
