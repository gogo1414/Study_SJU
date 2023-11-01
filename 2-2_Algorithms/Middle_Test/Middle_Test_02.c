#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

/* Binary_Search Tree - Middle Test 2
* 구현 기능 삽입, 삭제, 탐색, 출력(중위순회), 특이 출력 r ~ l 전위 순회 출력,
*/

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
	struct node* parent;
} Node;

typedef struct tree {
	Node* root;
} Tree;

bool isExternal(Node*);
bool isInternal(Node*);

void init(Tree*);
void expand(Node*);
void insert(Tree*, int);
void delete(Tree*, int);
void search(Tree*, int);
void print(Node*);
void r_print(Node*, int, int);

Node* node_Search(Node*, int);
Node* sibling(Node*);
Node* reduceExternal(Node*);
Node* inOrderSuc(Node*);

Tree* tree;

int main() {
	tree = (Tree*)malloc(sizeof(Tree));
	init(tree);
	int c, data, l, r;

	while ((c = getchar()) != EOF && c != 'q') {
		if (c == 'i') {
			scanf("%d", &data);
			insert(tree, data);
		}
		else if (c == 'd') {
			scanf("%d", &data);
			delete(tree, data);
		}
		else if (c == 'p') {
			print(tree->root);
			printf("\n");
		}
		else if (c == 's') {
			scanf("%d", &data);
			search(tree->root, data);
		}
		else if (c == 'r') {
			scanf("%d %d", &l, &r);
			r_print(tree->root, l, r);
			printf("\n");
		}
	}

	return 0;
}

bool isExternal(Node* node) {
	if (node->left == NULL && node->right == NULL) return true;
	else return false;
}
bool isInternal(Node* node) {
	if (node->left != NULL || node->right != NULL) return true;
	else return false;
}

void init(Tree* tree) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->parent = NULL;
	newnode->right = NULL;
	newnode->left = NULL;
	tree->root = newnode;
}
void expand(Node* node) {
	Node* left = (Node*)malloc(sizeof(Node));
	Node* right = (Node*)malloc(sizeof(Node));

	left->left = NULL;
	left->right = NULL;
	left->parent = node;

	right->left = NULL;
	right->right = NULL;
	right->parent = node;
	
	node->left = left;
	node->right = right;
}
void insert(Tree* tree, int data) {
	Node* P = node_Search(tree->root, data);
	P->data = data;
	expand(P);
}
void delete(Tree* tree, int data) {
	Node* P = node_Search(tree->root, data);
	if (isExternal(P)) {
		printf("NoSuchKey\n");
		return;
	}
	int p = P->data;
	Node* Z = P->left;
	if (!isExternal(Z))
		Z = P->right;
	if (isExternal(Z))
		reduceExternal(Z);
	else {
		Node* Y = inOrderSuc(P);
		Z = Y->left;
		P->data = Y->data;
		reduceExternal(Z);
	}
	printf("%d\n", p);
}
void search(Node* root, int data) {
	if (isExternal(root)) return;
	if (root->data == data) { printf("%d\n", root->data); return; }	
	else if (root->data > data)	search(root->left, data);
	else if(root->data < data)	search(root->right, data);
	
}
void print(Node* root) {
	if (isExternal(root)) return;
	printf(" %d", root->data);
	print(root->left);
	print(root->right);
}
void r_print(Node* root,int l,int r) {
	if (isExternal(root)) return;
	if (l <= root->data && root->data <= r) printf(" %d", root->data);
	r_print(root->left, l, r);
	r_print(root->right, l, r);
}

Node* node_Search(Node* root, int data) {
	if (isExternal(root)) return root;
	else if (root->data == data) return root;
	else if (root->data > data) return node_Search(root->left, data);
	else if (root->data < data) return node_Search(root->right, data);
}
Node* sibling(Node* node) {
	if (node->parent == NULL) {
		printf("ERROR!!!");
		exit(0);
	}
	if (node->parent->left == node)
		return node->parent->right;
	else
		return node->parent->left;
	
}
Node* reduceExternal(Node* node) {
	Node* P = node->parent;
	Node* PZ = sibling(node);
	if (P->parent == NULL) {
		PZ->parent = NULL;
		tree->root = PZ;
	}
	else {
		Node* PP = P->parent;
		PZ->parent = PP;
		if (PP->left == P)
			PP->left = PZ;
		else
			PP->right = PZ;
	}
	free(node);
	free(P);
	return PZ;
}
Node* inOrderSuc(Node* node) {
	Node* P = node->right;
	if (isInternal(P))
		while (isInternal(P))
			P = P->left;
	return P;
}
