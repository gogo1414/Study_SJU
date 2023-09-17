#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	struct node* next;
	int data;
	struct node* prev;
} Node;

typedef struct list {
	Node* head;
	Node* tail;
	int n;
}List;

void init(List* list) {
	Node* head = (Node*)malloc(sizeof(Node));
	Node* tail = (Node*)malloc(sizeof(Node));

	list->head = head;
	list->tail = tail;

	head->prev = NULL;
	head->next = tail;

	tail->prev = head;
	tail->next = NULL;

	list->n = 0;
}

void add(List* list, int a) {
	Node* p = list->head;
	for (int i = 0; i < list->n; i++)
		p = p->next;
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = a;

	new_node->prev = p;
	new_node->next = p->next;
	p->next = new_node;
	new_node->next->prev = new_node;

	list->n += 1;
	return;
}

List* first(List* list) { // 연결리스트를 짝수 부분으로 나눠준다.
	Node* p = list->head;
	List* a = (List*)malloc(sizeof(List));
	List* b = (List*)malloc(sizeof(List));
	init(a), init(b);
	for(int i=0;i<list->n;i++){
		p = p->next;
		if (p->data % 2 == 0)
			add(a, p->data);
		else
			add(b, p->data);
	}

	return a;
}

List* second(List* list) { // 연결리스트를 홀수 부분으로 나눠준다.
	Node* p = list->head;
	List* b = (List*)malloc(sizeof(List));
	init(b);
	for(int i=0;i<list->n;i++){
		p = p->next;
		if (p->data % 2 != 0)
			add(b, p->data);
	}

	return b;
}

void sort(List* list) { // 원소들을 작은 순서대로 정렬해준다.
	Node* p = list->tail;
	Node* q = list->tail;
	int tmp = 0;
	for (int i = 0; i < list->n; i++) {
		for (int j = 0; j < list->n-1; j++) {
			p = p->prev;
			if (p->data < p->prev->data) {
				tmp = p->data;
				p->data = p->prev->data;
				p->prev->data = tmp;
			}
		}
		p = q;
	}
	return;
}

void print(List* list) { // 연결리스트의 원소들을 출력해준다.
	Node* p = list->head;
	for (int i = 0; i < list->n; i++) {
		p = p->next;
		printf(" %d", p->data);
	}
	return;
}

int main() {
	int a;
	List* list = (List*)malloc(sizeof(List));
	List* A = (List*)malloc(sizeof(List));
	List* B = (List*)malloc(sizeof(List));

	init(list);

	for (int i = 0; i < 10; i++) {
		scanf("%d", &a);
		add(list, a);
	}

	A = first(list);
	B = second(list);
	sort(A);
	sort(B);
	printf("\n");
	print(B);
	printf("\n");
	print(A);
	return 0;
}
// 1 2 3 4 5 6 7 8 9 10
// 10 9 8 7 6 5 4 3 2 1
// 293 10 13 155 55 87 46 42 23 33