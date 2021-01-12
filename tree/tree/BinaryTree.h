#include "BinaryNode.h"
#include <stdlib.h>

inline void error(const char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};

#define MAX_QUEUE_SIZE 100

class CircularQueue {

	int front;
	int rear;
	BinaryNode* data[MAX_QUEUE_SIZE];

public:

	CircularQueue() { front = rear = 0; }
	bool isEmpty() { return front = rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

	void enqueue(BinaryNode* n) {
		if (isFull()) error("Error:ť�� ��ȭ�����Դϴ�\n");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = n;
		}
	}

	BinaryNode* dequeue() {
		if (isFull()) error("Error:ť�� ��������Դϴ�\n");
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}

};




class BinaryTree {

	BinaryNode* root;
public:
	BinaryTree():root(NULL){}

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }

	bool isEmpty() { return root == NULL; }

	//��ȸ����

	//������ȸ
	void inorder() { printf("\n inorder:"); inorder(root); }
	void inorder(BinaryNode* node) {
		if (node != NULL) {

			inorder(node->getLeft());
			printf("[%c]", node->getData());
			inorder(node->getRight());
		}
	}
	//������ȸ
	void preorder(){ printf("\n preorder:"); preorder(root); }
	void preorder(BinaryNode* node) {
		if (node != NULL) {

			printf("[%c]", node->getData());
			preorder(node->getLeft());
			preorder(node->getRight());
		}
	}

	//������ȸ
	void postorder(){ printf("\n postorder:"); postorder(root); }
	void postorder(BinaryNode* node) {
			if (node != NULL) {

				postorder(node->getLeft());
				postorder(node->getRight());
				printf("[%c]", node->getData());
			}
	}

	//������ȸ
	void levelorder(){
	
		printf("\nlevelorder: ");
		if (!isEmpty()) {
			CircularQueue q;
			q.enqueue(root);
			while (!q.isEmpty()) {
				BinaryNode* n = q.dequeue();
				if (n != NULL) {
					printf("[%c]", n->getData());
					q.enqueue(n->getLeft());
					q.enqueue(n->getRight());
				}
			}
		}
		printf("\n");
	}

	//�߰�����

	//��� ���� ���ϴ� �Լ�
	int getCount() { return isEmpty() ? 0 : getCount(root); }
	int getCount(BinaryNode* node) {
		if (node == NULL)return 0;
		return 1 + getCount(node->getLeft())
			     + getCount(node->getRight());

	}


	//���� ���ϴ� �Լ� 
	int getHeight() { return isEmpty() ? 0 : getHeight(root); }
	int getHeight(BinaryNode* node) {
		if (node == NULL) return 0;
		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());
		
		return(hLeft > hRight) ? hLeft + 1 : hRight+1;

	}
	
	//�ܸ� ��� ���� ���ϴ� �Լ�
	int getLeafCount(){ return isEmpty() ? 0 : getHeight(root); }
	int getLeafCount(BinaryNode* node) {
		if (node == NULL) return 0;
		if (node->isLeaf())return 1;
		else return getLeafCount(node->getLeft())
			+ getLeafCount(node->getRight());
	}
};
