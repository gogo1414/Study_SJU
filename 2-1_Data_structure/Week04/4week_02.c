#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int N, ch_length, X[100] = {0,}, ch_X[100] = {0,}, tmp1;
	
	scanf("%d", &N); // ���� N �Է�
	for (int i = 0; i < N; i++) // N���� ���� �Է�
		scanf("%d", &X[i]); 

	scanf("%d", &ch_length); // �ٲ� ���� ���� �Է�
	for (int i = 0; i < ch_length; i++) // �ٲ� ���� �Է�
		scanf("%d", &ch_X[i]);

	tmp1 = X[ch_X[ch_length-2]]; // for ������ �� ������ ������ �̸� ������.
	
	for (int i = ch_length-2; i > 0; i--) { // �ڿ��� ���� ���ڸ� ��������
		X[ch_X[i]] = X[ch_X[i - 1]];
	}

	X[ch_X[ch_length-1]] = tmp1; // ������ ������ ����ֱ�
	
	for (int i = 0; i < N; i++) // ���
		printf(" %d", X[i]);

	return 0;
}