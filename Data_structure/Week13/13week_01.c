#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning (disable:4996)

typedef struct node {
	struct node* left;
	int id;
	int data;
	struct node* right;
} Node;

int cnt = 1;

bool is_empty(Node* node); // 노드 체크
Node* init_insert(Node* left, Node* right, int data, int id); // 초기화 데이터 삽입
Node* movenode(Node* node, int id); // node 순서 이동
int visit(Node*); // node 방문 함수
void preorder(Node* node); // 전위 순회
void inorder(Node* node); // 중위 순회
void postorder(Node* node); // 후위 순회

int main() {
	int n, id;
	Node* a8 = init_insert(NULL, NULL, 80, 8);
	Node* a7 = init_insert(NULL, NULL, 130, 7);
	Node* a6 = init_insert(a7, a8, 120, 6);
	Node* a5 = init_insert(NULL, NULL, 90, 5);
	Node* a4 = init_insert(NULL, NULL, 70, 4);
	Node* a3 = init_insert(NULL, a6, 50, 3);
	Node* a2 = init_insert(a4, a5, 30, 2);
	Node* root = init_insert(a2, a3, 20, 1);

	scanf("%d %d", &n, &id);
	
	Node* R = movenode(root, id);

	if ((1 <= id) && (id <= 8)) {
		switch (n) {
		case 1: {preorder(R);  break; }
		case 2: {inorder(R); break; }
		case 3: {postorder(R); break;}
		default: break;
		}
	}
	else
		printf("-1\n");


	free(a8);
	free(a7);
	free(a6);
	free(a5);
	free(a4);
	free(a3);
	free(a2);
	free(root);

	return 0;
}

Node* movenode(Node* node, int id) {
	if (!is_empty(node)) {
		if (node->id == id) return node;
		Node* p = movenode(node->left, id);
		if (p != NULL) return p;
		p = movenode(node->right, id);
		if (p != NULL) return p;
	}
	return NULL;
}

// 전위 순회
void preorder(Node* node) {
//	printf("3\n");
	if (node != NULL) {
		printf(" %d", node->data);
		preorder(node->left);
		preorder(node->right);
	}
}

// 중위 순회
void inorder(Node* node) {
	if (node != NULL) {
		inorder(node->left);
		printf(" %d", node->data);
		inorder(node->right);
	}
}

// 후위 순회 
void postorder(Node* node) {
	if (node != NULL) {
		postorder(node->left);
		postorder(node->right);
		printf(" %d", node->data);
	}
}


bool is_empty(Node* node) {
	if (node == NULL)
		return true;
	else
		return false;
}

Node* init_insert(Node* left, Node* right, int data, int id) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	
	newnode->left = left;
	newnode->right = right;
	newnode->data = data;
	newnode->id = id;

	return newnode;
}