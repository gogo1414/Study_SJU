#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#pragma warning(disable:4996)

/* Kruskal 알고리즘 구현
* 최소신장트리 생성 프로그램 
* 간선리스트 구조
*/

typedef struct vertexnode { // 정점 노드
	int v;
	struct vertexnode* next;
	struct vertexnode* parent;
}VertexNode;

typedef struct edgenode { // 간선 노드
	int v1, v2, weight;
	struct edgenode* next;
}EdgeNode;

typedef struct graph { // 그래프 구조
	int n, m;
	VertexNode* Vertices;
	EdgeNode* Edges;
}Graph;

typedef struct queue { // 우선순위 큐
	EdgeNode* Edges[1001];
	int size;
}Queue;

typedef struct sets { // 분리 집합
	int size;
	VertexNode* Vertices[101];
}Sets;

Graph* graph = NULL;
Queue* queue = NULL;
Sets* sets = NULL;
Queue* MST = NULL;

void init_MST(); // MST 큐 초기화
void add_MST(EdgeNode*); // MST 삽입
void print_MST(); // MST 출력

void init_graph(); // 그래프 초기화
void make_graph(); // 그래프 생성
void insert_Vertex(int); // 정점 노드 삽입
void insert_Edge(int, int, int); // 간선 노드 삽입
void free_Vertices(); // 정점 메모리 해제
void free_Edges(); // 간선 메모리 해제
VertexNode* find_Vertex(int); // 해당 num 정점 노드 반환

void init_queue(); // 우선순위 큐 초기화
void make_queue(); // 우선순위 큐 생성
void enqueue(EdgeNode*); // 큐 삽입
bool Q_isempty(); // 큐 비어있는 여부 반환
EdgeNode* dequeue(); // 큐 삭제
void buildHeap(); // 힙 생성
void downHeap(int); // 다운힙
void swapNode(int, int); // 노드 교환

void init_sets(); // 분할집합 초기화
void make_sets(); // 분할집합 생성
void unionSets(int, int); // 집합 합치기
VertexNode* find(int); // 집합 루트 찾기

void KruskalMST_DisjointSets(); // Kruskal 알고리즘

int main() {
	init_graph();
	make_graph();
	init_queue();
	KruskalMST_DisjointSets();
	print_MST();

	free_Vertices();
	free_Edges();
	free(graph);
	free(queue);
	free(sets);
	free(MST);
	return 0;
}

void init_MST() {
	MST = (Queue*)malloc(sizeof(Queue));
	MST->size = 0;
}
void add_MST(EdgeNode* E) {
	MST->Edges[++MST->size] = E;
}
void print_MST() {
	int sum = 0, t = 0;
	for (int i = 1; i <= MST->size; i++) {
		t = MST->Edges[i]->weight;
		printf(" %d", t);
		sum += t;
	}
	printf("\n%d\n", sum);
}

void init_graph() {
	graph = (Graph*)malloc(sizeof(Graph));
	graph->Edges = NULL;
	graph->Vertices = NULL;
	graph->n = 0;
	graph->m = 0;
}
void make_graph() {
	int n, m, v1, v2, weight;
	scanf("%d %d", &n, &m);
	graph->n = n; graph->m = m;

	for (int i = 1; i <= n; i++) {
		insert_Vertex(i);
	}

	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &v1, &v2, &weight);
		insert_Edge(v1, v2, weight);
	}
}
void insert_Vertex(int v) {
	VertexNode* newVertex = (VertexNode*)malloc(sizeof(VertexNode));
	newVertex->v = v;
	newVertex->next = NULL;
	if (graph->Vertices == NULL)
		graph->Vertices = newVertex;
	else {
		VertexNode* V = graph->Vertices;
		while (V->next != NULL)
			V = V->next;
		V->next = newVertex;
	}
}
void insert_Edge(int v1, int v2, int weight) {
	EdgeNode* newEdge = (EdgeNode*)malloc(sizeof(EdgeNode));
	newEdge->v1 = v1;
	newEdge->v2 = v2;
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
void free_Vertices() {
	VertexNode* V = graph->Vertices;
	VertexNode* V2 = graph->Vertices->next;
	while (V2 != NULL) {
		free(V);
		V = V2;
		V2 = V2->next;
	}
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
VertexNode* find_Vertex(int N) {
	for (VertexNode* V = graph->Vertices; V != NULL; V = V->next) {
		if (V->v == N)
			return V;
	}
	printf("Not Exists Vertex!!\n");
	exit(0);
}

void init_queue() {
	queue = (Queue*)malloc(sizeof(Queue));
	queue->size = 0;
}
void make_queue() {
	for (EdgeNode* E = graph->Edges; E != NULL; E = E->next) {
		enqueue(E);
	}
	buildHeap();
}
void enqueue(EdgeNode* E) {
	if (++queue->size > graph->m) {
		printf("Queue is FULL!!\n");
		exit(0);
	}
	queue->Edges[queue->size] = E;
}
void buildHeap() {
	for (int i = queue->size / 2; i >= 1; i--) {
		downHeap(i);
	}
}
void downHeap(int index) {
	int left = index * 2, right = index * 2 + 1;
	if (left > queue->size && right > queue->size)
		return;
	int smaller = left;
	if (right <= queue->size)
		if (queue->Edges[smaller]->weight > queue->Edges[right]->weight)
			smaller = right;
	if (queue->Edges[index]->weight <= queue->Edges[smaller]->weight)
		return;
	swapNode(index, smaller);
	downHeap(smaller);
}
void swapNode(int x1, int x2) {
	EdgeNode* tmp = queue->Edges[x1];
	queue->Edges[x1] = queue->Edges[x2];
	queue->Edges[x2] = tmp;
}
EdgeNode* dequeue() {
	if (Q_isempty()) {
		printf("Queue is Empty\n");
		exit(0);
	}
	EdgeNode* E = queue->Edges[1];
	swapNode(1, queue->size--);
	downHeap(1);
	return E;
}
bool Q_isempty() {
	if (queue->size >= 1)
		return false;
	else
		return true;
}

void init_sets() {
	sets = (Sets*)malloc(sizeof(Sets));
	sets->size = 0;
}
void make_sets() {
	init_sets();
	int i = 0;
	for (VertexNode* V = graph->Vertices; V != NULL; V = V->next) {
		V->parent = V;
		sets->Vertices[++sets->size] = V;
	}
}
VertexNode* find(int V) {
	if (sets->Vertices[V]->parent == find_Vertex(V)) {
		return find_Vertex(V);
	}
	return
		sets->Vertices[V]->parent = find(sets->Vertices[V]->parent->v);
}
void unionSets(int v1, int v2) {
	VertexNode* V1 = find(v1);
	VertexNode* V2 = find(v2);

	if (V1->v < V2->v) {
		V2->parent = V1;
	}
	else {
		V1->parent = V2;
	}

}

void KruskalMST_DisjointSets() {
	make_sets();
	make_queue();
	init_MST();

	while (!Q_isempty()) {
		EdgeNode* E = dequeue(); // E->v1 : 4, E->v2 : 3
		if (find(E->v1) != find(E->v2)) {
			add_MST(E);
			unionSets(E->v1, E->v2);
		}
	}
}