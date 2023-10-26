#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

/* Heap_Sort list version
* 힙 정렬을 리스트로 구현한 버전입니다.
* 어려웠던 점 : NULL에 접근하는 함수들에 대한 처리가 필요했습니다.
*/

typedef struct node {
	struct node* left;
	struct node* parent;
	struct node* right;
	int key;
}Node;

bool isRoot(Node*);
bool isleft(Node*);
bool isRight(Node*);
bool isExternal(Node*);
bool isInternal(Node*);
void swap_Element(Node*, Node*);
int remove_min();
void list_HeapSort(Node*);
void insert_node(int);
void print_list(Node*);
void upHeap(Node*);
void downHeap(Node*);
void expandNode(Node*);
int delete_node(Node*, int);
int find_key(Node*, int);
Node* reduceExternal(Node*);
Node* sibling(Node*);
Node* find_node(Node*, int);
void advanceLast();
void retreatLast();
Node* root(Node*);

Node* last;

int main() {
	int n, c, d, s;
	last = (Node*)malloc(sizeof(Node));
	last->left = NULL, last->right = NULL, last->parent = NULL;
	while ((c = getchar()) != EOF && c != 'q') {
		if (c == 'i') {
			scanf("%d", &n);
			insert_node( n);
		}
		else if (c == 's') {
			scanf("%d", &n);
			s = find_key(root(last), n);
			if (s != 0)
				printf(" %d\n", s);
			else
				printf("X\n");
		}
		else if (c == 'p') {
			print_list(root(last));
			printf("\n");
		}
		else if (c == 'd') {
			printf(" %d\n", remove_min());
		}
	}

	

	return 0;
}

bool isRoot(Node* node) {
	if (node->parent == NULL)
		return true;
	else return false;
}
bool isleft(Node* node) {
	if (isRoot(node)) return false;
	else if (node->parent->left == node) return true;
	else return false;
}
bool isRight(Node* node) {
	if (isRoot(node)) return false;
	else if (node->parent->right == node) return true;
	else return false;
}
bool isExternal(Node* node) {
	if (node == NULL) return true;
	if ((node->left == NULL) && (node->right == NULL)) return true;
	else return false;
}
bool isInternal(Node* node) {
	if (node == NULL) return true;
	if ((node->left != NULL) || (node->right != NULL)) return true;
	else return false;
}

int find_key(Node* node, int key) {
	int n = 0;
	if (isExternal(node)) return n;
	if (node->key == key) return node->key;
	else {
		n = find_key(node->left, key);
		if (n == key) return n;
		n = find_key(node->right, key);
		return n;
	}
}
int remove_min() {
	int k = root(last)->key;
	Node* w = last;
	root(w)->key = w->key; 
	retreatLast();
	Node* z = w->right;
	reduceExternal(z);
	downHeap(root(last));
	return k;
}
void swap_Element(Node* X, Node* Y) {
	int tmp = X->key;
	X->key = Y->key;
	Y->key = tmp;
}
void insert_node(int key) {
	advanceLast();
	Node* z = last;
	z->key = key;
	expandNode(z);
	upHeap(z);
	return;
}
void print_list(Node* node) {
	if (isExternal(node)) {
		return;
	}
	else {
		printf(" %d", node->key);
		print_list(node->left);
		print_list(node->right);
	}
}
void upHeap(Node* node) {
	if (!isRoot(node)) {
		if (node->parent->key > node->key) {
			swap_Element(node, node->parent);
			upHeap(node->parent);
		}
	}
	else return;
}
void downHeap(Node* node) {
	if (isExternal(node->left) && isExternal(node->right)) { printf("okay\n"); return; }
	Node* smaller = node->left;
	if (!isExternal(node->right) && node->right->key < smaller) smaller = node->right;
	if (node->key <= smaller->key) return;
	swap_Element(node, smaller);
	downHeap(smaller);
}
void expandNode(Node* node) {
	Node* left = (Node*)malloc(sizeof(Node));
	Node* right = (Node*)malloc(sizeof(Node));
	
	left->left = NULL;
	left->right = NULL;
	left->key = 0;

	right->left = NULL;
	right->right = NULL;
	right->key = 0;

	left->parent = node;
	right->parent = node;

	node->left = left;
	node->right = right;
}
Node* reduceExternal(Node* node) { // 외부노드 들어옴
	Node* P = node->parent;
	Node* Z = sibling(node);
	if (isRoot(P)) {
		Z->parent = NULL;
		last = Z;
	}
	else {
		if (isleft(P))
			P->parent->left = Z;
		else
			P->parent->right = Z;
		Z->parent = P->parent;
	}
	free(P);
	free(node);
	return Z;
}
Node* find_node(Node* node, int key) {
	Node* p = node;
	if (isExternal(p) || (p->key == key)) return p;
	else {
		p = find_node(p->left, key);
		if (p->key == key) return p;
		p = find_node(p->right, key);
		return p;
	}
}
Node* sibling(Node* node) {
	if (isRoot(node)) {
		printf("Error");
		exit(0);
	}
	if (node->parent->left == node) return node->parent->right;
	else return node->parent->left;
}
void advanceLast(){
	while (isRight(last)) { last = last->parent; }
	if (isleft(last)) { last = last->parent->right; }
	while (isInternal(last)) { last = last->left; }
}
void retreatLast(){
	while (isleft(last)) { last = last->parent; }
	if (isRight(last)) { last = last->parent->left; }
	while (isInternal(last->left) && isInternal(last->right)) { last = last->right; }
}
Node* root(Node* node) {
	Node* p = node;
	while (!isRoot(p))
		p = p->parent;
	return p;
}