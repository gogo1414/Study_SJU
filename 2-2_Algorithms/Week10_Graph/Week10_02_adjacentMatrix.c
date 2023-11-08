#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* ������ ���߱׷��� (������� ����)
* graphNode* adj_List�� ���� �߰� ���� : adj_Matrix�� �� �ε����� �ش� verticies�� ������ �ǹ��ϸ�,
*										 adj_Matrix�� �ش� verticies�� ������ ����Ų��.
* graphType : �׷����� ���´� ������ķ� �����Ǿ� �ִ�.
*/
typedef struct graphnode {
	int vertic, weight; // ������ ����ġ
	struct graphnode* link; // ����
}graphNode;

typedef struct graphType {
	int n; // ���� ��
	graphNode* adj_Matrix[6][6]; // ���� ���
} graphType;

// graphType �ʱ�ȭ
void init_GraphType(graphType*);

// graphType, vertic, adj_vertic, weight ���̴�.
void insert_Vertic_Edge(graphType*, int, int, int);

// graph�� vertic, weight, adj_List�� �����Ѵ�.
void make_Graph(graphType*);

// weight�� 0�̶�� a�� b ������ ������ ���� 
// weight�� 0�� �ƴ϶��, ������ ���� �� weight ����, �������� ���� �� ���� ����.
void modify_Edge(graphType*, int, int, int);

// node Number�� ��������Ʈ�� ������������ ����Ѵ�.
void print_AdjList(graphType*, int);
// graphNode �޸� ����
void free_Graph(graphType*);

int main() {
	int c, x, a, b, weight;
	graphType* graph = (graphType*)malloc(sizeof(graphType));
	init_GraphType(graph);
	make_Graph(graph);
	while ((c = getchar()) != EOF && c != 'q') {
		if (c == 'a') {
			scanf("%d", &x);
			print_AdjList(graph, x);
		}
		else if (c == 'm') {
			scanf("%d %d %d", &a, &b, &weight);
			modify_Edge(graph, a, b, weight);
		}
	}
	free_Graph(graph);
	free(graph);
	return 0;
}


void init_GraphType(graphType* G) {
	G->n = 6;
	for (int i = 0; i < G->n; i++)
		for (int j = 0; j < G->n; j++)
			G->adj_Matrix[i][j] = NULL;
}
void insert_Vertic_Edge(graphType* G, int a, int b, int weight) {
	graphNode* newnode = (graphNode*)malloc(sizeof(graphNode));
	newnode->vertic = a;
	newnode->weight = weight;
	newnode->link = G->adj_Matrix[a-1][b-1];
	G->adj_Matrix[a - 1][b - 1] = newnode;

}
void make_Graph(graphType* G) {
	insert_Vertic_Edge(G, 1, 2, 1);
	insert_Vertic_Edge(G, 1, 3, 1);
	insert_Vertic_Edge(G, 1, 4, 1);
	insert_Vertic_Edge(G, 1, 6, 2);
	insert_Vertic_Edge(G, 2, 1, 1);
	insert_Vertic_Edge(G, 2, 3, 1);
	insert_Vertic_Edge(G, 3, 1, 1);
	insert_Vertic_Edge(G, 3, 2, 1);
	insert_Vertic_Edge(G, 3, 5, 4);
	insert_Vertic_Edge(G, 4, 1, 1);
	insert_Vertic_Edge(G, 5, 3, 4);
	insert_Vertic_Edge(G, 5, 6, 3);
	insert_Vertic_Edge(G, 5, 5, 4);
	insert_Vertic_Edge(G, 6, 1, 2);
	insert_Vertic_Edge(G, 6, 5, 3);
}
void modify_Edge(graphType* G, int a, int b, int weight) {
	if (a < 1 || a >G->n || b < 1 || b > G->n) {
		printf("-1\n");
		return;
	}
	else {
		graphNode* P = G->adj_Matrix[a - 1][b - 1];
		if (weight == 0) {
			if (P != NULL) {
				graphNode* Q = G->adj_Matrix[b - 1][a - 1];
				G->adj_Matrix[a - 1][b - 1] = NULL;
				free(P);
				if (a == b) return;
				G->adj_Matrix[b - 1][a - 1] = NULL;
				free(Q);
			}
			else {
				printf("-1\n");
				return;
			}
		}
		else {
			if (P != NULL) {
				graphNode* Q = G->adj_Matrix[b - 1][a - 1];
				P->weight = weight;
				Q->weight = weight;
				return;
			}
			else {
				insert_Vertic_Edge(G, a, b, weight);
				insert_Vertic_Edge(G, b, a, weight);
				return;
			}
		}
	}
}
void print_AdjList(graphType* G, int node_Number) {
	if (node_Number > G->n || node_Number < 1) {
		printf("-1\n"); 
		return;
	}
	for (int i = 0; i < G->n; i++) {
		if (G->adj_Matrix[node_Number-1][i] != NULL) {
			printf(" %d %d", i+1, G->adj_Matrix[node_Number - 1][i]->weight);
		}
	}
	printf("\n");
}
void free_Graph(graphType* G) {
	for (int i = 0; i < G->n; i++) {
		for (int j = 0; j < G->n; j++) {
			graphNode* P = G->adj_Matrix[i][j];
			if (P != NULL) {
				free(P);
				G->adj_Matrix[i][j] = NULL;
			}
		}
	}
}