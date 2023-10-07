#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* ���� ���Ḯ��Ʈ�� ������ �պ�����
* �� ������ Ǯ�鼭 ���� �����ϴ� �ִ��� ������ partition �κ��̴�.
* ������ ��� Ǯ �� �����ϸ鼭 ������ ��Ĵ�� �� ���� �ƴ϶� �ǻ��ڵ带 ���鼭 �����߱� ������
* �ش� �ڵ忡 �´� partition�� ¥�� ���� ���̿���..
* �پ��� ����� �õ��ߴµ� size�� �ƴ� node�� next�� NULL���� ���η� �õ��Ϸ��� ������, �۵��� �ǳ�
* ����Ʈ�� ©���� ������ ������ �߻��ߴ�... ��������� size�� �����ϱ�� �ϰ� �̰� ���� �ٲٰ�
* �������� ��Ʈ�� �ֽ� ���� �����Ͽ� �ۼ��ߴ�.
*/

typedef struct node {
	int data;
	struct node* next;
}Node;

typedef struct linekdList {
	Node* head;
	int size;
}linkedList;

void set_linkedList(linkedList*, int); // n���� ������ �Է�
void print_linkedList(linkedList*); // list ���
void free_linkedList(linkedList*); // list�� ���� list ��ü �޸� ����
int removefirst_linkedList(linkedList*); // list�� ù ��� ����
void addLast_linkedList(linkedList*, int); // list�� �ڷ� ����

linkedList* partition(linkedList* L, int); // ����
linkedList* merge(linkedList*, linkedList*); // ��ġ
linkedList* mergeSort(linkedList*); // ���

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

// �� �Լ��� ���� ��� ����Ʈ�� ��ȯ�ϰ� �ִ�.
// ���� mergeSort�� ����� �� �´� ����Ʈ�� �޴� ���� �߿��ϴ�.
linkedList* partition(linkedList* L, int k) {
	linkedList* L2 = (linkedList*)malloc(sizeof(linkedList));
	Node* H = L->head;
	for (int i = 0; i < k-1; i++) {
		H = H->next;
	}
	L2->head = H->next;
	L2->size = L->size - k; // ����� �̷��� ������ �Ǵ� ���� ��带 �����ϰ� **** �ƹ�ư �� �ƴ�.
	L->size = k; 
	H->next = NULL; // �߰� �κп��� �ڸ���
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
