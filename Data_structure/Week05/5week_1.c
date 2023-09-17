#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)


typedef struct node { // node 구조 -> 이중연결리스트라 head와 tail 존재
	struct node* prev; // 뒤를 가리키는 주소
	char data; // 저장 데이터 (문자형)
	struct node* next; // 앞을 가리키는 주소
} Node;

typedef struct list { // head와 tail 먼저 생성
	Node* head; // 맨앞
	Node* tail; // 맨뒤
	int n;//몇개의 노드가 있는지 확인하기 위함.
} List;

void init(List* list) { // head와 tail 초기화
	Node* head = (Node*)malloc(sizeof(Node)); // head 동적 할당
	Node* tail = (Node*)malloc(sizeof(Node)); // tail 동적 할당

	list->head = head; // list의 head <- 동적할당된 head 
	head->prev = NULL; // 맨 앞의 뒤는 없기 때문에 NULL
	head->next = tail; // head의 앞 <- tail의 주소
	
	list->tail = tail; // list의 tail <- 동적할당된 tail
	tail->next = NULL; // til의 뒤는 없기 땜누에 NULL
	tail->prev = head; // tail의 뒤 <- head의 주소

	list->n = 0; // list->n 0으로 초기화 : head와 tail은 문제 조건에서 노드로 
	//              세지 않는다고 함.
}

void add(List* list, int r, char e) { // 입력받은 데이터가 들어간 노드를 r 번째에 추가해주는 함수
	if ((r < 1)|| r >(list->n + 1)) { //  입력받은 r번째의 수가 1보다 작거나
		printf("invalid position\n"); // 현재노드의 수에 +1한 값이 r번째보다 작을 때 실행
		return; // 실행 취소
	}
	Node* p = list->head; // node p에 list head 주소 대입 즉, p = list_head다 현재
	for (int i = 0; i < r; i++) { // 입력받은 r만큼 반복
		p = p->next; // r번째 만큼 node p를 이동 즉, r번째 node p 가 되는 것이다.
	}
	Node* new_node = (Node*)malloc(sizeof(Node)); // 추가할 new_node 동적할당
	new_node->data = e; // 입력받은 데이터 new_node의 데이터에 저장

	// 뒤로 노드를 추가하는 방법이다.
	new_node->next = p; // new_node의 next에 p 주소 저장 -> r이 1일때 예를들면 p는 tail의 주소를 갖고있다.
	new_node->prev = p->prev; // new_node의 prev에 p->prev 저장
	
	p->prev = new_node; // p의 prev에 new_node 주소 저장
	p = new_node->prev; // p에 new_node->prev 주소 저장
//	new_node->prev->next = new_node; // 위 아래 없애고 이렇게 해도 된다.
	p->next = new_node; // p->next에 new_node 주소 저장
	// r이 1일때 위의 식을 정리하면
	/* 추가할 노드의 앞과 뒤에 tail과 head의 주소 대
 #pragma warning (disable:4996)입
	   tail의 전 주소에 추가 노드 대입
	   여기서가 좀 특이한데 p노드의 주소를 head로 바꾼 다음에
	   head의 next 에 추가할 노드의 주소를 대입*/

	list->n = list->n + 1; // 노드 추가 반영하여 노드의 수 1추가
	return;

}


void delete(List* list, int r) { // 노드 제거 함수, 입력받는 데이터 r번째의 정수, list
	if ((r < 1) || (r > list->n)) { // r번째 정수가 1보다 작거나 노드의 크기보다 클 때 
		printf("invalid position\n"); // 타당하지 않은 위치다 표시
		return; // delete함수 취소.
	}
	Node* p = list->head; // node p <- list의 head 주소 대입
	for (int i = 0; i < r; i++) // r번째 반복
		p = p->next; // p주소 r번째로 이동
	p->prev->next = p->next; // p->prev->next <- p->next p->prev 주소의 next에 p->next 저장된 주소를 저장하는거임
	p->next->prev = p->prev; // p->next->prev <- p->prev 위와 비슷한 생각으로 이해하면 된다.
	free(p); // 노드를 제거하기 위해서 할당한 메모리 해제
	list->n = list->n - 1; // 제거된 노드 노드의 개수에 반영
}

char get(List* list, int r) { // r번째 노드의 데이터 값 추출 함수
	if ((r < 1) || (r > list->n)){ // 정수 r이 1보다 작거나 노드의 개수 list->n보다 클때
		printf("invalid position\n"); // 타당하지 않은 위치 출력
		return '?'; // 메인함수에서 취소 조건으로 '?'로 만듦. 그래서 '?'문자 반환
	}
	Node* p = list->head; // node p <- list->head 주소 대입
	for (int i = 0; i < r; i++) { // r번 반복
		p = p->next; //p의 주소 r번으로 이동
	}

	return p->data; // r번 주소의 데이터 반환
}

void print(List* list) { // 모든 노드 순회하여 데이터 출력하는 함수
	Node* p = list->head; // 노드 p에 list->head 주소 저장
	for (int i = 0; i < list->n; i++) { // node의 개수만큼 반복
		p = p->next; // p의 주소 이동 
		printf("%c", p->data); // p->data 출력
	}
	printf("\n"); // 줄 이동
	return; // 반환
}

int main() { // 메인함수
	int n,  x; 
	char c, da, get1;
	// 입력받을 정수 2개 문자 3개 선언

	List* list = (List*)malloc(sizeof(List)); // head와 tail이 들어간 list 할당
	init(list); // list 초기화 

	scanf("%d", &n); // 연산의 개수 입력받기

	// 사실 위에 함수를 만드는 것들 보다는 아래가 더 힘들었다.
	// 기초가 부족해서 그런걸 너무 크게 느낌..
	
	/* 조교님이 알려주신 정보 : scanf는 ""사이에 들어간 띄어쓰기 까지 입력해야
	 실행되기 때문에 "%c"가 아닌 "%c "로 하면 띄어쓰기까지 써야 입력을 받는다. */
	
	for (int i = 0; i < n; i++) { // n번 반복
		getchar(); // 문자 입력받기전에 enter 입력이 c에 들어갈까봐 넣음
		scanf("%c", &c); // 연산의 종류 문자로 입력
		if(c == 'A'){ // add함수 실행
			scanf("%d %c", &x, &da);
			add(list, x, da);
		}
		if (c == 'D') { // delete 함수 실행
			scanf("%d", &x); // 이거 입력 받는걸 안써서 입력이 씹혔는데 드디어 찾았다.
			delete(list, x);
		}
		if (c == 'G') { // get 함수 실행
			scanf("%d", &x);
			get1 = get(list, x); // 값을 따로 저장
			if (get1 != '?') // 처음에는 printf("%c\n", get(list,x)로 했으나 이상한 위치
				// 여도 출력은 진행되기 때문에 조건식을 만듦.
				printf("%c\n", get1);
		}
		if (c == 'P') { // print 함수 실행
			print(list);
		}
	}
	return 0;
}