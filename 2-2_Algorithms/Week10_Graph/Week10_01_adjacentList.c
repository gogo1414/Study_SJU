#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* 무방향 가중그래프 (인접리스트 구현)
* graphNode* adj_List에 관한 추가 설명 : adj_List의 인덱스는 해당 vertic을 의미하며,
*										 adj_List는 해당 vertic의 인접리스트의 헤더를 가리킨다.
* graphType : 그래프의 형태는 인접리스트로 구현되어 있다.
*/

typedef struct graphnode {
	int vertic, weight;
	struct graphnode* next;
}graphNode;

typedef struct graphtype {
	graphNode* adj_List[7]; // 인접리스트를 관리할 헤더노드
}graphType;

void init_GraphType(graphType*); // graphType 초기화
void insert_Vertic_Edge(graphType*, int, int, int); // graphType, vertic, adj_vertic, weight 순이다.
void make_Graph(graphType*); // graph의 vertic, weight, adj_List를 구성한다.

// weight이 0이라면 a와 b 사이의 간선을 삭제 
// weight이 0이 아니라면, 간선이 존재 시 weight 수정, 존재하지 않을 시 간선 생성.
void modify_Edge(graphType*, int, int, int);
void print_AdjList(graphType*, int); // node Number의 인접리스트를 오름차순으로 출력한다.
void free_Graph(graphType*); // graphNode 메모리 헤제

int main() {
	int c, a, b, w, x;
	graphType* graph = (graphType*)malloc(sizeof(graphType));
	init_GraphType(graph);
	make_Graph(graph);
	while ((c = getchar()) != EOF && c != 'q') {
		if (c == 'a') {
			scanf("%d", &x);
			print_AdjList(graph, x);
		}
		else if (c == 'm') {
			scanf("%d %d %d", &a, &b, &w);
			modify_Edge(graph, a, b, w);
		}
	}
	free_Graph(graph);
	free(graph);
	return 0;
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
void init_GraphType(graphType* G) {
	for (int i = 0; i <= 6; i++) {
		G->adj_List[i] = NULL;
	}
}
void insert_Vertic_Edge(graphType* G, int a, int b, int weight) {
	graphNode* newnode = (graphNode*)malloc(sizeof(graphNode));
	newnode->vertic = a;
	newnode->weight = weight;
	newnode->next = G->adj_List[b];
	G->adj_List[b] = newnode; 
}
void modify_Edge(graphType* G, int a, int b, int weight) {
	graphNode* P = G->adj_List[b], *Q = G->adj_List[a];
	if ((a < 1 || a > 6) || (b < 1 || b > 6)) {
		printf("-1\n");
		return;
	}
	if (weight == 0) {
		graphNode* P2 = P, * Q2 = Q;
		while (P != NULL) {
			if (P->vertic == a) {
				if (P == G->adj_List[b]) G->adj_List[b] = P->next;
				P2->next = P->next;
				free(P);
				break;
			}
			P2 = P;
			P = P->next;
		}
		if (a == b) return;
		while (Q != NULL) {
			if (Q->vertic == b) {
				if (Q == G->adj_List[a]) G->adj_List[a] = Q->next;
				Q2->next = Q->next;
				free(Q);
				return;
			}
			Q2 = Q;
			Q = Q->next;
		}
	}
	else {
		while (P != NULL) {
			if (P->vertic == a) {
				while (Q != NULL) {
					if (Q->vertic == b) {
						break;
					}
					Q = Q->next;
				}
				P->weight = weight;
				Q->weight = weight;
				return;
			}
			P = P->next;
		}
		insert_Vertic_Edge(G, a, b, weight);
		if (a == b) return;
		insert_Vertic_Edge(G, b, a, weight);
		return;
	}
	printf("-1\n");
}
void print_AdjList(graphType* G, int node_Number) {
	if (node_Number < 1 || node_Number > 6 || G->adj_List[node_Number] == NULL) {
		printf("-1\n");
		return;
	}
	graphNode* P = G->adj_List[node_Number];
	while (P->next != NULL) {
		graphNode* P2 = P->next;
		graphNode* small = P;
		while (P2 != NULL) {
			if (small->vertic > P2->vertic)
				small = P2;
			P2 = P2->next;
		}
		if (P->vertic > small->vertic) {
			int tmp1 = P->vertic;
			int tmp2 = P->weight;
			P->vertic = small->vertic;
			P->weight = small->weight;
			small->vertic = tmp1;
			small->weight = tmp2;
		}
		P = P->next;
	}
	graphNode* V = G->adj_List[node_Number];
	while (V != NULL) {
		printf(" %d %d", V->vertic, V->weight);
		V = V->next;
	}
	printf("\n");
}
void free_Graph(graphType* G) {
	for (int i = 0; i < 7; i++) {
		graphNode* P = G->adj_List[i];
		if (P == NULL) continue;
		graphNode* P2 = P->next;
		while (P2 != NULL) {
			free(P);
			P = P2;
			P2 = P2->next;
		}
		free(P);
	}
}