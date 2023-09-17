#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

// 큐 구조
typedef struct node {
	struct node* next;
	int data;
	struct node* prev;
} Node;

// 큐 구조를 자유롭게 사용하기 위해 선언
// 초기화는 따로 하지 않았는데 이유는 문제에서 아무것도 없는 상태로 보이기 때문이다.
Node* front, * rear, * deque;

// deque의 앞에 원소 n을 추가
void add_front(int n) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = n;
	new_node->prev = NULL;
	new_node->next = front;
	front->prev = new_node;
	front = new_node; 
	// front가 데크에 위치 해있다가 노드가 추가될 때 front 위치도 해당 노드로 이동한다.
	return;
}

// deque의 뒤에 원소 n을 추가
void add_rear(int n) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = n;
	new_node->prev = rear;
	new_node->next = NULL;
	rear->next = new_node;
	rear = new_node;
	return;
}

// deque의 앞 원소 삭제
void delete_front(int size) {
	Node* p;
	if (size == 0) {
		printf("underflow\n");
		exit(0);
	}
	else {
		p = front;
		// 노드 삭제
		if (size == 1) free(p);
		else { 
			front = front->next;
			front->prev = NULL;
			free(p);
		}
	}
	return;
}

// deque의 뒤 원소 삭제
void delete_rear(int size) {
	Node* p;
	if (size == 0) {
		printf("underflow\n");
		exit(0);
	}
	else {
		p = rear;
		// 노드 삭제
		if (size == 1) free(p);
		else {
			rear = rear->prev;
			rear->next = NULL;
			free(p);
		}
	}
	return;
}

// deque의 앞부터 출력
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

// 할당 메모리 해제 함수
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
			if (deque_size == 0) { // 첫 deque의 노드
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
			if (deque_size == 0) { // 첫 deque의 노드
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
// 맨 처음에 아무 노드도 없을 때는 빈 공간이 였다가 첫 노드deque가 생기면 front와 rear 는 deque를
// 향한다. 그리고 추가로 노드가 생길 때 마다 front와 rear가 이동한다. 그림으로 봤을땐 front와 rear
// 따로 있는 줄 알았으나 아니라는 것을 알았다...
// front와 rear는 항상 각각 맨 앞과 맨 뒤 에 존재하기 때문에 큐 끝에 존재한다.

/* front rear 노드를 main 에 선언 해서 add 함수에 받아서 사용했을 때 작동은 되지만 add함수
와 print delete가 작동하지 않는 문제가 생겼는데, 노드를 먼저 선언한 뒤에 사용하니 해결됐다.
원인을 생각 해봤을 때 front로 받았을 때 크기가 넘어선 위치로 받아지거나 노드해제가 다른 
위치에서 실행되는거 같다. */