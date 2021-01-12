#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE	100

inline void error(char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};

class Node
{
	Node*	link;
	int		data;

public:
	Node(int val = 0) : data(val), link(NULL) { }
	Node* getLink() { return link; }
	void setLink(Node* next) { link = next; }
	void display() { printf(" <%2d>", data); }
	bool hasData(int val) { return data == val; }

	void insertNext(Node *n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}

	Node* removeNext() {
		Node* removed = link;
		if (removed != NULL)
			link = removed->link;
		return removed;
	}
};
