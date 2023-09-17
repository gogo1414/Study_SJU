#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	struct node* prev;
	char elem;
	struct node* next;
} Node;

typedef struct list {
	Node* head;
	Node* tail;
	int cnt;
} List;

void init(List* list);
void addElement_doublelinkedlist(List* list, int rank, char elem);
void deleteElement_doublelinkedlist(List* list, int rank);
char getElement_doublelinkedlist(List* list, int rank);
void printAll_doublelinkedlist(List* list);

int main() {
	int N, rank;
	char A, elem, getelem;
	List* list = (List*)malloc(sizeof(List));
	init(list);

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%c", &A);
		if (A == 'A') {
			scanf("%d %c", &rank, &elem);
			addElement_doublelinkedlist(list, rank, elem);
		}
		if (A == 'D') {
			scanf("%d", &rank);
			deleteElement_doublelinkedlist(list, rank);
	}
		if (A == 'G') { 
			scanf("%d", &rank);
			getelem = getElement_doublelinkedlist(list, rank);
			if(getelem)
				printf("%c\n", getelem);
		}
		if (A == 'P') {
			printAll_doublelinkedlist(list);
		}
	}

	return;
}

void init(List* list) {
	Node* head = (Node*)malloc(sizeof(Node));
	Node* tail = (Node*)malloc(sizeof(Node));

	head->prev = NULL;
	head->next = tail;

	tail->next = NULL;
	tail->prev = head;

	list->head = head;
	list->tail = tail;

	list->cnt = 0;
}

void addElement_doublelinkedlist(List* list, int rank, char elem) {
	if (rank < 1 || rank > list->cnt + 1) {
		printf("invalid position\n");
		return;
	}
	else {
		Node* p = list->head;

		for (int i = 0; i < rank; i++) {
			p = p->next;
		}

		// 맨 뒤 기준으로 삽입
		Node* new_node = (Node*)malloc(sizeof(Node));
		new_node->elem = elem;
		new_node->next = p;
		new_node->prev = p->prev;
		
		p->prev = new_node;
		new_node->prev->next = new_node;

		list->cnt += 1;

		return;
	}
}

void deleteElement_doublelinkedlist(List* list, int rank) {
	if (rank > list->cnt) {
		printf("invalid position\n");
		return;
	}
	else {
		Node* p = list->head;

		for (int i = 0; i < rank; i++) {
			p = p->next;
		}

		p->next->prev = p->prev;
		p->prev->next = p->next;

		list->cnt -= 1;

		free(p);
	}
}

char getElement_doublelinkedlist(List * list, int rank) {
	if (rank > list->cnt) {
		printf("invalid position\n");
		return NULL;
	}
	else {
		Node* p = list->head;

		for (int i = 0; i < rank; i++)
			p = p->next;

		return p->elem;
	}
}

void printAll_doublelinkedlist(List * list) {
	if (list->cnt == 0)
		return;
	else {
		Node* p = list->head;

		for (int i = 0; i < list->cnt; i++) {
			p = p->next;
			printf("%c", p->elem);
		}
		printf("\n");
		return;
	}
}