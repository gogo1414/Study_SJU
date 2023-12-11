#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#pragma warning(disable:4996)
/* 방향그래프
* DAG면 위상순서를 구해 인쇄, DAG 아니면  0 인쇄
* 
*/

typedef struct edgenode { // 간선 노드
	char v1, v2;
	struct edgenode* next;
} EdgeNode;

typedef struct out_edges { // 나가는 간선
	EdgeNode* E;
	struct out_edges* next;
}outEdge;

typedef struct in_edges {  // 들어오는 간선
	EdgeNode* E;
	struct in_edges* next;
}InEdge;

typedef struct vertexnode { // 정점 노드
	char vertex;
	int in, out, index;
	struct vertexnode* next;
	outEdge* outEdges;
	InEdge* InEdges;
} VertexNode;

typedef struct queue { // 큐
	int front, rear;
	VertexNode* data[100];
}Queue;

typedef struct graph { // 그래프
	int n, m;
	VertexNode* Vertices;
	EdgeNode* Edges;
}Graph;

void init_Graph(); // 그래프 초기화
void init_Queue(); // 큐 초기화
void Build_Graph(); // 그래프 형성
void insert_Vertexnode(char); // 정점 노드 삽입
void insert_EdgeNode(char, char); // 간선 노드 삽입
void insert_InandOut(EdgeNode*, char, char); // 간선 방향 노드에 삽입
void enqueue(VertexNode*); // 큐에 정점 삽입
void topologicalSort(); // 위상 정렬
char index_Vertex(int); // 해당 인덱스의 문자 반환
VertexNode* dequeue(); // 큐 삭제후 정점 반환
bool isEmpty(); // 큐 비어있는지 확인
VertexNode* find_Vertex(char); // 해당 문자의 정점 반환

Graph* graph;
Queue* Q;
int* topOrder, num;

int main() {
	init_Graph();
	Build_Graph();
	init_Queue();
	topologicalSort();

	if (topOrder[0] == 0)
		printf("0\n");
	else {
		for (int i = 1; i <= graph->n; i++)
			printf(" %c", index_Vertex(topOrder[i]));
	}


	free(graph);
	free(Q);
	free(topOrder);
	return 0;
}

void Build_Graph() {
	int n, m;
	char c, v1, v2;
	scanf("%d", &n);
	getchar();
	graph->n = n;
	num = n - 1;
	topOrder = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i < n; i++) {
		scanf("%c", &c);
		getchar();
		insert_Vertexnode(c);
	}

	scanf("%d", &m);
	getchar();

	graph->m = m;
	for (int i = 0; i < m; i++) {
		scanf("%c %c", &v1, &v2);
		getchar();
		insert_EdgeNode(v1, v2);
	}
}
void init_Graph() {
	graph = (Graph*)malloc(sizeof(Graph));
	graph->Edges = NULL;
	graph->Vertices = NULL;
}
void init_Queue() {
	Q = (Queue*)malloc(sizeof(Queue));
	Q->front = -1;
	Q->rear = -1;
	//for (int i = 0; i < graph->n; i++)
	//	Q->data[i] = (VertexNode*)malloc(sizeof(VertexNode));
}
void insert_Vertexnode(char c) {
	VertexNode* newVertex = (VertexNode*)malloc(sizeof(VertexNode));

	newVertex->InEdges = NULL;
	newVertex->outEdges = NULL;
	newVertex->index = 0;
	newVertex->in = 0;
	newVertex->out = 0;
	newVertex->vertex = c;
	newVertex->next = NULL;

	VertexNode* GV = graph->Vertices;

	if (GV == NULL) {
		graph->Vertices = newVertex;
	}
	else {
		newVertex->index++;
		while (GV->next != NULL) {
			newVertex->index++;
			GV = GV->next;
		}
		GV->next = newVertex;
	}
}
void insert_EdgeNode( char v1, char v2) {
	EdgeNode* newEdge = (EdgeNode*)malloc(sizeof(EdgeNode));
	newEdge->v1 = v1;
	newEdge->v2 = v2;
	newEdge->next = graph->Edges;
	graph->Edges = newEdge;
	insert_InandOut(newEdge, v1, v2);
}
void insert_InandOut( EdgeNode* newEdge, char v1, char v2) {
	VertexNode* V1 = find_Vertex(v1);
	VertexNode* V2 = find_Vertex(v2);

	outEdge* out = (outEdge*)malloc(sizeof(outEdge));
	InEdge* In = (InEdge*)malloc(sizeof(InEdge));

	out->E = newEdge;
	In->E = newEdge;

	out->next = V1->outEdges;
	V1->outEdges = out;
	V1->out += 1;

	In->next = V2->InEdges;
	V2->InEdges = In;
	V2->in += 1;
}
void enqueue(VertexNode* V) {
	if (Q->rear == graph->n - 1) {
		printf("Queue is Full!!\n");
		return;
	}
	Q->data[++(Q->rear)] = V;
}
void topologicalSort() {
	VertexNode* V = graph->Vertices;
	for (int i = graph->n-1; i >= 0; i--) {
		if (V->in == 0) {
			enqueue(V);
		}
		V = V->next;
	}
	int k = 1;
	while (!isEmpty()) {
		VertexNode* U = dequeue();
		topOrder[k++] = U->index;
		outEdge* OE = U->outEdges;
		while (OE != NULL) {
			VertexNode* W = find_Vertex(OE->E->v2);
			W->in--;
			if (W->in == 0) {
				enqueue(W);
			}
			OE = OE->next;
		}
	}
	if (k <= graph->n)
		topOrder[0] = 0;
	else
		topOrder[0] = 1;
	
}
char index_Vertex(int index) {
	VertexNode* V = graph->Vertices;
	while (V != NULL) {
		if (V->index == index) return V->vertex;
		V = V->next;
	}
	printf("Error!!");
	return;
}
bool isEmpty() {
	if (Q->front == Q->rear)
		return true;
	else return false;
}
VertexNode* dequeue() {
	if (isEmpty()) {
		printf("Queue is Empty!!");
		return;
	}
	return Q->data[++(Q->front)];
}
VertexNode* find_Vertex(char v) {
	VertexNode* V = graph->Vertices;
	while (V != NULL) {
		if (V->vertex == v) break;
		V = V->next;
	}
	if (V == NULL) printf("find Error!!");

	return V;
}