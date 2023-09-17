#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node { // node 구조
	struct node* prev;
	char data;
	struct node* next;
} Node;

typedef struct list { // head와 tail 먼저 생성
	Node* head;
	Node* tail;
	int n;
} List;

struct Node* init() { // 초기화 함수
	Node* head = (Node*)malloc(sizeof(Node));
	Node* tail = (Node*)malloc(sizeof(Node));

	head->next = tail; // 주소 앞과 뒤를 각각 잘 선정
	tail->prev = head;

	List* list = (List*)malloc(sizeof(List));

	list->n = 0;

}

void add() {

}

void print(struct node* list) {
	struct node* p = (struct node*)malloc(sizeof(struct node));
	p = list->head;
}

int main() {
	int n;
	scanf("%d", &n);
	struct node* list = init();
	
	print(list);

}