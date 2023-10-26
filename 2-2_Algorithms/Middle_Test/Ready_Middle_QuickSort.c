#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

/* Quick Sort(중복 가능) version
*/

void QuickSort(int*, int, int);
void input_array(int*);
void print_array(int*);
void inPlacePartition(int*, int, int, int);
void swap_Element(int*, int,int);
int findPivot(int, int);

int size, pivot[2];

int main() {
	scanf("%d", &size);
	int *int_array = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		scanf("%d", &int_array[i]);
	QuickSort(int_array, 0, size-1);
	print_array(int_array);
	return 0;
}


void input_array(int* array) {
	for (int i = 0; i < size; i++)
		scanf("%d", &array[i]);
}
void print_array(int* array) {
	for (int i = 0; i < size; i++) {
		printf(" %d", array[i]);
	}
	printf("\n");
}
void QuickSort(int* array, int a, int b) {
	if (a > b) return;
	int k = findPivot(a, b);
	inPlacePartition(array, a, b, k);
	QuickSort(array, a, pivot[0]-1);
	QuickSort(array, pivot[1]+1, b);
}
void swap_Element(int* array, int a, int b) {
	int tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}// a, b는 index이다.

void inPlacePartition(int* array, int a, int b, int k) {
	int i = a, j = b-1, p = array[k];
	swap_Element(array, k, b);
	while (i <= j) {
		while ((i <= j) && (array[i] < p)) {
			i += 1;
		}
		while ( (j >= i) && (array[j] >= p)) {
			j -= 1;
		}
		if (i < j)
			swap_Element(array, i, j);
	}
	pivot[0] = i;
	j = b - 1;
	while (i <= j) {
		while ((i<=j) && (array[i] <= p)) {
			i += 1;
		}
		while ((j >= i) && (array[j] > p)) {
			j -= 1;
		}
		if (i < j)
			swap_Element(array, i, j);
	}
	pivot[1] = i;
	swap_Element(array, pivot[1], b);
}

int findPivot(int a, int b) {
	srand(time(NULL));
	return rand() % (b - a + 1) + a; // ex 3 ~ 5 범위 rand() % 3 + 3
}