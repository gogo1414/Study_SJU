#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

/* 상향식 힙 생성을 트리로
* 문제 3의 2번과 다른 점은 출력을 레벨 순으로 하고 있어, 전위순회로 출력하는 트리와는 다르게 출력이 된다.
* 하지만 그 구조는 동일하다.
* 비재귀의 경우 배열로 주어질 경우에만 가능하기 때문에 생략한다.
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
void rBuildHeap(Node*);
Node* root(Node*);

Node* last;

int main() {
	int n, c, x[100];
	last = (Node*)malloc(sizeof(Node));
	last->left = NULL, last->right = NULL, last->parent = NULL;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c);
		insert_node(c);
	}

	rBuildHeap(root(last));
	print_list(root(last));

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
void rBuildHeap(Node* node) {
	if (isInternal(node)) {
		rBuildHeap(node->left);
		rBuildHeap(node->right);
		downHeap(node);
	}
	return;
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
	//upHeap(z);
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
	if (isExternal(node->left) && isExternal(node->right)) return;
	Node* bigger = node->left;
	if (!isExternal(node->right) && node->right->key > bigger->key) bigger = node->right;
	if (node->key >= bigger->key) return;
	swap_Element(node, bigger);
	downHeap(bigger);
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
void advanceLast() {
	while (isRight(last)) { last = last->parent; }
	if (isleft(last)) { last = last->parent->right; }
	while (isInternal(last)) { last = last->left; }
}
void retreatLast() {
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