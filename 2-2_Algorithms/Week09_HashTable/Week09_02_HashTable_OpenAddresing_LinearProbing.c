#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* 개방주소법 해시테이블 - 선형조사법 (open-Adrresing HashTable linear probing)
* active : 1, empty : 0
* h(key) = key % M
* 입력 키는 중복 없는 6자리 혹은 8자리의 자연수
* 특이사항 : 문제의 조건이 정수형 배열을 사용하도록 유도했지만 구조체를 새로 만들어서
* 문제를 해결했습니다.
*/

typedef struct hashtable {
	int key;
	int active;
}HashTable;

void HashTable_init(HashTable*);
void HashTable_Insert(HashTable*, int);
void HashTable_Search(HashTable*, int);

int M;

int main() {
	int n, c, key, h;
	scanf("%d %d", &M, &n);

	HashTable* Array = (HashTable*)malloc(sizeof(HashTable) * M);
	HashTable_init(Array);

	while ((c = getchar()) != EOF && c != 'e') {
		if (c == 'i') {
			scanf("%d", &key);
			HashTable_Insert(Array, key);
		}
		else if (c == 's') {
			scanf("%d", &key);
			HashTable_Search(Array, key);
		}
	}

	free(Array);
	
	return 0;
}

void HashTable_init(HashTable* array) {
	HashTable* H = array;
	for (int i = 0; i < M; i++) {
		(H + i)->active = 0; // 비어있는 셀 : 0
	}
}
void HashTable_Insert(HashTable* array, int key) {
	HashTable* H = array;
	int h = key % M;
	int first = h;
	while ((H + h)->active != 0) {
		printf("C");
		h += 1;
		if (h == M)
			h = 0;
		if (h == first) {
			return;
		}
	}
	(H + h)->key = key;
	(H + h)->active = 1;
	printf("%d\n", h);
}
void HashTable_Search(HashTable* array, int key) {
	HashTable* H = array;
	int h = key % M;
	int first = h;
	while ((H+h)->active == 1) {
		if ((H + h)->key == key) {
			printf("%d %d\n", h, key);
			return;
		}
		h += 1;
		if (h == M) h = 0;
		if (h == first) {
			printf("-1\n");
			return;
		}
	}
	printf("-1\n");
}