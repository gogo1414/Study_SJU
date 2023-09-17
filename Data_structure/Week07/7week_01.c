#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	struct node* prev;
	int data;
	struct node* next;
} Node;

typedef struct list {
	Node* head;
	Node* tail;
	int cnt;
} List;

void init (List* list) {
	Node* head = (Node*)malloc(sizeof(Node));
	Node* tail = (Node*)malloc(sizeof(Node));

	list->head = head;
	head->next = tail;

	list->tail = tail;
	tail->prev = head;
	
	head->prev = NULL;
	tail->next = NULL;
	
	list->cnt = 0;
}

void addElem(List* list, int X) {
	Node* p = list->head;
	for (int i = 0; i < list->cnt; i++) {
		p = p->next;
	}

	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = X;

	new_node->next = p->next;
	new_node->prev = p;
	p->next = new_node;
	new_node->next->prev = new_node;
	
	list->cnt = list->cnt + 1;
}

int subset(List* A, List* B) {
	Node* a = A->head->next;
	Node* b = B->head;
	int res = 0;
	for (int i = 0; i < B->cnt; i++) {
		b = b->next;
		if (a->data == b->data) {
			res++;
			a = a->next;
		}
	}
	if (res == A->cnt)		return 0;
	else return a->data;
}

int main() {
	List* A = (List*)malloc(sizeof(List));
	List* B = (List*)malloc(sizeof(List));
	init(A), init(B);
	int A_size, B_size, n;
	scanf("%d", &A_size);
	for (int i = 0; i < A_size; i++) {
		scanf("%d", &n);
		addElem(A, n);
	}
	scanf("%d", &B_size);
	for (int i = 0; i < B_size; i++) {
		scanf("%d", &n);
		addElem(B, n);
	}

	printf("%d", subset(A, B));

	return 0;
}