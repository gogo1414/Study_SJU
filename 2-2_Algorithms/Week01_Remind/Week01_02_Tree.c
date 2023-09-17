#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct node {
	struct node* leftchild;
	struct node* rightchild;
	int data;
} Node;

typedef struct tree {
	Node* root;
} Tree;

Node* findNode_tree(Node* root, int p) {
	if (root != NULL) {
		if (root->data == p) return root;
		Node* P = findNode_tree(root->leftchild, p);
		if (P != NULL) return P;
		P = findNode_tree(root->rightchild, p);
		if (P != NULL) return P;
	}
	return NULL;
}

void init_tree(Tree*);
void makeNode_tree(Tree*, int, int, int);
void explorenode_tree(Tree*, char*);

int main() {
	int N, s, parent, leftchild, rightchild;
	char explore[100];
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	init_tree(tree);
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &parent, &leftchild, &rightchild);
		makeNode_tree(tree, parent, leftchild, rightchild);
	}


	scanf("%d", &s);

	for (int j = 0; j < s; j++) {
		scanf("%s", explore);
		explorenode_tree(tree, explore);
	}

	return 0;
}

void init_tree(Tree* tree) {
	tree->root = NULL;
}

void makeNode_tree(Tree* tree, int parent, int left, int right) {
	if (tree->root == NULL) {
		Node* parent_node = (Node*)malloc(sizeof(Node));
		Node* left_node = (Node*)malloc(sizeof(Node));
		Node* right_node = (Node*)malloc(sizeof(Node));

		parent_node->data = parent;
		parent_node->leftchild = left_node;
		parent_node->rightchild = right_node;
		tree->root = parent_node;

		left_node->data = left;
		left_node->leftchild = NULL;
		left_node->rightchild = NULL;
		tree->root->leftchild = left_node;

		right_node->data = right;
		right_node->leftchild = NULL;
		right_node->rightchild = NULL;
		tree->root->rightchild = right_node;
		
		return;
	}
	else {
		Node* parent_node = findNode_tree(tree->root, parent);
		
		if (left != 0) {
			Node* left_node = (Node*)malloc(sizeof(Node));

			left_node->data = left;
			left_node->leftchild = NULL;
			left_node->rightchild = NULL;
			parent_node->leftchild = left_node;
		}
		if (right != 0) {
			Node* right_node = (Node*)malloc(sizeof(Node));

			right_node->data = right;
			right_node->leftchild = NULL;
			right_node->rightchild = NULL;
			parent_node->rightchild = right_node;
		}

		return;
	}
}

void explorenode_tree(Tree* tree, char* explore) {
	Node* p = tree->root;
	for (int i = 0; i< strlen(explore) + 1; i++) {
		printf(" %d", p->data);
		if (*(explore+i) == 'L') {
			p = p->leftchild;
		}
		else {
			p = p->rightchild;
		}
	}

	printf("\n");

	return;
}