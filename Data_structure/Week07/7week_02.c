#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int data;
	struct node* next;
} Node;

typedef struct list {
	Node* head;
	int cnt;
} List;

void init(List* list) {
	Node* head = (Node*)malloc(sizeof(Node));
	list->head = head;
	head->next = NULL;
	list->cnt = 0;
}

void addElem(List* s, int X) {
	Node* a = s->head;
	if(s->cnt == 0)
		a->data = X;
	else {
		for (int i = 1; i < s->cnt; i++)
			a = a->next;
		Node* new_node = (Node*)malloc(sizeof(Node));
		new_node->next = NULL;
		new_node->data = X;
		a->next = new_node;
	}
	s->cnt = s->cnt + 1;
}

int subset(List* A, List* B) {
	Node* a = A->head;
	Node* b = B->head;
	int res = 0;
	for (int i = 0; i < B->cnt;i++) {
		if (a->data == b->data) {
			res++;
			if (a->next == NULL)
				return 0;
			a = a->next;
		}
		b = b->next;
	}
	if (res == A->cnt) return 0;
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