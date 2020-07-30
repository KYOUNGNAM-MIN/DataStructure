#pragma once
#include <iostream>
using namespace std;

class Chain;

class ChainNode {
	friend class Chain;
private:
	int data;
	ChainNode *link;
public:
	ChainNode(int element = 0, ChainNode* next = 0) {
		data = element;
		link = next;
	}
};
class Chain {
private:
	ChainNode* first;
	int deleteFirst;
	int deleteAdd;
public:
	Chain(int n, int m, int k) {
		ChainNode* p = 0;
		ChainNode* c = 0;
		for (int i = 1; i <= n; i++) {
			if (i == 1) {
				p = new ChainNode(i, 0);
				first = p;
			}
			else if (i == n) {
				c = new ChainNode(i, first);
				p->link = c;
			}
			else {
				c = new ChainNode(i, 0);
				p->link = c;
				p = c;
			}
		}
		deleteFirst = m;
		deleteAdd = k;
	}
	void Delete();
	void Print(int n);
};
void Chain::Print(int n) {
	int count = 0;
	for (ChainNode* i = first; count < n; i = i->link) {
		cout << i->data << endl;
		count++;
	}
}/*
void Chain::Delete() {
	ChainNode* tmp=NULL;
	ChainNode* j;
	for (ChainNode* i = first; i != 0; i = i->link) {
		if (i->data == deleteFirst) {
			cout << i->data << endl;
			
			j->link = i->link;
			delete i;
		}
	}
}*/