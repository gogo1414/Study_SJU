#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int N, X[100] = { 0, }, rev_num, rev_X[200] = { 0, }, tmp = 0, ms;
	// 크기가 100개 한정이기 때문에 뒤집을 수 있는 횟수도 100*2, 200번이 된다.
	

	scanf("%d", &N); // 정수 N 입력
	for (int i = 0; i < N; i++) // N개의 수열 X 입력
		scanf("%d", &X[i]); 

	scanf("%d", &rev_num); // 뒤집기할 개수 입력.
	for (int i = 0; i < rev_num * 2; i++) // 뒤집기 정보 입력
		scanf("%d", &rev_X[i]);
	
	for (int i = 0; i < rev_num * 2; i += 2) { // 뒤집기 수만큼 반복
		ms = 0; // 수열의 시작과 끝을 점점 좁힐 때 이용
		while (ms < (rev_X[i+1]-rev_X[i] + 1)/2) { // 뒤집기 정보 속 앞 뒤 수를 뺀 후 1을 더하여 2를 나눈 값을 하면 반복할 수 가 나옴
			tmp = X[rev_X[i] + ms];
			X[rev_X[i] + ms] = X[rev_X[i + 1] - ms];
			X[rev_X[i + 1] - ms] = tmp; // 교환해주기
			ms += 1; // 시작과 끝 좁혀주기
		}
	}
	
	for (int i = 0; i < N; i++) // 결과 출력
		printf(" %d", X[i]);
	
	return 0;
}