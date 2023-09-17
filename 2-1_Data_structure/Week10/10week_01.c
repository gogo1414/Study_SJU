#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

// ���ϳ��
typedef struct node {
	struct node* next;
	char data;
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

// ���� �� ���� �ִ� ������ ��ȯ
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

// ���� �� ���� ������ ��ȯ �� ����
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

// �ǿ����� ������ ����
int isOperand(char n) {
	if (n >= 65 && n <= 90)
		return 1;
	else return 0;
}

// a�� top b�� str / ������ �켱���� ���� �Լ�
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

// ������������ ���� ��ȯ
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
			} // ���׿����� ó���� ���� ���� ���ǹ�
			if (str[i + 1] == '&' || str[i + 1] == '|') // �������ڰ� ���ڰ� 2���� �̷��� ó����.
				push(stack, str[++i]);
		}
	}
	while(stack->size != 0)
		printf("%c", pop(stack));
	printf("\n");
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
		convert(str);
	}
	

	return 0;
}