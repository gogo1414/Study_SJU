#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)

/* HashTable �и� ����� ����
* �и� ������� �� �ؽ� ���̺� ���� ���Ḯ��Ʈ�� �̴ϻ����� ����Ǿ� �ִ� �����̴�.
* ���� ����ü�� ���� �Ŀ� ���� �����ϴ� ���·� �����ߴ�.
*/

typedef struct node {
	struct node* next;
	int key;
	int rank;
} Node;

typedef struct hashtable {
	Node* list;
}HashTable;

void HashTable_Insert(HashTable*, int); // HashTable key�� ����
void HashTable_Search(HashTable*, int); // HashTable key�� Ž��
void HashTable_Delete(HashTable*, int); // HashTAble key�� 
void HashTable_Print(HashTable*); // HashTable ��ȸ ���
void free_List(HashTable*); // HashTable�� ����Ʈ �޸� ����

void List_Insert(HashTable* ,int); // HashTable ���Ḯ��Ʈ�� Ű ����
void List_Delete(HashTable*, int); // HashTable ���Ḯ��Ʈ Ű ���� 
void List_Search(HashTable*,int); // HashTable ���Ḯ��Ʈ Ű Ž��
void rank_Update(HashTable*); // HashTable ���Ḯ��Ʈ ���� ��ġ��

int M; // �迭�� ũ��

int main() {
	int c, key;
	HashTable* array = (HashTable*)malloc(sizeof(HashTable));
	scanf("%d", &M);
	
	array = (HashTable*)malloc(sizeof(HashTable) * M);

	for (int i = 0; i < M; i++) // HashTable�� �̴ϻ����� �ʱ�ȭ
		(array + i)->list = NULL;

	while (((c = getchar()) != EOF) && (c != 'e')) {
		if (c == 'i') {
			scanf("%d", &key);
			HashTable_Insert(array, key);
		}
		else if (c == 's') {
			scanf("%d", &key);
			HashTable_Search(array, key);
		}
		else if (c == 'd') {
			scanf("%d", &key);
			HashTable_Delete(array, key);
		}
		else if (c == 'p') {
			HashTable_Print(array);
		}
	}
	free_List(array);
	free(array);

	return 0;
}

void HashTable_Insert(HashTable* array, int key) {
	int i = key % M;
	List_Insert(array+i, key);
}
void HashTable_Search(HashTable* array, int key) {
	int i = key % M;
	List_Search(array+i, key);
}
void HashTable_Delete(HashTable* array, int key) {
	int i = key % M;
	List_Delete(array + i, key);
}
void HashTable_Print(HashTable* array) {
	HashTable* H = array;
	Node* P = NULL;
	for (int i = 0; i < M; i++) {
		if ((H + i)->list != NULL) {
			P = (H + i)->list;
			while (P != NULL) {
				printf(" %d", P->key);
				P = P->next;
			}
		}	
	}
	printf("\n");
}

void List_Insert(HashTable* array, int k) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->key = k;
	if (array->list == NULL) {
		newnode->rank = 1;
		newnode->next = NULL;
	}
	else {
		newnode->next = array->list;
		newnode->rank = 1;
		array->list->rank += 1;
	}	
	array->list = newnode;
}
void List_Search(HashTable* array, int key) {
	Node* P = array->list;
	while (P != NULL) {
		if (P->key == key) {
			printf("%d\n", P->rank);
			return;
		}
		P = P->next;
	}
	printf("0\n");
	return;
}

void List_Delete(HashTable* array, int key) {
	Node* P = array->list, * Q = NULL;
	int check = 0;
	while (P != NULL) {
		if (P->key == key) {
			printf("%d\n", P->rank);
			check = 1;
			break;
		}
		Q = P;
		P = P->next;
	}
	if (Q == NULL && check == 1) {
		array->list = P->next;
		free(P);
	}
	else if (Q != NULL && check == 1) {
		Q->next = P->next;
		free(P);
	}
	if (check == 0) printf("0\n");
	rank_Update(array);
}

void rank_Update(HashTable* array) {
	Node* P = array->list;
	int i = 1;
	while (P != NULL) {
		P->rank = i++;
		P = P->next;
	}
}

void free_List(HashTable* array) {
	HashTable* H = array;
	Node* Q = NULL, * P = NULL;
	for (int i = 0; i < M; i++) {
		if ((H + i)->list != NULL) {
			P = (H + i)->list;
			Q = P;
			while (Q != NULL ) {
				Q = P->next;
				free(P);
				P = Q;
			}
		}
	}
}