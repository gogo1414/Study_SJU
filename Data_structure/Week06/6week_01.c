#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node { // node ����
	int coef; // ���
	int exp; // ����
	struct node* next; // head�� ���� �ּ�
}Node;

void init(Node* Head) { // ���Ͽ��Ḯ��Ʈ�� head�ۿ� ����
	Node* head = (Node*)malloc(sizeof(Node));
	
	Head = head;
	head->next = NULL; // �ּҸ� NULL���� �־������
}

/* �ʱ�ȭ �Լ��� ���� ����°� ���ٰ� �����߾��µ� �� �𸣰ڴ�.
   ���Ͽ��Ḯ��Ʈ�ϱ� �ȸ��� ���� ������.. */

void appendTerm(Node* head, int c, int e) { // �Է¹��� ����� ������ ��忡 �־��ִ� �Լ���.
	if (c == 0) return;
	Node* p = head;
	while (p->next != NULL)
		p = p->next; // ������ �� ������ �ƴ϶� �ٸ��ɷ� �����־��µ� �׷��� �ϴϱ� �� �ȵǼ� �̷��� �ٲ��.
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->coef = c;
	new_node->exp = e;
	new_node->next = NULL;
	p->next = new_node;
	return;
}

Node* addPoly(Node* fx1, Node* fx2) { // �ڷῡ �����ִ� ������ �״�� ����
	int sum = 0;
	Node* result = (Node*)malloc(sizeof(Node));
	result->next = NULL;
	Node* g1 = fx1->next;
	Node* g2 = fx2->next;
	Node* k = result;
	
	while ((g1 != NULL) && (g2 != NULL)) { // ��ġ�ϴ� ���������� ����� ���ϱ� ó������ ������ �ݺ��Ѵ�.
		if (g1->exp > g2->exp) { // ����� ������ �� ���Ƽ� �������� �Ѿ��.
			appendTerm(k, g1->coef, g1->exp); // ���� ����� ���� �־��ش�.
			g1 = g1->next; // �������� ��ĭ ������
		}
		else if (g2->exp > g1->exp) { // ���� ����
			appendTerm(k, g2->coef, g2->exp);
			g2 = g2->next;
		}
		else { // ���� ������ �������� �ش� ����� ���ؼ� ���ο� ��忡 �ݿ�
			sum = g1->coef + g2->coef;
			if (sum != 0)
				appendTerm(k, sum, g1->exp); // ������ ��������� �ص� �������.
			g1 = g1->next;
			g2 = g2->next;
		}
	}

	while (g1 != NULL) { // �ǳ��� �����ִ� ����� �����ֱ� �� �� �ϴ°ɷ� ����.
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
	// node�� �׳� ���ε��� �ʱ�ȭ �ߴ� �� ������ ���� ���� �� ������ ����.
	fx1->next = NULL, fx2->next = NULL; //result�� ���� ������ �Լ� �߿� �־��ִ°� �ֱ� �����̴�.
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
	result = result->next; // �Ʒ����� ����� ���ֱ� ���� �̸� ������.
	while (result != NULL) {
		printf(" %d %d", result->coef, result->exp);
		result = result->next;
	}
}
