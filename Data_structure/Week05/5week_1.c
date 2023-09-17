#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)


typedef struct node { // node ���� -> ���߿��Ḯ��Ʈ�� head�� tail ����
	struct node* prev; // �ڸ� ����Ű�� �ּ�
	char data; // ���� ������ (������)
	struct node* next; // ���� ����Ű�� �ּ�
} Node;

typedef struct list { // head�� tail ���� ����
	Node* head; // �Ǿ�
	Node* tail; // �ǵ�
	int n;//��� ��尡 �ִ��� Ȯ���ϱ� ����.
} List;

void init(List* list) { // head�� tail �ʱ�ȭ
	Node* head = (Node*)malloc(sizeof(Node)); // head ���� �Ҵ�
	Node* tail = (Node*)malloc(sizeof(Node)); // tail ���� �Ҵ�

	list->head = head; // list�� head <- �����Ҵ�� head 
	head->prev = NULL; // �� ���� �ڴ� ���� ������ NULL
	head->next = tail; // head�� �� <- tail�� �ּ�
	
	list->tail = tail; // list�� tail <- �����Ҵ�� tail
	tail->next = NULL; // til�� �ڴ� ���� ������ NULL
	tail->prev = head; // tail�� �� <- head�� �ּ�

	list->n = 0; // list->n 0���� �ʱ�ȭ : head�� tail�� ���� ���ǿ��� ���� 
	//              ���� �ʴ´ٰ� ��.
}

void add(List* list, int r, char e) { // �Է¹��� �����Ͱ� �� ��带 r ��°�� �߰����ִ� �Լ�
	if ((r < 1)|| r >(list->n + 1)) { //  �Է¹��� r��°�� ���� 1���� �۰ų�
		printf("invalid position\n"); // �������� ���� +1�� ���� r��°���� ���� �� ����
		return; // ���� ���
	}
	Node* p = list->head; // node p�� list head �ּ� ���� ��, p = list_head�� ����
	for (int i = 0; i < r; i++) { // �Է¹��� r��ŭ �ݺ�
		p = p->next; // r��° ��ŭ node p�� �̵� ��, r��° node p �� �Ǵ� ���̴�.
	}
	Node* new_node = (Node*)malloc(sizeof(Node)); // �߰��� new_node �����Ҵ�
	new_node->data = e; // �Է¹��� ������ new_node�� �����Ϳ� ����

	// �ڷ� ��带 �߰��ϴ� ����̴�.
	new_node->next = p; // new_node�� next�� p �ּ� ���� -> r�� 1�϶� ������� p�� tail�� �ּҸ� �����ִ�.
	new_node->prev = p->prev; // new_node�� prev�� p->prev ����
	
	p->prev = new_node; // p�� prev�� new_node �ּ� ����
	p = new_node->prev; // p�� new_node->prev �ּ� ����
//	new_node->prev->next = new_node; // �� �Ʒ� ���ְ� �̷��� �ص� �ȴ�.
	p->next = new_node; // p->next�� new_node �ּ� ����
	// r�� 1�϶� ���� ���� �����ϸ�
	/* �߰��� ����� �հ� �ڿ� tail�� head�� �ּ� ��
 #pragma warning (disable:4996)��
	   tail�� �� �ּҿ� �߰� ��� ����
	   ���⼭�� �� Ư���ѵ� p����� �ּҸ� head�� �ٲ� ������
	   head�� next �� �߰��� ����� �ּҸ� ����*/

	list->n = list->n + 1; // ��� �߰� �ݿ��Ͽ� ����� �� 1�߰�
	return;

}


void delete(List* list, int r) { // ��� ���� �Լ�, �Է¹޴� ������ r��°�� ����, list
	if ((r < 1) || (r > list->n)) { // r��° ������ 1���� �۰ų� ����� ũ�⺸�� Ŭ �� 
		printf("invalid position\n"); // Ÿ������ ���� ��ġ�� ǥ��
		return; // delete�Լ� ���.
	}
	Node* p = list->head; // node p <- list�� head �ּ� ����
	for (int i = 0; i < r; i++) // r��° �ݺ�
		p = p->next; // p�ּ� r��°�� �̵�
	p->prev->next = p->next; // p->prev->next <- p->next p->prev �ּ��� next�� p->next ����� �ּҸ� �����ϴ°���
	p->next->prev = p->prev; // p->next->prev <- p->prev ���� ����� �������� �����ϸ� �ȴ�.
	free(p); // ��带 �����ϱ� ���ؼ� �Ҵ��� �޸� ����
	list->n = list->n - 1; // ���ŵ� ��� ����� ������ �ݿ�
}

char get(List* list, int r) { // r��° ����� ������ �� ���� �Լ�
	if ((r < 1) || (r > list->n)){ // ���� r�� 1���� �۰ų� ����� ���� list->n���� Ŭ��
		printf("invalid position\n"); // Ÿ������ ���� ��ġ ���
		return '?'; // �����Լ����� ��� �������� '?'�� ����. �׷��� '?'���� ��ȯ
	}
	Node* p = list->head; // node p <- list->head �ּ� ����
	for (int i = 0; i < r; i++) { // r�� �ݺ�
		p = p->next; //p�� �ּ� r������ �̵�
	}

	return p->data; // r�� �ּ��� ������ ��ȯ
}

void print(List* list) { // ��� ��� ��ȸ�Ͽ� ������ ����ϴ� �Լ�
	Node* p = list->head; // ��� p�� list->head �ּ� ����
	for (int i = 0; i < list->n; i++) { // node�� ������ŭ �ݺ�
		p = p->next; // p�� �ּ� �̵� 
		printf("%c", p->data); // p->data ���
	}
	printf("\n"); // �� �̵�
	return; // ��ȯ
}

int main() { // �����Լ�
	int n,  x; 
	char c, da, get1;
	// �Է¹��� ���� 2�� ���� 3�� ����

	List* list = (List*)malloc(sizeof(List)); // head�� tail�� �� list �Ҵ�
	init(list); // list �ʱ�ȭ 

	scanf("%d", &n); // ������ ���� �Է¹ޱ�

	// ��� ���� �Լ��� ����� �͵� ���ٴ� �Ʒ��� �� �������.
	// ���ʰ� �����ؼ� �׷��� �ʹ� ũ�� ����..
	
	/* �������� �˷��ֽ� ���� : scanf�� ""���̿� �� ���� ���� �Է��ؾ�
	 ����Ǳ� ������ "%c"�� �ƴ� "%c "�� �ϸ� ������� ��� �Է��� �޴´�. */
	
	for (int i = 0; i < n; i++) { // n�� �ݺ�
		getchar(); // ���� �Է¹ޱ����� enter �Է��� c�� ����� ����
		scanf("%c", &c); // ������ ���� ���ڷ� �Է�
		if(c == 'A'){ // add�Լ� ����
			scanf("%d %c", &x, &da);
			add(list, x, da);
		}
		if (c == 'D') { // delete �Լ� ����
			scanf("%d", &x); // �̰� �Է� �޴°� �ȽἭ �Է��� �����µ� ���� ã�Ҵ�.
			delete(list, x);
		}
		if (c == 'G') { // get �Լ� ����
			scanf("%d", &x);
			get1 = get(list, x); // ���� ���� ����
			if (get1 != '?') // ó������ printf("%c\n", get(list,x)�� ������ �̻��� ��ġ
				// ���� ����� ����Ǳ� ������ ���ǽ��� ����.
				printf("%c\n", get1);
		}
		if (c == 'P') { // print �Լ� ����
			print(list);
		}
	}
	return 0;
}