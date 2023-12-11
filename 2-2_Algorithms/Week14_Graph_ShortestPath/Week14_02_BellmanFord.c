#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* BellmanFord 알고리즘
* 방향 가중그래프 - 간선 리스트 구조
* 경로의 최대 값이 몇일지에 대한 생각을 고찰해야함
* 음의 가중치가 존재하기 때문에 30000 보다 살짝 작은 값들이 존재하기 때문
*/

typedef struct vertexnode {
	int num, weight;
	struct vertexnode* next;
}VertexNode;

typedef struct edgenode {
	int origin, destination, weight;
	struct edgenode* next;
}EdgeNode;

typedef struct graph {
	VertexNode* Vertices;
	EdgeNode* Edges;
	int n, m;
}Graph;

Graph* graph = NULL;
int s;

void init_Graph();
void make_Graph();
void insert_Vertex(int);
void insert_Edge(int, int, int);
void print_Vertex();
void free_Vertex();
void free_Edge();
VertexNode* find_Vertex(int);

void BellmanFord();

int main() {
	init_Graph();
	make_Graph();

	BellmanFord();
	print_Vertex();

	free_Vertex();
	free_Edge();
	free(graph);

	return 0;
}

void init_Graph() {
	graph = (Graph*)malloc(sizeof(Graph));
	graph->Edges = NULL;
	graph->Vertices = NULL;
	graph->n = 0;
	graph->m = 0;
}
void make_Graph() {
	int n, m;
	
	scanf("%d %d %d", &n, &m, &s);
	graph->n = n;
	graph->m = m;
	for (int i = 1; i <= n; i++) {
		insert_Vertex(i);
	}

	int v1, v2, weight;

	for (int j = 0; j < m; j++) {
		scanf("%d %d %d", &v1, &v2, &weight);
		insert_Edge(v1, v2, weight);
	}

}
void insert_Vertex(int v) {
	VertexNode* newVertex = (VertexNode*)malloc(sizeof(VertexNode));
	newVertex->next = NULL;
	newVertex->num = v;
	newVertex->weight = 0;

	if (graph->Vertices == NULL) {
		graph->Vertices = newVertex;
	}
	else {
		VertexNode* V = graph->Vertices;
		while (V->next != NULL)
			V = V->next;
		V->next = newVertex;
	}
}
void insert_Edge(int v1, int v2, int weight) {
	EdgeNode* newEdge = (EdgeNode*)malloc(sizeof(EdgeNode));
	newEdge->origin = v1;
	newEdge->destination = v2;
	newEdge->weight = weight;
	newEdge->next = NULL;

	if (graph->Edges == NULL)
		graph->Edges = newEdge;
	else {
		EdgeNode* E = graph->Edges;
		while (E->next != NULL)
			E = E->next;
		E->next = newEdge;
	}
}
void print_Vertex() {
	for (VertexNode* V = graph->Vertices; V != NULL; V = V->next) {
		if (V->weight >= 20000 || V->num == s) continue;
		printf("%d %d\n", V->num, V->weight);
	}
}
void free_Vertex() {
	VertexNode* V1 = graph->Vertices;
	VertexNode* V2 = graph->Vertices->next;

	while (V2 != NULL) {
		free(V1);
		V1 = V2;
		V2 = V2->next;
	}
	free(V1);

}
void free_Edge() {
	EdgeNode* E1 = graph->Edges;
	EdgeNode* E2 = graph->Edges->next;

	while (E2 != NULL) {
		free(E1);
		E1 = E2;
		E2 = E2->next;
	}
	free(E1);
}
VertexNode* find_Vertex(int v) {
	for (VertexNode* V = graph->Vertices; V != NULL; V = V->next) {
		if (V->num == v) return V;
	}
	printf("Not Found!!\n");
	exit(0);
}

void BellmanFord() {
	for (VertexNode* V = graph->Vertices; V != NULL; V = V->next)
		V->weight = 30000;

	find_Vertex(s)->weight = 0;
	for (int i = 1; i <= graph->n - 1; i++) {
		for (EdgeNode* E = graph->Edges; E != NULL; E = E->next) {
			VertexNode* origin = find_Vertex(E->origin);
			VertexNode* destination = find_Vertex(E->destination);
			if (origin->weight + E->weight < destination->weight) {
				destination->weight = origin->weight + E->weight;
			}
		}
	}
}K