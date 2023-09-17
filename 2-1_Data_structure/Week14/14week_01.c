#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#pragma warning(disable:4996)

// Ʈ���� ����� ���
typedef struct node {
	struct node* leftchild;
	int num;
	struct node* rightchild;
}Node;

//Ʈ�� �Ѹ�
typedef struct tree {
	Node* root;
}Tree;

// Ʈ�� �ʱ�ȭ
void init(Tree* tree) {
	tree->root = NULL;
}

// Ʈ���� ��尡 ����ִ��� Ȯ��
bool is_empty(Node* node) {
	return node == NULL;
}

// �ش� ������ ��� ã�� �� ��ȯ
Node* find(Node* root, int c) {
	if (!is_empty(root)) {
		if (root->num == c) return root;
		Node* p = find(root->leftchild, c);
		if (!is_empty(p)) return p;
		p = find(root->rightchild, c);
		if (!is_empty(p)) return p;
	}
	return NULL;
}

// Ʈ���� ���� ����
void push(Tree* tree, int p, int l, int r) {
	if (is_empty(tree->root)) {
		Node* parent = (Node*)malloc(sizeof(Node));
		Node* left = (Node*)malloc(sizeof(Node));
		Node* right = (Node*)malloc(sizeof(Node));
		parent->num = p;
		left->num = l;
		right->num = r;
		left->leftchild = left->rightchild = NULL;
		right->leftchild = right->rightchild = NULL;
		if (l == 0) left = NULL;
		if (r == 0) right = NULL;
		parent->leftchild = left;
		parent->rightchild = right;
		tree->root = parent;
	}
	else {
		Node* left = (Node*)malloc(sizeof(Node));
		Node* right = (Node*)malloc(sizeof(Node));
		Node* a = find(tree->root, p);
		left->num = l;
		right->num = r;
		left->leftchild = left->rightchild = NULL;
		right->leftchild = right->rightchild = NULL;
		if (l == 0) left = NULL;
		a->leftchild = left;
		if (r == 0) right = NULL;
		a->rightchild = right;
	}
}

// �ش� ����� ��ȣ ���
void print(Node* p) {
	if (is_empty(p)) printf("error");
	printf(" %d", p->num);
}

// Ž���ϸ鼭 �湮�ϴ� ��� ��ȣ ���
void quest(Node* root, char* c) {
	if (is_empty(root)) printf("error");
	else {
		Node* p = root;
		print(p);
		for (int i = 0; i < strlen(c); i++) {
			if (is_empty(p)) return;
			if (*(c+i) == 'R') {
				p = p->rightchild;
			}
			else if (*(c+i) == 'L') {
				p = p->leftchild;
			}
			print(p);
		}
	}
}

int main() {
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	init(tree);
	int n , p, r, l, s;
	char finds[101];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &p, &l, &r);
		push(tree , p, l, r);
	}

	scanf("%d", &s);

	for (int i = 0; i < s; i++) {
		scanf("%s", &finds);
		quest(tree->root, finds);
	}


	return 0;
}
