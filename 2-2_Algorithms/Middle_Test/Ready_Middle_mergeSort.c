#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

/* 단일연결리스트를 이용한 합병 정렬 구현
* 단일연결리스트 구조가 필요하다.
* L1과 L2를 나누는 것에 있어서 L1은 L을 이용해서 구현
* L1과 L2를 합치는 것에 있어서 새로운 리스트를 만들어서 반환
*/

typedef struct node {
	struct node* next;
	int key;
} Node;

typedef struct list {
	Node* head;
	int size;
}List;

void insert_key(List*);
void print_list(List*);
void addLast(List*, int);
int removeFirst(List*);
bool isempty(List*);

List* mergeSort(List*);
List* partition(List*, int);
List* merge(List*);


int main() {
	int  n, k;
	scanf("%d", &n);
	List* L = (List*)malloc(sizeof(List));
	L->head = NULL;
	L->size = n;

	insert_key(L);
	L = mergeSort(L);
	print_list(L);

	return 0;
}

bool isempty(List* L) {
	if (L->head == NULL) return true;
	else return false;
}

void addLast(List* L, int key) {
	L->size += 1;
	Node* P = L->head;
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->key = key;
	newnode->next = NULL;
	if (P != NULL) {
		while (P->next != NULL) P = P->next;
		P->next = newnode;
	}
	else {
		L->head = newnode;
	}
}
int removeFirst(List* L) {
	L->size -= 1;
	int k = L->head->key;
	Node* P = L->head;
	L->head = P->next;
	free(P);
	return k;
}

List* mergeSort(List* L) {
	if (L->size > 1) {
		Node* L2 = partition(L, L->size / 2);
		L = mergeSort(L);
		L2 = mergeSort(L2);
		L = merge(L, L2);
	}
	return L;
}
List* partition(List* L, int size) {
	List* L2 = (List*)malloc(sizeof(List));
	Node* P = L->head;
	for (int i = 0; i < size-1; i++) {
		P = P->next;
	}
	L2->head = P->next;
	L2->size = L->size - size;
	L->size = size;
	P->next = NULL;
	return L2;
}
List* merge(List* L1, List* L2) {
	List* L = (List*)malloc(sizeof(List));
	L->size = 0, L->head = NULL;
	while ((!isempty(L1)) && (!isempty(L2))) {
		if (L1->head->key > L2->head->key) addLast(L, removeFirst(L2));
		else addLast(L, removeFirst(L1));
	}
	while (!isempty(L1))
		addLast(L, removeFirst(L1));
	while (!isempty(L2))
		addLast(L, removeFirst(L2));
	return L;
}

void print_list(List* list) {
	Node* P = list->head;
	for (int i = 0; i < list->size; i++) {
		printf(" %d", P->key);
		P = P->next;
	}
	printf("\n");
}

void insert_key(List* L) {
	int x;
	for (int i = 0; i < L->size; i++) {
		scanf("%d", &x);
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->key = x;
		newnode->next = NULL;
		if (L->head == NULL) {
			L->head = newnode;
		}
		else {
			Node* P = L->head;
			while (P->next != NULL) P = P->next;
			P->next = newnode;
		}
	}
}
