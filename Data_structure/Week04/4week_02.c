#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int N, ch_length, X[100] = {0,}, ch_X[100] = {0,}, tmp1;
	
	scanf("%d", &N); // 정수 N 입력
	for (int i = 0; i < N; i++) // N개의 수열 입력
		scanf("%d", &X[i]); 

	scanf("%d", &ch_length); // 바꿈 정보 개수 입력
	for (int i = 0; i < ch_length; i++) // 바꿈 정보 입력
		scanf("%d", &ch_X[i]);

	tmp1 = X[ch_X[ch_length-2]]; // for 문에서 못 가져온 데이터 미리 빼놓기.
	
	for (int i = ch_length-2; i > 0; i--) { // 뒤에서 앞의 숫자를 가져오기
		X[ch_X[i]] = X[ch_X[i - 1]];
	}

	X[ch_X[ch_length-1]] = tmp1; // 빼놓은 데이터 집어넣기
	
	for (int i = 0; i < N; i++) // 출력
		printf(" %d", X[i]);

	return 0;
}