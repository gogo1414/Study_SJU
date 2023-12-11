#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

/* Prim-Jarnik �˰���
* �ּҽ���Ʈ��(MST)�� �����ϴ� ���α׷��� �ۼ� �� ���� ������ �ѹ��Ը� ����� ���
* ���� ����Ʈ ����
*/


typedef struct edgenode { // ���� ���
	int v1, v2, weight;
	struct edgenode* next;
}EdgeNode;

typedef struct incidentedge { // ���� ����
	EdgeNode* edge;
	struct incidentedge* next;
}IncidentEdge;

typedef struct vertexnode { // ���� ���
	int num, weight;
	struct vertexnode* next;
	EdgeNode* parent;
	IncidentEdge* IE;
}VertexNode;

typedef struct graph { // �׷��� ����
	int n, m;
	VertexNode* Vertices;
	EdgeNode* Edges;
}Graph;

typedef struct queue { // �켱���� ť ����
	VertexNode* Vertices[101];
	int size;
} Queue;

Graph* graph = NULL;
Queue* queue = NULL;
Queue* MST = NULL;

void init_MST(); // MST ť �ʱ�ȭ
void add_MST(VertexNode*); // MST ������� ����
void print_MST(); // MST ���

void init_Graph(); // graph �ʱ�ȭ
void make_Graph(); // graph ����
void insert_Vertex(int); // ���� ��� ����
void insert_IncidentEdge(int, EdgeNode*); // ���� ���� ����
void insert_Edge(int, int, int); // ���� ��� ����
void free_IncidentEdges(); // ���� ���� �޸� ����
void free_Vertices(); // ���� �޸� ����
void free_Edges(); // ���� �޸� ����
VertexNode* opposite_Vertex(VertexNode*, EdgeNode*); // ������ ����� ������ �ݴ� ���� ��ȯ
VertexNode* find_Vertex(int); // �ش� num ���� ���� ��ȯ

void init_Queue(); // �켱���� ť �ʱ�ȭ
void make_Queue(); // �켱���� ť ����
void enqueue(VertexNode*); //ť ����
void swapNode(int, int); // ť ��ȯ
void downHeap(int); // �ٿ���
void buildHeap(); // ������
bool is_InQ(VertexNode*); // �ش� ���� ť�� ���� ���� Ȯ��
bool Q_isEmpty(); // ť ����ִ��� Ȯ��
VertexNode* dequeue(); // ť ����

void PrimJarnikMST(); // PrimJarnik �˰���
void Q_replaceKey(); // �ǻ��ڵ��� �̸��� ��������� �뵵�� �ٸ��� �̿�..

int main() {
	init_Graph();
	init_Queue();
	init_MST();
	make_Graph();
	PrimJarnikMST();
	print_MST();

	free_Vertices();
	free_Edges();
	free(queue);
	free(graph);
	free(MST);
	return 0;
}

void init_MST() {
	MST = (Queue*)malloc(sizeof(Queue));
	MST->size = 0;
}
void add_MST(VertexNode* V) {
	MST->Vertices[++MST->size] = V;
}
void print_MST() {
	int sum = 0;
	for (int i = 1; i <= graph->n; i++) {
		sum += MST->Vertices[i]->weight;
		printf(" %d", MST->Vertices[i]->num, MST->Vertices[i]->weight);
	}
	printf("\n%d\n", sum);
}

