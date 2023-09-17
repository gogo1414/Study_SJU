#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#pragma warning(disable:4996)

int main() {
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	srand(time(NULL));
	printf("%d\n", ((((long) rand() << 15) | rand()) % 1000000)+1);
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("time : %12.f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	return 0;
}
/*
((((long) rand() << 15) | rand()) % 1000000) + 1
- 1 ~ 1,000,000 . ������ ������ �����Ѵ�
- RAND_MAX = 32,767�� ��� �� ������ ū ������ ������ �߻���Ű�� ���� ���:
32,767�� 16 0X7FFF, 2 0111 1111 1111 1111 ���� ǥ���� ���� ǥ���� �̹Ƿ� rand()
ȣ���� 15 . 15 ��Ʈ�� ǥ���� �� �ִ� ������ ��ȯ�Ѵ� �� ���� �������� ��Ʈ��ŭ
shift���� �� �ι�° rand() ȣ��κ��� ���� ������ OR 30 ������ ���ָ� ��Ʈ��
ǥ���� �� �ִ� ������ ���� �� �ִ� ��. 0 ~ 1,073,741,823 ������ ������ �̸� ��
���� 1,000,000 1 1 ~ 1,000,000 ���� ������ ������ �� �� �� �����ָ� ������ ������
��� �ȴ�.
*/

/*
���̺귯�� �Լ� ��� �Ϲ����� �ð����� �Լ��� clock()�� ����ϸ� �ð��� �����ϰ�
������ �ʴ� ������ �߻��Ѵ� ��. ������ QueryPerformanceCounter() �Լ��� ����ϸ�
������ �ð��� ����� �� �ִ� ��. . ü���� ��� ����� ������ ����
- ������Ϸ� windows.h�� �߰��� ��,
- LARGE_INTEGER , ���� �����ϰ�
- QueryPerformanceFrequency() , �Լ��� ���� Ÿ�̸��� ���ļ��� ������ ������ ��
- �ð��� �����ϰ� ���� �۾��� ���Ŀ� QueryPerformanceCounter()�� ȣ���ϰ� ��
��ȯ������ �̿��Ͽ� ��� ����ϸ� �ȴ�.*/