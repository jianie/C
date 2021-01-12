#include "BinaryTree.h"

void main()
{
	BinaryTree tree;
	BinaryNode* d = new BinaryNode('D', NULL, NULL);
	BinaryNode* b = new BinaryNode('B', d, NULL);
	BinaryNode* g = new BinaryNode('G', NULL, NULL);
	BinaryNode* h = new BinaryNode('H', NULL, NULL);
	BinaryNode* e = new BinaryNode('E', g, h);
	BinaryNode* f = new BinaryNode('F', NULL, NULL);
	BinaryNode* c = new BinaryNode('C', e, f);
	BinaryNode* a = new BinaryNode('A', b, c);
	tree.setRoot(a);


	tree.inorder();
	tree.preorder();
	tree.postorder();
	tree.levelorder();

	printf(" ����� ���� =%d\n", tree.getCount());
	printf(" �ܸ��� ���� =%d\n", tree.getLeafCount());
	printf(" Ʈ���� ���� =%d\n", tree.getHeight());
}