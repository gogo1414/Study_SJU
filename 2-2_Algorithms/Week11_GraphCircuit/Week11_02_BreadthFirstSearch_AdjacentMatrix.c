#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* 너비 우선 탐색 BreadthFirstSearch (AdjacentMatrix)
* 정점 : n (1 <= n <= 100), 간선 : m (1 <= m <= 1000)
* 모든 간선은 무방향 간선, 한 정점에서 임의의 다른 정점으로 가는 경로는 반드시 존재
* 인접 정점 조사 순서는 정점 u의 인접 정점들을 번호가 작은 정점부터 조사한다.
* Fresh : 0, Visited : 1, Tree : 2, Cross : 3
*/

// 간선 노드 v1, v2 : 양 끝 정점 수, state : 상태
typedef struct edgeNode {
	int v1, v2, state;
	struct edgeNode* next;
}EdgeNode;

// 인접행렬
typedef struct adjacentMatrix {
	EdgeNode* edge;
}AdjacentMatrix;

// 정점 노드 V : 정점 수
typedef struct vertexNode {
	int V, state;
	struct vertexNode* next;
}VertexNode;

// 정점리스트 vertex: 정점 노드
typedef struct vertexList {
	VertexNode* vertex;
	struct vertexList* next;
}VertexList;

// 그래프 n : 정점 갯수, 인접행렬
typedef struct graph {
	int n;
	VertexNode* Vertices;
	EdgeNode* Edges;
	AdjacentMatrix matrix[101][101];
	VertexList* list;
}Graph;

void init_Graph(Graph*, int);
void make_Vertices(Graph*);
void make_Edges(Graph*, int);
void addLast(Graph*, VertexList*, VertexNode*);
VertexNode* find_Vertex(Graph*, int);
void BFS(Graph*, int);
void BFS2(Graph*, VertexNode*);
void free_Vertices(Graph*);
void free_Edges(Graph*);
void free_VertexList(VertexList*);

int main() {
	int n, m, s;
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	scanf("%d %d %d", &n, &m, &s);
	init_Graph(graph, n);
	make_Vertices(graph);
	make_Edges(graph, m);
	BFS(graph, s);
	free_Vertices(graph);
	free_Edges(graph);
	free(graph);
	return 0;
}

void init_Graph(Graph* G, int n) {
	G->Edges = NULL;
	G->n = n;
	G->Vertices = NULL;

	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			G->matrix[i][j].edge = NULL;
}
void make_Vertices(Graph* G) {
	for (int i = 1; i <= G->n; i++) {
		VertexNode* newnode = (VertexNode*)malloc(sizeof(VertexNode));
		newnode->next = G->Vertices;
		newnode->V = i;
		G->Vertices = newnode;
	}
}
void make_Edges(Graph* G, int m) {
	int v1, v2;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &v1, &v2);
		EdgeNode* newnode = (EdgeNode*)malloc(sizeof(EdgeNode));
		newnode->v1 = v1;
		newnode->v2 = v2;
		newnode->next = G->Edges;
		G->Edges = newnode;
		G->matrix[v1][v2].edge = newnode;
		G->matrix[v2][v1].edge = newnode;
	}
}
VertexNode* find_Vertex(Graph* G, int s) {
	VertexNode* V = G->Vertices;
	while (V != NULL) {
		if (V->V == s) break;
		V = V->next;
	}
	return V;
}
void BFS(Graph* G, int s) {
	VertexNode* V = G->Vertices, * S = NULL;
	while (V != NULL) {
		V->state = 0;
		if (V->V == s)
			S = V;
		V = V->next;
	}
	EdgeNode* E = G->Edges;
	while (E != NULL) {
		E->state = 0;
		E = E->next;
	}
	if (S == NULL) {
		printf("BFS Error!\n");
		exit(0);
	}
	BFS2(G, S);
}
void BFS2(Graph* G, VertexNode* S) {
	VertexList* L = (VertexList*)malloc(sizeof(VertexList));
	G->list = L;
	L->vertex = S;
	L->next = NULL;
	S->state = 1;
	printf("%d\n", L->vertex->V);
	while (L != NULL) {
		for (int i = 1; i <= 100; i++) {
			if (G->matrix[L->vertex->V][i].edge != NULL) {
				if (G->matrix[L->vertex->V][i].edge->state == 0) {
					VertexNode* P = find_Vertex(G, i);
					if (P->state == 0) {
						printf("%d\n", P->V);
						G->matrix[L->vertex->V][i].edge->state = 2;
						G->matrix[i][L->vertex->V].edge->state = 2;
						P->state = 1;
						addLast(G, L, P);
					}
					else {
						G->matrix[L->vertex->V][i].edge->state = 3;
						G->matrix[i][L->vertex->V].edge->state = 3;
					}
				}
			}
		}
		L = L->next;
	}
	free_VertexList(G->list);
}
void addLast(Graph* G, VertexList* VL, VertexNode* P) {
	VertexList* newnode = (VertexList*)malloc(sizeof(VertexList));
	newnode->vertex = P;
	newnode->next = NULL;
	VertexList* L = VL;
	while (L->next != NULL) L = L->next;
	L->next = newnode;
}
void free_Vertices(Graph* G) {
	VertexNode* V = G->Vertices;
	VertexNode* V2 = G->Vertices->next;
	while (V2 != NULL) {
		free(V);
		V = V2;
		V2 = V2->next;
	}
	free(V);
}
void free_Edges(Graph* G) {
	EdgeNode* E = G->Edges;
	EdgeNode* E2 = G->Edges->next;
	while (E2 != NULL) {
		free(E);
		E = E2;
		E2 = E2->next;
	}
	free(E);
}
void free_VertexList(VertexList* VL) {
	VertexList* V = VL;
	VertexList* V2 = VL->next;
	while (V2 != NULL) {
		free(V);
		V = V2;
		V2 = V2->next;
	}
	free(V);
}