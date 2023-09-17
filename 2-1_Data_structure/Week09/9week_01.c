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

// 원소를 추가하는 함수
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

// 탑의 원소를 반환한 후 제거한다. 비어 있으면 "Stack Empty" 출력
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

// stack의 top 원소 화면에 출력
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

// stack의 top 원소 pop 한후 두 번 push *stack 꽉 차있으면 "Stack FULL" 출력
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

// stack 맨 위 n개 원소 위로 회전
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

// stack 맨 위 n개 원소 아래로 회전
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

// stack의 모든 원소 출력
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
	Stack* stack = init(size); // 선언과 동시에 초기화

	scanf("%d", &A); // 연산의 개수
	for (int i = 0; i < A; i++) {
		getchar(); // enter 방지
		scanf("%s", &s); // 연산 입력

		if (strcmp(s, "PUSH") == 0) { // stack에 원소 추가
			getchar();
			scanf("%c", &a);
			push(stack, a);
		}
		else if (strcmp(s, "PRINT") == 0) { // 출력
			print(stack);
		}
		else if (strcmp(s, "POP") == 0) { // 원소 반환 후 stack 제거
			pop(stack);
		}
		else if (strcmp(s, "UpR") == 0) { // stack 맨 위 n개 원소 회전 위
			scanf("%d", &d);
			upRotate(stack, d);
		}
		else if (strcmp(s, "DownR") == 0) { // stack 맨 위 n개 원소 회전 아래
			scanf("%d", &d);
			downRotate(stack, d);
		}
		else if (strcmp(s, "PEEK") == 0) { // top 원소 화면 출력
			peek(stack);
		}
		else if (strcmp(s, "DUP") == 0) { // top 원소 pop해서 2번 push
			duplicate(stack);
		}
	}

	return 0;
}