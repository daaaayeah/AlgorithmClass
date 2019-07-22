#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct NodeStruct {
	int data;
	struct NodeStruct *leftChild;
	struct NodeStruct *rightChild;
}Node;

Node *BST_insert(Node *root, int data);
void BST_print(Node *root);

int main() {
	Node *root = NULL;
	int N;

	while (scanf("%d", &N) != EOF)
		root = BST_insert(root, N);
	BST_print(root);
}

Node *BST_insert(Node *root, int data) {
	if (root == NULL) {
		root = (Node *)malloc(sizeof(Node));
		root->data = data;
		root->leftChild = NULL;
		root->rightChild = NULL;
		return root;
	}
	else {
		if (root->data > data)
			root->leftChild = BST_insert(root->leftChild, data);
		else
			root->rightChild = BST_insert(root->rightChild, data);
	}

	return root;
}
void BST_print(Node *root) {
	if (root == NULL) return;
	BST_print(root->leftChild);
	BST_print(root->rightChild);
	printf("%d\n", root->data);
}