#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

// ť ����
typedef struct queue {
	int size;
	int* data;
	int front;
	int rear;
} Queue;

// ť �ʱ�ȭ
void init(Queue* que, int size) {
	que->size = size;
	que->front = 0;
	que->rear = 0;
	que->data = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < que->size; i++)
		que->data[i] = 0;
	return;
}

// �迭�� ������ ť�� ��� ������ ���
void print(Queue* que) {
	for (int i = 0; i < que->size; i++)
		printf(" %d", que->data[i]);
	printf("\n");

	return;
}


// ť�� ������ �������ִ� �Լ�
void enqueue(Queue* que, int data) {
	if ((que->rear == (que->size - 1) && que->front == 0) || ((que->rear + 1) == (que->front))) {
		printf("overflow");
		print(que);
		exit(0);
	}
	que->data[++que->rear] = data;
	if ((que->rear + 1) == que->size) que->rear = -1;
	return;
}

// ť �ȿ� �ִ� ������ ����
void dequeue(Queue* que) {
	if (que->rear == que->front) {
		printf("underflow");
		exit(0);
	}

	que->data[++que->front] = 0;
	if (que->front == que->size) que->front = 0;
	return;
}

int main() {
	int size, n, da, front = 0, rear = 0;
	char ch;

	// ����� �Է� �ް� �迭�� ť ����
	scanf("%d", &size);
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	init(queue, size);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c", &ch);
		if (ch == 'I') {
			scanf("%d", &da);
			enqueue(queue, da);
		}
		else if (ch == 'D') {
			dequeue(queue);
		}
		else if (ch == 'P') {
			print(queue);
		}
	}
	free(queue);

	return 0;
}