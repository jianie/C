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

	printf(" 노드의 개수 =%d\n", tree.getCount());
	printf(" 단말의 개수 =%d\n", tree.getLeafCount());
	printf(" 트리의 높이 =%d\n", tree.getHeight());
}