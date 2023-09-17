#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct node {
	char* array;
	int top;
	int size;
}Stack;

Stack* init(int size) {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->array = (char*)malloc(sizeof(char) * size);
	stack->top = -1;
	stack->size = size;
	return stack;
}

// ���Ҹ� �߰��ϴ� �Լ�
void push(Stack* sta, char s) {
	if (sta->top == sta->size - 1) {
		printf("Stack FULL\n");
		return;
	}
	else {
		sta->top = sta->top + 1;
		sta->array[sta->top] = s;
		return;
	}
}

// ž�� ���Ҹ� ��ȯ�� �� �����Ѵ�. ��� ������ "Stack Empty" ���
char pop(Stack* sta) {
	char res;
	if (sta->top == -1) {
		printf("Stack Empty\n");
		return;
	}
	else {
		res = sta->array[sta->top];
		sta->top = sta->top - 1;
		return res;
	}
}

// stack�� top ���� ȭ�鿡 ���
void peek(Stack* sta) {
	if (sta->top == -1) {
		printf("Stack Empty\n");
		return;
	}
	else {
		printf("%c\n", sta->array[sta->top]);
		return;
	}
}

// stack�� top ���� pop ���� �� �� push *stack �� �������� "Stack FULL" ���
void duplicate(Stack* sta) {
	if (sta->top == sta->size - 1) {
		printf("Stack FULL\n");
		return;
	}
	else if (sta->top == -1) {
		printf("Stack Empty\n");
		return;
	}
	char s = pop(sta);
	push(sta, s);
	push(sta, s);
	return;
}

// stack �� �� n�� ���� ���� ȸ��
void upRotate(Stack* sta, int n) {
	if (n > sta->top + 1)
		n = sta->top;
	char temp = sta->array[sta->top];
	int i;
	for (i = 0; i < n - 1; i++) {
		sta->array[sta->top - i] = sta->array[sta->top - i - 1];
	}
	sta->array[sta->top - n + 1] = temp;
	return;
}

// stack �� �� n�� ���� �Ʒ��� ȸ��
void downRotate(Stack* sta, int n) {
	if (n > sta->top + 1)
		n = sta->top;
	char temp = sta->array[sta->top - n + 1];
	int i;
	for (i = n - 1; i > 0; i--) {
		sta->array[sta->top - i] = sta->array[sta->top - i + 1];
		// 1 2 2 3 3 4 4 5
	}
	sta->array[sta->top] = temp;
	return;
}

// stack�� ��� ���� ���
void print(Stack* sta) {
	if (sta->top == -1) {
		return;
	}
	for (int i = sta->top; i >= 0; i--)
		printf("%c", sta->array[i]);
	printf("\n");
	return;
}


int main() {
	int size, A, d;
	char s[10], a;

	scanf("%d", &size);
	Stack* stack = init(size); // ����� ���ÿ� �ʱ�ȭ

	scanf("%d", &A); // ������ ����
	for (int i = 0; i < A; i++) {
		getchar(); // enter ����
		scanf("%s", &s); // ���� �Է�

		if (strcmp(s, "PUSH") == 0) { // stack�� ���� �߰�
			getchar();
			scanf("%c", &a);
			push(stack, a);
		}
		else if (strcmp(s, "PRINT") == 0) { // ���
			print(stack);
		}
		else if (strcmp(s, "POP") == 0) { // ���� ��ȯ �� stack ����
			pop(stack);
		}
		else if (strcmp(s, "UpR") == 0) { // stack �� �� n�� ���� ȸ�� ��
			scanf("%d", &d);
			upRotate(stack, d);
		}
		else if (strcmp(s, "DownR") == 0) { // stack �� �� n�� ���� ȸ�� �Ʒ�
			scanf("%d", &d);
			downRotate(stack, d);
		}
		else if (strcmp(s, "PEEK") == 0) { // top ���� ȭ�� ���
			peek(stack);
		}
		else if (strcmp(s, "DUP") == 0) { // top ���� pop�ؼ� 2�� push
			duplicate(stack);
		}
	}

	return 0;
}