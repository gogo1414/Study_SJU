#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* �����ּҹ� �ؽ����̺� - �����ؽ� (Open Addresing HashTable - Double Hashing)
*  ũ�� M, ���� ���� n
*  �Է� Ű : 2�ڸ� �̻��� �ڿ���
*  h(key) = key % M, �� ��° �ؽ��Լ� h'(key) = q - (key % q), q�� M���� ���� �Ҽ�
*  �� ���� 0
*  Ư�̻��� : ������ ������ ������ �迭�� ����ϵ��� ���������� ����ü�� ���� ����
*  ������ �ذ��߽��ϴ�.
*/

typedef struct hashtable {
	int key;
	int active;
}HashTable;

void HashTable_init(HashTable*);
void HashTable_Insert(HashTable*, int);
void HashTable_Search(HashTable*, int);
void HashTable_Print(HashTable*);

int M, q;

int main() {
	int n, c, key;
	scanf("%d %d %d", &M, &n, &q);

	HashTable* array = (HashTable*)malloc(sizeof(HashTable*) * M);
	HashTable_init(array);
	while ((c = getchar()) != EOF && c != 'e') {
		if (c == 'i') {
			scanf("%d", &key);
			HashTable_Insert(array, key);
		}
		else if (c == 's') {
			scanf("%d", &key);
			HashTable_Search(array, key);
		}
		else if (c == 'p') {
			HashTable_Print(array);
		}
	}

	HashTable_Print(array);

	free(array);

	return 0;
}

void HashTable_init(HashTable* array) {
	for (int i = 0; i < M; i++) {
		(array + i)->active = 0;
		(array + i)->key = 0;
	}
}
void HashTable_Insert(HashTable* array, int key) {
	int h = key % M, h2 = q - (key %q);
	for (int i = 0; i < M; i++) {
		if ((array + h)->active == 0) {
			(array + h)->active = 1;
			(array + h)->key = key;
			printf("%d\n", h);
			return;
		}
		else {
			printf("C");
			h = (h + h2) % M;
		}
	}
	printf("array is Full\n");
}
void HashTable_Search(HashTable* array, int key) {
	int h = key % M, h2 = q - (key % q);
	for (int i = 0; i < M; i++) {
		if ((array + h)->key == key) {
			printf("%d %d\n", h, (array+h)->key);
			return;
		}
		else if((array+h)->active == 1) {
			h = (h + h2) % M;
		}
		else {
			printf("-1\n");
			return;
		}
	}
	printf("-1\n");
}
void HashTable_Print(HashTable* array) {
	for (int i = 0; i < M; i++) {
		printf(" %d", (array + i)->key);
	}
	printf("\n");
}