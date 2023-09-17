#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct node {
	struct node* next;
	int student_id, book_id, year, month, day;
	struct node* prev;
} Node;

typedef struct list {
	Node* head;
//	Node* tail;
	int n;
} List;

void init(List* list) {
	Node* head = (Node*)malloc(sizeof(Node));
	Node* tail = (Node*)malloc(sizeof(Node));
	
	list->head = head;
//	list->tail = tail;
	head->next = NULL;
	head->prev = NULL;

//	tail->next = NULL;
//	tail->prev = head;

	list->n = 0;
}

void add(List* list, int stu, int book, int year, int month, int day) {
	Node* p = list->head;
	for (int i = 0; i < list->n; i++) {
		p = p->next;
	}
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->student_id = stu;
	new_node->book_id = book;
	new_node->year = year;
	new_node->month = month;
	new_node->day = day;
	

	new_node->prev = p;
	new_node->next = NULL;

	list->n = list->n + 1;
	return;
}

void print(List* list, int year, int month, int day) {
	Node* p = list->head;
	for (int i = 0; i < list->n; i++) {
		p = p->next;
		if ((p->year % 4) == 0 && (p->year % 100 != 0) || p->year % 400) {
			if (year == 2) {
				if(month -)
			}
			else if (year == 4 || year == 6 || year == 9 || year == 11) {

			}
			else {

			}
		}
		else {
			if (year == 2) {

			}
			else if (year == 4 || year == 6 || year == 9 || year == 11) {

			}
			else {

			}
				
		}
	}
}

int main() {
	char N;
	int stu_id, book_id, year, month, day;
	List* list = (List*)malloc(sizeof(List));
	while (1) {
		scanf("%c", &N);
		if(N == 'A'){
			scanf("%d %d %d-%d-%d", &stu_id, &book_id, &year, &month, &day);
//			printf("%d %d %d-%d-%d\n", stu_id, book_id, year, month, day);
			add(list, stu_id, book_id, year, month, day);
		}
		
		if (N == 'P') {
			scanf("%d-%d-%d", &year, &month, &day);
			print(list, year, month, day);
		}
		if (N == 'Q') {
			break;
		}
		getchar();
	}
	
	return 0;
}