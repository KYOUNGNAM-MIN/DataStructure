#include <iostream>
using namespace std;

class Chain;
class ChainNode {
	friend class Chain;
private:
	int data;
	ChainNode* link;
public:
	ChainNode(int element = 0, ChainNode* next = 0) {
		data = element;
		link = next;
	}
};
class Chain {
private:
	ChainNode* first;
public:
	int Length(); // 책163p 1번 노드 개수
	void Create2();
	void Create7();
	void CreateArr(int* arr);
	void PrintAll();
	void Insert50(ChainNode*); // 노드 삽입
	void Delete(ChainNode*, ChainNode*); // 책163p 2번 x 노드 삭제
	void DeleteAlternate(); // 책163p 3번 짝수 노드만 가리키기
							//책163p 4번 
	//Chain Merge(Chain y);	//책163p 5번
	void InsertSort(int k);
	void Reverse();
};
void Chain::Reverse() {
	ChainNode* current = first;
	ChainNode* previous = 0;
	while (current) {
		ChainNode* r = previous;
		previous = current;
		current = current->link;
		previous->link = r;
	}
	first = previous;
}
void Chain::InsertSort(int k) {
	for (ChainNode* i = first; i != 0; i = i->link) {
		if (i->data < k && k<i->link->data) {
			i->link = new ChainNode(k, i->link);
		}
	}
}
int Chain::Length() {
	int count = 0;
	for (ChainNode* i = first; i != 0; i = i->link) {
		count++;
	}
	return count;
}
void Chain::Create2() {
	ChainNode* second = new ChainNode(12, 0);
	first = new ChainNode(1, second);
}
void Chain::Create7() {
	first = new ChainNode(2, 0);
	ChainNode* second = new ChainNode(22, 0);
	first->link = second;
}
void Chain::CreateArr(int* arr) {
	ChainNode* p = 0;
	ChainNode* c = 0;
	for (int i = 0; i < 5; i++) {
		if (i == 0) {
			p = new ChainNode(arr[i], 0);
			first = p;
		}
		else {
			c = new ChainNode(arr[i], 0);
			p->link = c;
			p = c;
		}
	}
}
void Chain::PrintAll() {
	for (ChainNode* i = first; i != 0; i = i->link) {
		cout << i->data << endl;
	}
}
void Chain::Insert50(ChainNode* x) {
	if (first)
		x->link = new ChainNode(50, x->link);
	else
		first = new ChainNode(50);
}
void Chain::Delete(ChainNode* d, ChainNode* pd) {
	if (d == first)
		first = first->link;
	else
		pd->link = d->link;
	delete d;
}
void Chain::DeleteAlternate() {
	if (first) {
		ChainNode* del = first;
		first = first->link;
		delete del;
		for (ChainNode* i = first; i != 0; i = i->link) {
			del = i->link;
			i->link = del->link;
			delete del;
		}
	}
}