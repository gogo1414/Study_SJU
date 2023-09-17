#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	struct node* next;
	int data;
}Node;

typedef struct list {
	Node* head;
	int cnt;
}List;

void init(List* list) {
	Node* head = (Node*)malloc(sizeof(Node));
	list->head = head;
	head->next = NULL;
	list->cnt = 0;
}

void addelem(List* list, int X) {
	Node* p = list->head; 
	for (int i = 0; i < list->cnt; i++) {
		p = p->next;
	}
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = X;
	new_node->next = NULL;
	p->next = new_node;
	list->cnt = list->cnt + 1;
}

void print_list(List* s) {
	Node* p = s->head->next;
	if (p == NULL) {
		printf(" 0");
		return;
	}
	
	for (int i = 0; i < s->cnt; i++) {
		printf(" %d", p->data);
		p = p->next;
	}

	return;
}

List* union_list(List* A, List* B) {
	List* unionlist = (List*)malloc(sizeof(List));
	init(unionlist);
	Node* a = A->head->next;
	Node* b = B->head->next;
	while (a != NULL && b != NULL) {
		if (a->data < b->data) {
			addelem(unionlist, a->data);
			a = a->next;
		}
		else if (a->data > b->data) {
			addelem(unionlist, b->data);
			b = b->next;
		}
		else {
			addelem(unionlist, a->data);
			a = a->next, b = b->next;
		}
	}
	while (a != NULL) {
		addelem(unionlist, a->data);
		a = a->next;
	}
	while (b != NULL) {
		addelem(unionlist, b->data);
		b = b->next;
	}
	return unionlist;
}

List* intersect_list(List* A, List* B) {
	List* intersectlist = (List*)malloc(sizeof(List));
	init(intersectlist);
	Node* a = A->head->next;
	Node* b = B->head->next;
	while (a != NULL && b != NULL) {
		if (a->data == b->data) {
			addelem(intersectlist, a->data);
			a = a->next;
			b = b->next;
		}
		else if (a->data < b->data)
			a = a->next;
		else
			b = b->next;
	}

	return intersectlist;
}

int main() {
	List* A = (List*)malloc(sizeof(List));
	List* B = (List*)malloc(sizeof(List));
	List* unionlist = (List*)malloc(sizeof(List));
	List* intersectlist = (List*)malloc(sizeof(List));
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

//	print_list(A); test ¼º°ø

	unionlist = union_list(A, B);
	print_list(unionlist);
	printf("\n");
	intersectlist = intersect_list(A, B);
	print_list(intersectlist);

	return 0;
}