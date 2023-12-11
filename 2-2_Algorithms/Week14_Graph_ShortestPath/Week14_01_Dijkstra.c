#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#pragma warning(disable:4996)

/* Dijkstra 알고리즘
* 무방향 양의 가중그래프 - 인접리스트 구조
*/

typedef struct edgenode {
	int v1, v2, weight;
	struct edgenode* next;
}EdgeNode;

typedef struct incidentedge {
	EdgeNode* IEdge;
	struct incidentedge* next;
}IncidentEdge;

typedef struct vertexnode {
	int num, weight;
	struct vertexnode* next;
	IncidentEdge* IEdges;
}VertexNode;

typedef struct graph {
	VertexNode* Vertices;
	EdgeNode* Edges;
	int n, m;
}Graph;

typedef struct queue {
	VertexNode* Vertices[101];
	int size;
}Queue;

Graph* graph = NULL;
Queue* queue = NULL;
int s;

void init_Graph();
void make_Graph();
void insert_Vertex(int);
void insert_Edge(int, int, int);
void insert_IncidentEdges(int, int, EdgeNode*);
void print_Vertex();
void free_Edges();
void free_Vertices();
void free_IncidentEdges(); // 인접 간선 메모리 해제
VertexNode* find_Vertex(int);
VertexNode* opposite_Vertex(VertexNode*, EdgeNode*);

void init_Queue();
void make_Queue();
void enqueue(VertexNode*);
void swap_Element(int, int);
void queue_Sort();
void downHeap(int);
void print_Queue();
bool queue_isempty();
VertexNode* dequeue();

void Dijkstra();

int main() {
	init_Graph();
	make_Graph();
	init_Queue();

	Dijkstra();
	print_Vertex();

	free_Vertices();
	free_Edges();
	free(graph);
	free(queue);
	return 0;
}

void init_Graph() {
	graph = (Graph*)malloc(sizeof(Graph));
	graph->Vertices = NULL;
	graph->Edges = NULL;
	graph->n = 0; graph->m = 0;
}
void make_Graph() {
	int n, m;
	scanf("%d %d %d", &n, &m, &s);
	graph->n = n; graph->m = m;
	for (int i = 1; i <= n; i++) {
		insert_Vertex(i);
	}

	int v1, v2, weight;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &v1, &v2, &weight);
		insert_Edge(v1, v2, weight);
	}
}
void insert_Vertex(int i) {
	VertexNode* newVertex = (VertexNode*)malloc(sizeof(VertexNode));
	newVertex->next = NULL;
	newVertex->num = i;
	newVertex->weight = 0;
	newVertex->IEdges = NULL;
	if (graph->Vertices == NULL)
		graph->Vertices = newVertex;
	else {
		VertexNode* V = graph->Vertices;
		while (V->next != NULL) {
			V = V->next;
		}
		V->next = newVertex;
	}
}
void insert_Edge(int v1, int v2, int weight) {
	EdgeNode* newEdge = (EdgeNode*)malloc(sizeof(EdgeNode));
	newEdge->next = NULL;
	newEdge->v1 = v1;
	newEdge->v2 = v2;
	newEdge->weight = weight;
	if (graph->Edges == NULL) {
		graph->Edges = newEdge;
	}
	else {
		EdgeNode* E = graph->Edges;
		while (E->next != NULL)
			E = E->next;
		E->next = newEdge;
	}
	insert_IncidentEdges(v1, v2, newEdge);
}
void insert_IncidentEdges(int v1, int v2, EdgeNode* E) {
	IncidentEdge* IE1 = (IncidentEdge*)malloc(sizeof(IncidentEdge));
	IE1->IEdge = E;
	IE1->next = NULL;

	VertexNode* V1 = find_Vertex(v1);
	
	if (V1->IEdges == NULL) {
		V1->IEdges = IE1;
	}
	else {
		IncidentEdge* IE = V1->IEdges;
		while (IE->next != NULL)
			IE = IE->next;
		IE->next = IE1;
	}

	IncidentEdge* IE2 = (IncidentEdge*)malloc(sizeof(IncidentEdge));
	IE2->IEdge = E;
	IE2->next = NULL;

	VertexNode* V2 = find_Vertex(v2);

	if (V2->IEdges == NULL) {
		V2->IEdges = IE2;
	}
	else {
		IncidentEdge* IE = V2->IEdges;
		while (IE->next != NULL)
			IE = IE->next;
		IE->next = IE2;
	}
	
}
void print_Vertex() {
	for (VertexNode* V = graph->Vertices; V != NULL; V = V->next) {
		if (V->num == s || V->weight >= 30000) continue;
		printf("%d %d\n", V->num, V->weight);
	}
}
void free_Vertices() {
	VertexNode* V = graph->Vertices;
	VertexNode* V2 = graph->Vertices->next;
	while (V2 != NULL) {
		//free_IncidentEdges(V);
		free(V);
		V = V2;
		V2 = V2->next;
	}
	//free_IncidentEdges(V);
	free(V);
}
void free_Edges() {
	EdgeNode* E = graph->Edges;
	EdgeNode* E2 = graph->Edges->next;
	while (E2 != NULL) {
		free(E);
		E = E2;
		E2 = E2->next;
	}
	free(E);
}
void free_IncidentEdges(VertexNode* V) {
	IncidentEdge* IE = V->IEdges;
	IncidentEdge* IE2 = V->IEdges->next;
	while (IE2 != NULL) {
		free(IE);
		IE = IE2;
		IE2 = IE2->next;
	}
	free(IE);
}
VertexNode* find_Vertex(int v) {
	for (VertexNode* V = graph->Vertices; V != NULL; V = V->next) {
		if (V->num == v) return V;
	}
	printf("Not Found!!");
	return NULL;
}
VertexNode* opposite_Vertex(VertexNode* V, EdgeNode* E) {
	for (IncidentEdge* IE = V->IEdges; IE != NULL; IE = IE->next) {
		if (IE->IEdge == E) {
			if (V->num == E->v1)
				return find_Vertex(E->v2);
			else if (V->num == E->v2)
				return find_Vertex(E->v1);
		}
	}
	printf("Opposite Not Found!\n");
	return NULL;
}

