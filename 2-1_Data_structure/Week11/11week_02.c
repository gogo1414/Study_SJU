#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

// ť ����
typedef struct node {
	struct node* next;
	int data;
	struct node* prev;
} Node;

// ť ������ �����Ӱ� ����ϱ� ���� ����
// �ʱ�ȭ�� ���� ���� �ʾҴµ� ������ �������� �ƹ��͵� ���� ���·� ���̱� �����̴�.
Node* front, * rear, * deque;

// deque�� �տ� ���� n�� �߰�
void add_front(int n) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = n;
	new_node->prev = NULL;
	new_node->next = front;
	front->prev = new_node;
	front = new_node; 
	// front�� ��ũ�� ��ġ ���ִٰ� ��尡 �߰��� �� front ��ġ�� �ش� ���� �̵��Ѵ�.
	return;
}

// deque�� �ڿ� ���� n�� �߰�
void add_rear(int n) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = n;
	new_node->prev = rear;
	new_node->next = NULL;
	rear->next = new_node;
	rear = new_node;
	return;
}

// deque�� �� ���� ����
void delete_front(int size) {
	Node* p;
	if (size == 0) {
		printf("underflow\n");
		exit(0);
	}
	else {
		p = front;
		// ��� ����
		if (size == 1) free(p);
		else { 
			front = front->next;
			front->prev = NULL;
			free(p);
		}
	}
	return;
}

// deque�� �� ���� ����
void delete_rear(int size) {
	Node* p;
	if (size == 0) {
		printf("underflow\n");
		exit(0);
	}
	else {
		p = rear;
		// ��� ����
		if (size == 1) free(p);
		else {
			rear = rear->prev;
			rear->next = NULL;
			free(p);
		}
	}
	return;
}

// deque�� �պ��� ���
void print(int size) {
	Node* p = front;
	if (p == NULL || size == 0) {
//		printf("Error");
		exit(0);
	}
	for (int i = 0; i < size; i++) {
		printf(" %d", p->data);
		p = p->next;
	}
	printf("\n");
	return;
}

// �Ҵ� �޸� ���� �Լ�
void free_all(int size) {
	Node* p = front;
	for (int i = 0; i < size;i++) {
		front = front->next;
		free(p);
		p = front;
	}
	return;
}

int main() {
	int n, da, deque_size = 0;
	char ch[5];
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%s", &ch);
		if (strcmp(ch,"AF") == 0) {
			scanf("%d", &da);
			if (deque_size == 0) { // ù deque�� ���
				deque = (Node*)malloc(sizeof(Node));
				deque->next = NULL;
				deque->prev = NULL;
				deque->data = da;
				front = deque;
				rear = deque;
				deque_size++;
			}
			else {
				add_front(da);
				deque_size++;
			}
		}
		else if (strcmp(ch, "AR") == 0) {
			scanf("%d", &da);
			if (deque_size == 0) { // ù deque�� ���
				deque = (Node*)malloc(sizeof(Node));
				deque->next = NULL;
				deque->prev = NULL;
				deque->data = da;
				front = deque;
				rear = deque;
				deque_size++;
			}
			else {
				add_rear(da);
				deque_size++;
			}
		}
		else if (strcmp(ch, "DF") == 0) {
			delete_front(deque_size);
			deque_size--;
		}
		else if (strcmp(ch, "DR") == 0) {
			delete_rear(deque_size);
			deque_size--;
		}
		else if (strcmp(ch, "P") == 0) {
			print(deque_size);
		}
	}

	free_all(deque_size);
	
	return 0;
}
// �� ó���� �ƹ� ��嵵 ���� ���� �� ������ ���ٰ� ù ���deque�� ����� front�� rear �� deque��
// ���Ѵ�. �׸��� �߰��� ��尡 ���� �� ���� front�� rear�� �̵��Ѵ�. �׸����� ������ front�� rear
// ���� �ִ� �� �˾����� �ƴ϶�� ���� �˾Ҵ�...
// front�� rear�� �׻� ���� �� �հ� �� �� �� �����ϱ� ������ ť ���� �����Ѵ�.

/* front rear ��带 main �� ���� �ؼ� add �Լ��� �޾Ƽ� ������� �� �۵��� ������ add�Լ�
�� print delete�� �۵����� �ʴ� ������ ����µ�, ��带 ���� ������ �ڿ� ����ϴ� �ذ�ƴ�.
������ ���� �غ��� �� front�� �޾��� �� ũ�Ⱑ �Ѿ ��ġ�� �޾����ų� ��������� �ٸ� 
��ġ���� ����Ǵ°� ����. */