#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* 단일 연결리스트로 구현한 합병정렬
* 이 문제를 풀면서 내가 생각하는 최대의 난제는 partition 부분이다.
* 문제를 어떻게 풀 지 생각하면서 나만의 방식대로 한 것이 아니라 의사코드를 보면서 따라했기 때문에
* 해당 코드에 맞는 partition을 짜는 것이 고역이였다..
* 다양한 방법을 시도했는데 size가 아닌 node의 next가 NULL인지 여부로 시도하려고 했지만, 작동이 되나
* 리스트가 짤려서 나오는 문제가 발생했다... 결과적으로 size를 유지하기로 하고 이것 저것 바꾸고
* 교수님이 힌트를 주신 글을 참고하여 작성했다.
*/

typedef struct node {
	int data;
	struct node* next;
}Node;

typedef struct linekdList {
	Node* head;
	int size;
}linkedList;

void set_linkedList(linkedList*, int); // n개의 데이터 입력
void print_linkedList(linkedList*); // list 출력
void free_linkedList(linkedList*); // list의 노드와 list 자체 메모리 해제
int removefirst_linkedList(linkedList*); // list의 첫 노드 삭제
void addLast_linkedList(linkedList*, int); // list의 뒤로 삽입

linkedList* partition(linkedList* L, int); // 분할
linkedList* merge(linkedList*, linkedList*); // 통치
linkedList* mergeSort(linkedList*); // 재귀

int main() {
	int n, x;
	linkedList* L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL, L->size = 0;
	scanf("%d", &n);
	
	set_linkedList(L, n);
	L = mergeSort(L);
	print_linkedList(L);

	return 0;
}

void set_linkedList(linkedList* L, int n) {
	int x;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		addLast_linkedList(L, x);
	}
}
void print_linkedList(linkedList* L) {
	Node* H = L->head;
	while (H != NULL) {
		printf(" %d", H->data);
		H = H->next;
	}
	printf("\n");
}
void free_linkedList(linkedList* L) {
	Node* H = L->head;
	while (H != NULL) {
		Node* S = H->next;
		free(H);
		H = S;
	}
	free(L);
}
int removefirst_linkedList(linkedList* L) {
	if (L->head == NULL)
		return 0;
	Node* S = L->head;
	int n = S->data;
	L->head = S->next;
	free(S);
	L->size -= 1;
	return n;
}
void addLast_linkedList(linkedList* L, int x) {
	if (L->head == NULL) {
		Node* newnode = (Node*)malloc(sizeof(Node));
		L->head = newnode;
		newnode->data = x;
		newnode->next = NULL;
	}
	else {
		Node* newnode = (Node*)malloc(sizeof(Node));
		Node* H = L->head;
		while (H->next != NULL)
			H = H->next;
		newnode->data = x;
		newnode->next = NULL;
		H->next = newnode;		
	}
	L->size += 1;
}

// 세 함수를 보면 모두 리스트를 반환하고 있다.
// 따라서 mergeSort를 사용할 때 맞는 리스트로 받는 것이 중요하다.
linkedList* partition(linkedList* L, int k) {
	linkedList* L2 = (linkedList*)malloc(sizeof(linkedList));
	Node* H = L->head;
	for (int i = 0; i < k-1; i++) {
		H = H->next;
	}
	L2->head = H->next;
	L2->size = L->size - k; // 사이즈를 이렇게 했으면 되는 일을 노드를 삭제하고 **** 아무튼 잘 됐다.
	L->size = k; 
	H->next = NULL; // 중간 부분에서 자르기
	return L2;
}

linkedList* merge(linkedList* L1, linkedList* L2) {
	linkedList* L3 = (linkedList*)malloc(sizeof(linkedList));
	L3->size = 0, L3->head = NULL;
	while (L1->head != NULL && L2->head != NULL) {
		if (L1->head->data <= L2->head->data) {
			addLast_linkedList(L3, removefirst_linkedList(L1));
		}
		else {
			addLast_linkedList(L3, removefirst_linkedList(L2));
		}
	}
	while (L1->head != NULL)
		addLast_linkedList(L3, removefirst_linkedList(L1));
	while (L2->head != NULL)
		addLast_linkedList(L3, removefirst_linkedList(L2));
	return L3;
}

linkedList* mergeSort(linkedList* L) {
	if (L->size > 1) {
		linkedList* L2 = partition(L, L->size/2);
		L = mergeSort(L);
		L2 = mergeSort(L2);
		L = merge(L, L2);
	}
	return L;
}
