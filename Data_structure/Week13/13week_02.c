#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

typedef struct node {
	struct node* left;
	int data;
	int id;
	struct node* right;
}Node;

Node* init_insert(Node*, Node*, int, int);
Node* movenode(Node* node, int id);
bool isempty(Node*);
int sum_size(Node* node);
int visit(Node*);


int main() {
	int id;
	
	Node* a8 = init_insert(NULL, NULL, 80, 8);
	Node* a7 = init_insert(NULL, NULL, 130, 7);
	Node* a6 = init_insert(a7, a8, 120, 6);
	Node* a5 = init_insert(NULL, NULL, 90, 5);
	Node* a4 = init_insert(NULL, NULL, 70, 4);
	Node* a3 = init_insert(NULL, a6, 50, 3);
	Node* a2 = init_insert(a4, a5, 30, 2);
	Node* root = init_insert(a2, a3, 20, 1);


	scanf("%d", &id);

	if ((1 <= id) && (id <= 8)) printf("%d", sum_size(movenode(root, id)));
	else printf("-1\n");

	return 0;
}

int sum_size(Node* node) {
	if (isempty(node)) return 0;
	int sum = node->data;
	sum += sum_size(node->left);
	sum += sum_size(node->right);
	return sum;
}

int visit(Node* node) {
	if (isempty(node))
		return 0;
	else return node->data;
}

Node* init_insert(Node* left, Node* right, int data, int id) {
	Node* newnode = (Node*)malloc(sizeof(Node));

	newnode->left = left;
	newnode->right = right;
	newnode->id = id;
	newnode->data = data;

	return newnode;
}

Node* movenode(Node* node, int id) {
	if (!isempty(node)) {
		if (node->id == id) return node;
		Node* p = movenode(node->left, id);
		if (p != NULL) return p;
		p = movenode(node->right, id);
		if (p != NULL) return p;
	}
	return NULL;
}

bool isempty(Node* node) {
	if (node == NULL) return true;
	else return false;
}