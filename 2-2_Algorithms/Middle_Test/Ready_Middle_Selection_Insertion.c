#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

/* in-place Selection Sort + in-place in-place inserting Sort
* 리스트로 구현한 버전이다.
* 제자리 선택 정렬의 특징은 앞 부분이 정렬로 유지되어 있다는 것이지만 교환은 각 한번씩만 이뤄진다.
* 제자리 삽입 정렬의 특징은 앞 부분이 정렬되어 있다는 것은 동일하나 교환이 매번 이뤄진다.
*/

typedef struct node {
	struct node* next;
	int data;
}Node;

void insert_data(Node*, int);
void print_list(Node*);
void selection_sort(Node*);
void swap_Elements(Node*, Node*);
void insertion_sort(Node*);
bool isempty(Node*);

int cnt1 = 0, cnt2 = 0;

int main() {
	int n, x;
	scanf("%d", &n);

	Node* list = (Node*)malloc(sizeof(Node));
	list->next = NULL;

	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		insert_data(list, x);
	}
	//selection_sort(list);
	insertion_sort(list);
	print_list(list);

	return 0;
}

bool isempty(Node* node) {
	if (node == NULL) return true;
	else return false;
}
void swap_Elements(Node* H, Node* Q) {
	int tmp = H->data;
	H->data = Q->data;
	Q->data = tmp;
}
void print_list(Node* list) {
	Node* H = list;
	while (!isempty(H->next)) {
		printf(" %d", H->data);
		H = H->next;
	}
	printf("\n");
}
void insert_data(Node* list, int data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->next = NULL;
	Node* H = list;

	if (isempty(H->next))
		H->data = data;
	else {
		while (!isempty(H->next))
			H = H->next;
		H->data = data;

	}
	H->next = newnode;
}

void selection_sort(Node* list) { // 제자리 선택 정렬
	Node* H, *P, *Q;
	int x;
	for (Node* H = list;!isempty(H->next->next); H = H->next) {
		for (P = H->next, Q = H; !isempty(P->next); P = P->next) {
			if (Q->data > P->data)
				Q = P;
		}
		swap_Elements(H, Q);
	}
}

void insertion_sort(Node* list) { // 제자리 삽입 정렬
	Node* P, * Q;
	for (P = list->next; !isempty(P->next); P = P->next) {
		for (Q = list; Q != P; Q = Q->next) {
			if (Q->data > P->data) 
				swap_Elements(Q, P);
		}
	}
}