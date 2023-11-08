#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* 개방주소법 해시테이블 - 이중해싱 (Open Addresing HashTable - Double Hashing)
*  크기 M, 삽입 개수 n
*  입력 키 : 2자리 이상의 자연수
*  h(key) = key % M, 두 번째 해시함수 h'(key) = q - (key % q), q는 M보다 작은 소수
*  빈 버켓 0
*  특이사항 : 문제의 조건이 정수형 배열을 사용하도록 유도했지만 구조체를 새로 만들어서
*  문제를 해결했습니다.
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