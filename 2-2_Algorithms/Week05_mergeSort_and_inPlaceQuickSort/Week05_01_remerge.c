#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* ���Ͽ��Ḯ��Ʈ�� �̿��Ͽ� �պ� ���� ����
* �� ���� �ʴ� �Ǽ����� ���� ��������. ������ ������ ���� ���� ���� ���Ͽ��Ḯ��Ʈ��
* ������ �򰥸� �� �� �ܿ� ������ ������ ���� �Ѱ����� ����ϴٰ� �ð��� ���� ������.
* ���Ͽ��Ḯ��Ʈ�� ����ü�� �� �ϳ� �����ؼ� Ǯ���� ������ partition�κ��� �ذ� �Ұ���
* �ϴٰ� ���� ��� ������ ������� �����ߴ�.
*/

// ���Ͽ��Ḯ��Ʈ�� ���� ��� ����ü
typedef struct node {
	struct node* next;
	int data;
} Node;

void addList(Node**, int); // ��� �����ϱ�
void printlist(Node*); // ����Ʈ ���
void freelist(Node*); // �޸� ����
void mergeSort(Node**, int); // �պ� ����
Node* merge(Node*, Node*); // ��ġ (��� ���)
void partition(Node*,Node**, Node**, int); // ����

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
			mergeSort(&L2, (size / 2) + 1); // �����Ͱ� Ȧ�� ���� ��� L2�� �򸮱� ������ �̸� �����ϰ��� ��
		}
		*L = merge(L1, L2);
	}
	return;
}

Node* merge(Node* L1, Node* L2) {
	Node* L = NULL;
	
	// ������ ��� �ٸ� ���� ��ȯ��Ų��.
	if (L1 == NULL)
		return L2;
	else if (L2 == NULL)
		return L1;
	
	
	// L�� ���� �ּ��� �����͸� ��ͷ� ����ؼ� ä���ش�.
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
	// �Ʒ� ���ó�� ����Ʈ ��ü�� ����Ѵٴ� ������ ���� �����͸� ���� �־��ִ� ����Ʈ
	// �� �����ϰ� �־���....
	for (int i = 0; i < (k / 2) - 1; i++) {
		H = H->next;
	}
	*L2 = H->next;
	H->next = NULL;
} 