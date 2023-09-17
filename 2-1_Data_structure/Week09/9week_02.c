#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

// ������ ����
typedef struct stack {
	char* array;
	int top;
	int size;
}Stack;

// ������ �ʱ�ȭ �Ѵ�.
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

// ���� �� �� ������ ���ÿ��� ���� �� 1��ȯ Ʋ���� 0��ȯ
int counterparts(Stack* sta, char c) {
	if (sta->array[sta->top] == '(' && c == ')') {
		pop(sta);
		return 1;
	}
	else if (sta->array[sta->top] == '{' && c == '}') {
		pop(sta);
		return 1;
	}
	else if (sta->array[sta->top] == '[' && c == ']') {
		pop(sta);
		return 1;
	}
	else
		return 0;
}

int main() {
	int size=1001, t = 1, i, cnt = 0;
	char s[1002];

	Stack* stack = init(size); // ����� ���ÿ� �ʱ�ȭ

	scanf("%[^\n]s", &s); // ���Ͱ� ������ ������ ���ڿ��� �Է¹޴´�.
	for (i = 0; i < strlen(s); i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') { // stack�� ���� �߰�
			push(stack, s[i]);
			cnt++;
		}
		else if (s[i] == ')' || s[i] == '}' || s[i] == ']') { // stack�� ���� �߰�
			t = counterparts(stack, s[i]);
			cnt++;
		}
	}
	
	//������ �ΰ����� �� ������ �ƿ� �������� ���� ��츦 ����� ���̴�.
	if (t == 0 || stack->top > -1)
		printf("Wrong_%d", cnt);
	else
		printf("OK_%d", cnt);

	return 0;
}