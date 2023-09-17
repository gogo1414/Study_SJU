#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

// ���ϳ��
typedef struct node {
	struct node* next;
	int data;
}Node;

// ���ϳ�� ����
typedef struct stack {
	Node* head;
	int size;
} Stack;

// ���� �ʱ�ȭ
Stack* init(Stack* stack) {
	Node* head = (Node*)malloc(sizeof(Node));
	Node* tail = (Node*)malloc(sizeof(Node));

	stack->head = head;
	head->next = NULL;

	stack->size = 0;

	return;
}

// ���ÿ� ������ �ױ�
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


// ���� �� ���� ������ ��ȯ �� ����
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

// �ǿ����� ������ ����
int isOperand(char n) {
	if (n >= '1' && n <= '9')
		return 1;
	else return 0;
}

// ���ڸ� ���ڷ� �ٲ��ִ� �Լ�
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

// ������ִ� �Լ�
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

// ���� ���� ��� �Լ�
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

// ���� �Լ�
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