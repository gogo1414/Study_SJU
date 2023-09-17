#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	struct node* left;
	struct node* right;
	int id;
}Node;

typedef struct tree {
	Node* root;
}Tree;

void init(Tree* tree) {
	tree->root = NULL;
}

Node* find(Node* root, int x) {
	if (root != NULL) {
		Node* p = root;
		if (p->id == x) return p;
		p = find(p->left, x);
		if (p != NULL) return p;
		p = find(p->right, x); 
		if (p != NULL) return p;
	}
	return NULL;
}

void init_insert(Tree* tree, int p, int l, int r) {
	if (tree->root == NULL) {
		printf("1\n");
		Node* parent = (Node*)malloc(sizeof(Node));
		Node* leftchild = (Node*)malloc(sizeof(Node));
		Node* rightchild = (Node*)malloc(sizeof(Node));
		parent->id = p;
		leftchild->id = l;
		rightchild->id = r;
		leftchild->left = leftchild->right = NULL;
		rightchild->left = rightchild->right = NULL;
		parent->left = leftchild;
		parent->right = rightchild;
		tree->root = parent;
	}
	else {
		Node* leftchild = (Node*)malloc(sizeof(Node));
		Node* rightchild = (Node*)malloc(sizeof(Node));
		printf("1\n");
		Node* a = find(tree->root, p);
		printf("2\n");
		leftchild->id = l;
		rightchild->id = r;
		leftchild->left = leftchild->right = NULL;
		rightchild->left = rightchild->right = NULL;
		if (l == 0) {
			leftchild = NULL;
		}
		if (r == 0)
			rightchild = NULL;
		a->left = leftchild;
		a->right = rightchild;
		printf("%d %d %d\n", a->id, a->left->id, a->right->id);
	}
}


int main() {
	int n, p, l, r, n2;
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	init(tree);
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &p, &l, &r);
		init_insert(tree, p, l, r);
	}
	scanf("%d", &n2);

	return 0;
}