void init_Graph() {
	graph = (Graph*)malloc(sizeof(Graph));
	graph->Vertices = NULL;
	graph->Edges = NULL;
	graph->n = 0;
	graph->m = 0;
}
void make_Graph() {
	int n, m, v1, v2, weight;
	scanf("%d %d", &n, &m);
	graph->n = n;
	graph->m = m;

	for (int i = 1; i <= n; i++)
		insert_Vertex(i);

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &v1, &v2, &weight);
		insert_Edge(v1, v2, weight);
	}
}
void insert_Vertex(int i) {
	VertexNode* newVertex = (VertexNode*)malloc(sizeof(VertexNode));
	newVertex->IE = NULL;
	newVertex->num = i;
	newVertex->next = NULL;
	VertexNode* V = graph->Vertices;
	if (V == NULL) {
		graph->Vertices = newVertex;
	}
	else {
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

	EdgeNode* E = graph->Edges;
	if (E == NULL) {
		graph->Edges = newEdge;
	}
	else {
		while (E->next != NULL) {
			E = E->next;
		}
		E->next = newEdge;
	}
	insert_IncidentEdge(v2, newEdge);
	insert_IncidentEdge(v1, newEdge);

}
void insert_IncidentEdge(int v, EdgeNode* E) {
	VertexNode* V1 = find_Vertex(v);

	IncidentEdge* newIE = (IncidentEdge*)malloc(sizeof(IncidentEdge));
	newIE->next = NULL;
	newIE->edge = E;

	IncidentEdge* IE = V1->IE;
	if (IE == NULL)
		V1->IE = newIE;
	else {
		while (IE->next != NULL) {
			IE = IE->next;
		}
		IE->next = newIE;
	}
}
void free_IncidentEdges(VertexNode* V) {
	IncidentEdge* IE = V->IE;
	IncidentEdge* IE2 = V->IE->next;
	while (IE2 != NULL) {
		free(IE);
		IE = IE2;
		IE2 = IE2->next;
	}
	free(IE);
}
void free_Vertices() {
	VertexNode* V = graph->Vertices;
	VertexNode* V2 = graph->Vertices->next;
	while (V2 != NULL) {
		free_IncidentEdges(V);
		free(V);
		V = V2;
		V2 = V2->next;
	}
	free_IncidentEdges(V);
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
VertexNode* opposite_Vertex(VertexNode* V, EdgeNode* E) {
	if (V->num == E->v1)
		return find_Vertex(E->v2);
	else
		return find_Vertex(E->v1);
	printf("opposite Error!!\n");
	return NULL;
}
VertexNode* find_Vertex(int v) {
	VertexNode* V = graph->Vertices;
	if (V == NULL) {
		printf("find Error!\n");
		exit(0);
	}
	while (V != NULL) {
		if (V->num == v) return V;
		V = V->next;
	}
	printf("Npt Found!!\n");
	return NULL;
}

void init_Queue() {
	queue = (Queue*)malloc(sizeof(Queue));
	queue->size = 0;
}
void make_Queue() {
	for (VertexNode* V = graph->Vertices; V != NULL; V = V->next) {
		enqueue(V);
	}
	buildHeap();
	//for (int i = 1; i <= queue->size; i++)
	//	printf(" %d(%d)", queue->Vertices[i]->num, queue->Vertices[i]->weight);
	//printf("\n");
}
void enqueue(VertexNode* V) {
	if (++queue->size > graph->m) {
		printf("Queue is FULL\n");
		exit(0);
	}
	queue->Vertices[queue->size] = V;
}
void swapNode(int index, int smaller) {
	VertexNode* tmp = queue->Vertices[index];
	queue->Vertices[index] = queue->Vertices[smaller];
	queue->Vertices[smaller] = tmp;
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
	swapNode(index, smaller);
	downHeap(smaller);
}
void buildHeap() {
	for (int i = queue->size / 2; i >= 1; i--)
		downHeap(i);
}
bool Q_isEmpty() {
	if (queue->size >= 1)
		return false;
	return true;
}
bool is_InQ(VertexNode* V) {
	for (int i = 1; i <= queue->size; i++) {
		if (queue->Vertices[i] == V)
			return true;
	}
	return false;
}
VertexNode* dequeue() {
	if (Q_isEmpty()) {
		printf("Queue is Empty!!\n");
		exit(0);
	}
	VertexNode* V = queue->Vertices[1];
	swapNode(1, queue->size--);
	downHeap(1);
	return V;
}

void Q_replaceKey() {
	buildHeap();
}
void PrimJarnikMST() {
	for (VertexNode* V = graph->Vertices; V != NULL; V = V->next) {
		V->weight = 100000;
		V->parent = NULL;
	}

	VertexNode* S = find_Vertex(1);
	S->weight = 0;
	make_Queue();

	while (!Q_isEmpty()) {
		VertexNode* U = dequeue();
		for (IncidentEdge* IE = U->IE; IE != NULL; IE = IE->next) {
			VertexNode* Z = opposite_Vertex(U, IE->edge);
			if (is_InQ(Z) && (IE->edge->weight < Z->weight)) {
				Z->weight = IE->edge->weight;
				Z->parent = IE->edge;
				Q_replaceKey();
			}
		}
		add_MST(U);
	}
}