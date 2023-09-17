#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

// 단일노드
typedef struct node {
	struct node* next;
	int data;
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
void push(Stack* stack, int n) {
	Node* head = (Node*)malloc(sizeof(Node));
	head = stack->head;
	for (int i = 0; i < stack->size; i++) {
		head = head->next;
	}
	Node* new_node = (Node*)malloc(sizeof(Node));
	head->next = new_node;
	new_node->data = n;
	new_node->next = NULL;
	stack->size += 1;

	return;
}


// 스택 맨 위의 데이터 반환 후 삭제
int pop(Stack* stack) {
	int ch;
	if (stack->size == 0) {
		printf("Error\n");
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
	if (n >= '1' && n <= '9')
		return 1;
	else return 0;
}

// 문자를 숫자로 바꿔주는 함수
int change_to_num(char str) {
	if (str == '1')
		return 1;
	else if (str == '2')
		return 2;
	else if (str == '3')
		return 3;
	else if (str == '4')
		return 4;
	else if (str == '5')
		return 5;
	else if (str == '6')
		return 6;
	else if (str == '7')
		return 7;
	else if (str == '8')
		return 8;
	else if (str == '9')
		return 9;
	else return 0;

}

// 계산해주는 함수
int doOperator(char str, int x, int y) {
	int res;
	switch (str) {
		case '+':
			res = x + y;
			break;
		case '-':
			res = x - y;
			break;
		case '*' :
			res = x * y;
			break;
		case '/' :
			res = x / y;
			break;
		default :
			printf("Error\n");
			return 0;
	}

	return res;
}

// 후위 수식 계산 함수
void evaluate(char* str) {
	int a = 0 , b = 0;
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	init(stack);

	for (int i = 0; i < strlen(str); i++) {
		if (isOperand(str[i])) {
			push(stack, change_to_num(str[i]));
		}
		else {
			a = pop(stack);
			b = pop(stack);
			push(stack, doOperator(str[i], b, a));
		}
	}
	printf("%d\n", pop(stack));
	
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
		evaluate(str);
	}


	return 0;
}