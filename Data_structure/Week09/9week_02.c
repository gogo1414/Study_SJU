#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

// 스택의 구조
typedef struct stack {
	char* array;
	int top;
	int size;
}Stack;

// 스택을 초기화 한다.
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

// 문자 비교 후 맞으면 스택에서 제거 후 1반환 틀리면 0반환
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

	Stack* stack = init(size); // 선언과 동시에 초기화

	scanf("%[^\n]s", &s); // 엔터가 나오기 전까지 문자열을 입력받는다.
	for (i = 0; i < strlen(s); i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') { // stack에 원소 추가
			push(stack, s[i]);
			cnt++;
		}
		else if (s[i] == ')' || s[i] == '}' || s[i] == ']') { // stack에 원소 추가
			t = counterparts(stack, s[i]);
			cnt++;
		}
	}
	
	//조건을 두가지로 둔 이유는 아예 존재하지 않을 경우를 대비한 것이다.
	if (t == 0 || stack->top > -1)
		printf("Wrong_%d", cnt);
	else
		printf("OK_%d", cnt);

	return 0;
}