void init_Queue() {
	queue = (Queue*)malloc(sizeof(Queue));
	queue->size = 0;
}
void make_Queue() {
	for (VertexNode* V = graph->Vertices; V != NULL; V = V->next)
		enqueue(V);
	queue_Sort();
}
void enqueue(VertexNode* V) {
	queue->Vertices[++queue->size] = V;
}
void swap_Element(int v1, int v2) {
	VertexNode* V = queue->Vertices[v1];
	queue->Vertices[v1] = queue->Vertices[v2];
	queue->Vertices[v2] = V;
}
void queue_Sort() {
	for (int i = queue->size / 2; i>=1; i--) {
		downHeap(i);
	}
}
void downHeap(int index) {
	int left = index * 2, right = index * 2 + 1;
	if (left > queue->size && right > queue->size)
		return;
	int smaller = left;
	if (right <= queue->size)
		if (queue->Vertices[smaller]->weight > queue->Vertices[right]->weight)
			smaller = right;
	if (queue->Vertices[index]->weight <= queue->Vertices[smaller]->weight)
		return;
	swap_Element(index, smaller);
	downHeap(smaller);
}
void print_Queue() {
	for (int i = 1; i <= graph->n; i++) {
		printf("%d %d\n", queue->Vertices[i]->num, queue->Vertices[i]->weight);
	}
}
bool queue_isempty() {
	if (queue->size >= 1) return false;
	else return true;
}
VertexNode* dequeue() {
	VertexNode* V = queue->Vertices[1];
	swap_Element(1, queue->size--);
	downHeap(1);
	return V;
}

void Dijkstra() {
	for (VertexNode* V = graph->Vertices; V != NULL; V = V->next)
		V->weight = 30000;
	find_Vertex(s)->weight = 0;
	make_Queue();
	while (!queue_isempty()) {
		VertexNode* Z = dequeue();
		for (IncidentEdge* IE = Z->IEdges; IE != NULL; IE = IE->next) {
			VertexNode* U = opposite_Vertex(Z, IE->IEdge);
			if (Z->weight + IE->IEdge->weight <= U->weight) {
				U->weight = Z->weight + IE->IEdge->weight;
				queue_Sort();
			}
		}
		//printf("%d %d\n", Z->num, Z->weight);
	}
}