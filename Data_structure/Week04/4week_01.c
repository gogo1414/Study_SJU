#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int N, X[100] = { 0, }, rev_num, rev_X[200] = { 0, }, tmp = 0, ms;
	// ũ�Ⱑ 100�� �����̱� ������ ������ �� �ִ� Ƚ���� 100*2, 200���� �ȴ�.
	

	scanf("%d", &N); // ���� N �Է�
	for (int i = 0; i < N; i++) // N���� ���� X �Է�
		scanf("%d", &X[i]); 

	scanf("%d", &rev_num); // �������� ���� �Է�.
	for (int i = 0; i < rev_num * 2; i++) // ������ ���� �Է�
		scanf("%d", &rev_X[i]);
	
	for (int i = 0; i < rev_num * 2; i += 2) { // ������ ����ŭ �ݺ�
		ms = 0; // ������ ���۰� ���� ���� ���� �� �̿�
		while (ms < (rev_X[i+1]-rev_X[i] + 1)/2) { // ������ ���� �� �� �� ���� �� �� 1�� ���Ͽ� 2�� ���� ���� �ϸ� �ݺ��� �� �� ����
			tmp = X[rev_X[i] + ms];
			X[rev_X[i] + ms] = X[rev_X[i + 1] - ms];
			X[rev_X[i + 1] - ms] = tmp; // ��ȯ���ֱ�
			ms += 1; // ���۰� �� �����ֱ�
		}
	}
	
	for (int i = 0; i < N; i++) // ��� ���
		printf(" %d", X[i]);
	
	return 0;
}