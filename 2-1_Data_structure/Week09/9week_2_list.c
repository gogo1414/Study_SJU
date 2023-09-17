#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int cnt = 0;

typedef struct node {
	struct node* next;
	char data;
}Node;

typedef struct stack {
	Node* top;
}Stack;

void init(Stack* sta) {
	sta->top = NULL;
	return;
}

bool is_empty(Stack* sta) {
	return sta->top == NULL;
}

void push(Stack* sta, char s) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = s;
	p->next = sta->top;

	sta->top = p;

	return;
}

char pop(Stack* sta) {
	if (is_empty(sta)) {
		printf("error");
		exit(0);
	}
	else {
		Node* p = sta->top;
		char c = p->data;
		sta->top = p->next;
		free(p);
		return c;
	}
}

void count(char s) {
	switch (s) {
	case '(': cnt++; return;
	case '{': cnt++; return;
	case '[': cnt++; return;
	case ')': cnt++; return;
	case '}': cnt++; return;
	case ']': cnt++; return;
	default: return;
	}
}

bool isopensymbol(char c) {
	switch (c) {
	case '(': return true;
	case '{': return true;
	case '[': return true;
	default: return false;
	}
}

bool isclosesymbol(char c) {
	switch (c) {
	case ')': return true;
	case '}': return true;
	case ']': return true;
	default: return false;
	}
}

bool isCounterpart(char a, char b) {
	if (((a == '(') && (b == ')')) || ((a == '{') && (b == '}')) || ((a == '[') && (b == ']')))
		return true;
	else
		return false;
}

void print(Stack* sta) {
	for (Node* p = sta->top; p != NULL; p = p->next) {
		printf("%c", p->data);
	}
	printf("\n");
	return;
}

char getsymbol(Stack* sta) {
	return sta->top;
}


int main() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	init(stack);

	char str[1001];
	char s, t;
	int ch = 0;
	scanf("%[^\n]s", &str);

	for (int i = 0; i < strlen(str); i++) {
		count(str[i]);
	}
	for (int i = 0; i < strlen(str); i++) {
		if (isopensymbol(str[i]))
			push(stack, str[i]);
		else if (isclosesymbol(str[i])) {
			if (is_empty(stack)) {
				printf("Wrong_%d", cnt);
				exit(0);
			}
			t = pop(stack);
			if (!isCounterpart(t, str[i])) {
				printf("Wrong_%d", cnt);
				exit(0);
			}
		}
	}


	if (stack->top != NULL)
		printf("Wrong_%d", cnt);
	else
		printf("OK_%d", cnt);

	return 0;
}