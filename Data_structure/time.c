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
- 1 ~ 1,000,000 . 범위의 난수를 생성한다
- RAND_MAX = 32,767인 경우 이 수보다 큰 범위의 난수를 발생시키기 위한 방법:
32,767의 16 0X7FFF, 2 0111 1111 1111 1111 진수 표현은 진수 표현은 이므로 rand()
호출은 15 . 15 비트로 표현할 수 있는 난수를 반환한다 이 값을 왼쪽으로 비트만큼
shift해준 뒤 두번째 rand() 호출로부터 얻은 난수와 OR 30 연산을 해주면 비트로
표현할 수 있는 난수를 얻을 수 있다 이. 0 ~ 1,073,741,823 난수의 범위는 이며 이
값을 1,000,000 1 1 ~ 1,000,000 으로 나머지 연산을 한 뒤 을 더해주면 범위의 난수를
얻게 된다.
*/

/*
라이브러리 함수 가운데 일반적인 시간측정 함수인 clock()을 사용하면 시간이 정밀하게
나오지 않는 문제가 발생한다 대. 안으로 QueryPerformanceCounter() 함수를 사용하면
정밀한 시간을 출력할 수 있다 구. . 체적인 사용 방법은 다음과 같다
- 헤더파일로 windows.h를 추가한 후,
- LARGE_INTEGER , 변수 선언하고
- QueryPerformanceFrequency() , 함수를 통해 타이머의 주파수를 변수에 저장한 후
- 시간을 측정하고 싶은 작업의 전후에 QueryPerformanceCounter()를 호출하고 그
반환값들을 이용하여 계산 출력하면 된다.*/