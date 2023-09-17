#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct Node {
	struct node* prev;
	int data;
	struct node* next;
}Node;

typedef struct list {
	Node* head;
	Node* tail;
	int cnt;
} List;

void init(List* list) {
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

void addelem(List* list, int X) {
	Node* p = list->head;
	for (int i = 0; i < list->cnt; i++)
		p = p->next;
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = X;

	new_node->prev = p;
	new_node->next = p->next;

	p->next = new_node;
	p = p->next;
	p->prev = new_node;

	list->cnt = list->cnt + 1;
}

List* union_ab(List* A, List* B) {
	Node* a = A->head->next;
	Node* b = B->head->next;
	List* union_list = (List*)malloc(sizeof(List));
	init(union_list);
	while (a != A->tail && b != B->tail) {
		if (a->data < b->data) {
			addelem(union_list, a->data);
			a = a->next;
		}
		else if (a->data > b->data) {
			addelem(union_list, b->data);
			b = b->next;
		}
		else {
			addelem(union_list, a->data);
			a = a->next;
			b = b->next;
		}
	}
	while (a != A->tail) {
		addelem(union_list, a->data);
		a = a->next;
	}
	while (b != B->tail) {
		addelem(union_list, b->data);
		b = b->next;
	}
	return union_list;
}

List* intersect(List* A, List* B) {
	Node* a = A->head->next;
	Node* b = B->head->next;
	List* intersect_list = (List*)malloc(sizeof(List));
	init(intersect_list);
	while (a != A->tail && b != B->tail) {
		if (a->data == b->data) {
			addelem(intersect_list, a->data);
			a = a->next;
			b = b->next;
		}
		else if (a->data < b->data)
			a = a->next;
		else
			b = b->next;
	}
	return intersect_list;
}

void print_list(List* x){
	Node* p = x->head->next;
	if (x->cnt == 0) {
		printf(" 0");
		return;
	}
	for (int i = 0; i < x->cnt; i++) {
		printf(" %d", p->data);
		p = p->next;
	}
	return 0;
}

int main() {
	List* A = (List*)malloc(sizeof(List));
	List* B = (List*)malloc(sizeof(List));
	List* union_list = (List*)malloc(sizeof(List));
	List* intersect_list = (List*)malloc(sizeof(List));
	init(A), init(B);
	int A_size, B_size, n;

	scanf("%d", &A_size);
	for (int i = 0; i < A_size; i++) {
		scanf("%d", &n);
		addelem(A, n);
	}

	scanf("%d", &B_size);
	for (int i = 0; i < B_size; i++) {
		scanf("%d", &n);
		addelem(B, n);
	}

	union_list = union_ab(A, B);
	print_list(union_list);
	printf("\n");
	intersect_list = intersect(A, B);
	print_list(intersect_list);
	return 0;
}