#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

// 단일노드
typedef struct node {
	struct node* next;
	char data;
}Node;

// 단일노드 스택
typedef struct stack {
	Node* head;
	int size;
} Stack;

// 스택 초기화
Stack* init(Stack* stack) {
	Node* head = (Node*)malloc(sizeof(Node));
	Node* tail = (Node*)malloc(sizeof(Node));

	stack->head = head;
	head->next = NULL;

	stack->size = 0;

	return;
}

// 스택에 데이터 쌓기
void push(Stack* stack, char n) {
	Node* head = (Node*)malloc(sizeof(Node));
	head = stack->head;
	for(int i=0;i<stack->size;i++) {
		head = head->next;
	}
	Node* new_node = (Node*)malloc(sizeof(Node));
	head->next = new_node;
	new_node->data = n;
	new_node->next = NULL;
	stack->size += 1;

	return;
}

// 스택 맨 위에 있는 데이터 반환
char top(Stack* stack) {
	if (stack->head->next == NULL) {
		return 'a';
	}
	Node* head = (Node*)malloc(sizeof(Node));
	head = stack->head;
	for (int i = 0; i < stack->size; i++)
		head = head->next;

	return head->data;
}

// 스택 맨 위의 데이터 반환 후 삭제
char pop(Stack* stack) {
	char ch;
	if (stack->size == 0) {
		printf("Error");
		return 0;
	}
	Node* head = (Node*)malloc(sizeof(Node));
	head = stack->head;
	for (int i = 0; i < stack->size; i++)
		head = head->next;
	ch = head->data;
	stack->size -= 1;
	return ch;
}

// 피연산자 연산자 구분
int isOperand(char n) {
	if (n >= 65 && n <= 90)
		return 1;
	else return 0;
}

// a가 top b가 str / 연산자 우선순위 결정 함수
int check(char a, char b) {
	if (a == '!') return 1;
	else if (a == '*' || a == '/') {
		if (b == '!') return 0;
		else return 1;
	}
	else if (a == '+' || a == '-') {
		if (b == '*' || b == '/' || b == '!') return 0;
		else return 1;
	}
	else if (a == '<' || a == '>') {
		if (b == '*' || b == '/' || b == '!' || b == '+' || b == '-') return 0;
		else return 1;
	}
	else if (a == '&') {
		if (b == '*' || b == '/' || b == '!' || b == '+' || b == '-' || b == '<' || b == '>') return 0;
		else return 1;
	}
	else if (a == '|') {
		if (b == '*' || b == '/' || b == '!' || b == '+' || b == '-' || b == '<' || b == '>' || b == '&') return 0;
		else return 1;
	}
	else return 0;
}

// 후위수식으로 수식 전환
void convert(char* str) {
	int r = 0;
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	init(stack);

	for (int i = 0; i < strlen(str); i++) {
		if ((str[i] == '+' || str[i] == '-') && i == 0) {
			r = 1;
			push(stack, str[i++]);
		}
		if (isOperand(str[i])) {
			printf("%c", str[i]);
			if (i == 1 && r == 1) {
				printf("%c", pop(stack));
				r = 0;
			}
		}
		else if (str[i] == '(')
			push(stack, str[i]);
		else if (str[i] == ')') {
			while (top(stack) != '(')
				printf("%c", pop(stack));
			pop(stack);
		}
		else {
			while (stack->size != 0 && check(top(stack), str[i])) {
				printf("%c", pop(stack));
				if (top(stack) == '|' || top(stack) == '&')
					printf("%c", pop(stack));
			}
			push(stack, str[i]);
			if ((top(stack) == '+' && str[i + 1] == '-') || (top(stack) == '-' && str[i + 1] == '+') || (top(stack) == '*' || top(stack) == '/') && (str[i+1] == '+' || str[i+1] == '-')) {
				push(stack, str[i+1]);
				i += 1;
			} // 단항연상자 처리를 위해 넣은 조건문
			if (str[i + 1] == '&' || str[i + 1] == '|') // 논리연산자가 문자가 2개라 이렇게 처리함.
				push(stack, str[++i]);
		}
	}
	while(stack->size != 0)
		printf("%c", pop(stack));
	printf("\n");
	return;
}

// 메인 함수
int main() {
	char str[101];
	int a;
	
	scanf("%d", &a);
	getchar();
	for (int i = 0; i < a; i++) {
		scanf("%s", &str);
		convert(str);
	}
	

	return 0;
}