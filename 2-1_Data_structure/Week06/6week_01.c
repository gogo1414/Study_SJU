#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node { // node 생성
	int coef; // 계수
	int exp; // 차수
	struct node* next; // head의 다음 주소
}Node;

void init(Node* Head) { // 단일연결리스트라 head밖에 없음
	Node* head = (Node*)malloc(sizeof(Node));
	
	Head = head;
	head->next = NULL; // 주소를 NULL값을 넣어줘야함
}

/* 초기화 함수를 따로 만드는게 좋다고 생각했었는데 잘 모르겠다.
   단일연결리스트니까 안만들어도 되지 않을까.. */

void appendTerm(Node* head, int c, int e) { // 입력받은 계수와 차수를 노드에 넣어주는 함수다.
	if (c == 0) return;
	Node* p = head;
	while (p->next != NULL)
		p = p->next; // 원래는 이 과정이 아니라 다른걸로 적혀있었는데 그렇게 하니깐 잘 안되서 이렇게 바꿨다.
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->coef = c;
	new_node->exp = e;
	new_node->next = NULL;
	p->next = new_node;
	return;
}

Node* addPoly(Node* fx1, Node* fx2) { // 자료에 나와있는 설명을 그대로 구현
	int sum = 0;
	Node* result = (Node*)malloc(sizeof(Node));
	result->next = NULL;
	Node* g1 = fx1->next;
	Node* g2 = fx2->next;
	Node* k = result;
	
	while ((g1 != NULL) && (g2 != NULL)) { // 일치하는 차수끼리의 계수를 더하기 처음부터 끝까지 반복한다.
		if (g1->exp > g2->exp) { // 계수가 한쪽이 더 높아서 다음으로 넘어간다.
			appendTerm(k, g1->coef, g1->exp); // 높은 계수의 식을 넣어준다.
			g1 = g1->next; // 높은쪽을 한칸 앞으로
		}
		else if (g2->exp > g1->exp) { // 위와 동일
			appendTerm(k, g2->coef, g2->exp);
			g2 = g2->next;
		}
		else { // 같은 차수를 만났을때 해당 계수를 더해서 새로운 노드에 반영
			sum = g1->coef + g2->coef;
			if (sum != 0)
				appendTerm(k, sum, g1->exp); // 차수는 어느쪽으로 해도 상관없다.
			g1 = g1->next;
			g2 = g2->next;
		}
	}

	while (g1 != NULL) { // 맨끝에 남아있던 계수를 더해주기 위 해 하는걸로 보임.
		appendTerm(k, g1->coef, g1->exp);
		g1 = g1->next;
	}
	while (g2 != NULL) {
		appendTerm(k, g2->coef, g2->exp);
		g2 = g2->next;
	}
	return result;

}

int main() {
	int n1, n2, x, y;
	Node* fx1 = (Node*)malloc(sizeof(Node));
	Node* fx2 = (Node*)malloc(sizeof(Node));
	Node* result = (Node*)malloc(sizeof(Node)); 
	// node를 그냥 따로따로 초기화 했다 이 과정도 따로 만들 수 있을거 같다.
	fx1->next = NULL, fx2->next = NULL; //result를 안한 이유는 함수 중에 넣어주는게 있기 때문이다.
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++) {
		scanf("%d %d", &x, &y);
		appendTerm(fx1, x, y);
	}
	printf("\n");
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++) {
		scanf("%d %d", &x, &y);
		appendTerm(fx2, x, y);
	}
	result = addPoly(fx1, fx2);
	result = result->next; // 아래에서 출력을 해주기 위해 미리 더해줌.
	while (result != NULL) {
		printf(" %d %d", result->coef, result->exp);
		result = result->next;
	}
}
