#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	struct node* next;
	int data;
} Node;

typedef struct list {
	Node* head;
	int n;
}List;

void init(List* list) {
	Node* head = (Node*)malloc(sizeof(Node));

	list->head = head;
	head->next = NULL;

	list->n = 0;
}

Node* makelist(int n) {
	Node* H = (Node*)malloc(sizeof(Node));
	H->next = NULL;
	return rMakelist(H, n);
}

Node* rMakelist(Node* H, int n) {
	if (n == 0)
		return H;
	else {
		H->data = n % 10;
		return makelist(H, n / 10);
	}
}

void print(Node* list) { // 연결리스트의 원소들을 출력해준다.
	Node* p = list;
	for (int i = 0; p->next != NULL; i++) {
		p = p->next;
		printf(" %d", p->data);
	}
	return;
}

int main() {
	int a, b;
	List* list = (List*)malloc(sizeof(List));
	init(list);
	scanf("%d", &a);
	print(makelist(a));
	return 0;
}