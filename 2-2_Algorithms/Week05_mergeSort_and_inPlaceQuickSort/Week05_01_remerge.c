#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* 단일연결리스트를 이용하여 합병 정렬 구현
* 잘 하지 않는 실수들을 많이 저질렀다. 문제를 끝까지 읽지 않은 점과 단일연결리스트의
* 구조를 헷갈린 점 그 외에 편협한 생각에 빠져 한가지만 고민하다가 시간을 오래 끌었다.
* 단일연결리스트의 구조체를 또 하나 생성해서 풀고자 했지만 partition부분을 해결 불가능
* 하다고 느껴 재귀 형태의 방식으로 구현했다.
*/

// 단일연결리스트를 위한 노드 구조체
typedef struct node {
	struct node* next;
	int data;
} Node;

void addList(Node**, int); // 노드 연결하기
void printlist(Node*); // 리스트 출력
void freelist(Node*); // 메모리 해제
void mergeSort(Node**, int); // 합병 정렬
Node* merge(Node*, Node*); // 통치 (재귀 사용)
void partition(Node*,Node**, Node**, int); // 분할

int main() {
	Node* root = NULL;

	int n, x;
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		addList(&root,x);
	}

	mergeSort(&root, n);
	printlist(root);
	freelist(root);
	return 0;
}

void addList(Node** root, int elem) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = elem;
	newnode->next = NULL;

	Node* H = *root;
	if (*root == NULL) {
		*root = newnode;
	}
	else {
		while (H->next != NULL) {
			H = H->next;
		}
		H->next = newnode;
	}
}

void printlist(Node* root) {
	Node* H = root;
	while (H != NULL) {
		printf(" %d", H->data);
		H = H->next;
	}
}

void freelist(Node* root) {
	Node* H = root;
	while (H != NULL) {
		Node* S = H->next;
		free(H);
		H = S;
	}
}

void mergeSort(Node** L, int size) {
	Node* L1, * L2, *H = *L;

	if (size > 1) {
		partition(H, &L1, &L2, size);
		if (size % 2 == 0) {
			mergeSort(&L1, size/2);
			mergeSort(&L2, size/2);
		}
		else { 
			mergeSort(&L1, size / 2);
			mergeSort(&L2, (size / 2) + 1); // 데이터가 홀수 개일 경우 L2에 쏠리기 때문에 이를 방지하고자 함
		}
		*L = merge(L1, L2);
	}
	return;
}

Node* merge(Node* L1, Node* L2) {
	Node* L = NULL;
	
	// 한쪽이 비면 다른 쪽을 반환시킨다.
	if (L1 == NULL)
		return L2;
	else if (L2 == NULL)
		return L1;
	
	
	// L의 다음 주소의 데이터를 재귀로 계속해서 채워준다.
	if (L1->data < L2->data) {
		L = L1;
		L->next = merge(L1->next, L2);
	}
	else {
		L = L2;
		L->next = merge(L1, L2->next);
	}

	return L;
}

void partition(Node* L, Node** L1, Node** L2, int k) {
	Node* H = L;

	*L1 = L;
	// 아래 방식처럼 리스트 자체를 양분한다는 생각을 못해 데이터를 새로 넣어주는 리스트
	// 를 구현하고 있었다....
	for (int i = 0; i < (k / 2) - 1; i++) {
		H = H->next;
	}
	*L2 = H->next;
	H->next = NULL;
} 