#pragma once

#include "Node.h"
class LinkedList
{
	Node	org;	// 헤드 노드 (헤드 포인터가 아님)

public:
	LinkedList() : org(0) { }
	~LinkedList() { clear(); }

	void clear() { while (!isEmpty()) delete remove(0); }
	Node* getHead() { return org.getLink(); }
	bool isEmpty() { return getHead() == NULL; }

	Node* getEntry(int pos) {
		Node* n = &org;
		for (int i = -1; i<pos; i++, n = n->getLink())
			if (n == NULL) break;
		return n;
	}

	void insert(int pos, Node *n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
	}

	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev->removeNext();
	}

	Node* find(int val) {
		for (Node *p = getHead(); p != NULL; p = p->getLink())
			if (p->hasData(val)) return p;
		return NULL;
	}

	void replace(int pos, Node *n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}

	int size() {
		int count = 0;
		for (Node *p = getHead(); p != NULL; p = p->getLink())
			count++;
		return count;
	}

	void display(const char* str = "리스트" ) {
		printf("%s", str);
		printf("[단순연결리스트 항목 수 = %2d] : ", size());
		for (Node *p = getHead(); p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}


	
	void reverse() {
		Node* prev = getEntry(-1);
		Node* n = prev->getLink(), *next;

		prev->setLink(NULL);
		while (n != NULL) {
			next = n->getLink();
			prev->insertNext(n);
			n = next;
		}
	}

	
	void merge(LinkedList* that) {
		Node* p = &org;
		for (; p->getLink() != NULL; p = p->getLink());

		p->setLink(that->org.getLink());
		that->org.setLink(NULL);
	}
};