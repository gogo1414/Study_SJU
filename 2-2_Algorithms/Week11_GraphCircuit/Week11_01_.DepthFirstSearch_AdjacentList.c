#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* ���̿켱Ž�� Depth-First Search (AdjacentList)
* ���� : n (1 <= n <= 100), ���� : m (1 <= m <= 1000)
* ��� ������ ������ ����, �� �������� ������ �ٸ� �������� ���� ��δ� �ݵ�� ����
* ���� ���� ���� ������ ���� u�� ���� �������� ��ȣ�� ���� �������� �����Ѵ�.
* Fresh : 0, Visited : 1, Tree : 2, Back : 3
*/

// ���� ��� : �� �� ������ ���� next�� �̷����
typedef struct edgeNode {
	int V1, V2, state;
	struct edgeNode* next;
}EdgeNode;

// �������� ����Ʈ : ������ ������� next�� �̷����
typedef struct incidentEdge {
	EdgeNode* edge;
	struct incidentEdge* next;
} IncidentEdge;

// ���� ��� : ���� V�� next�� �̷����
typedef struct vertexNode {
	int V, state;
	struct vertexNode* next;
	IncidentEdge* iedges;
} VertexNode;

// �׷��� : ������� ������� �̷����
typedef struct graph {
	int n, m; // ���� ���� ���� ��
	VertexNode* verticies;
	EdgeNode* edges;
} Graph;

void init_Graph(Graph*, int, int);
void make_Vertic(Graph*, int);
void make_Edge(Graph*, int);
void insert_IncidentEdge(Graph*, EdgeNode*, int, int);
void sort_IncidentEdge(VertexNode*);
int opposite(VertexNode*, IncidentEdge*);
void swap_IEdgeNode(IncidentEdge*, IncidentEdge*);
VertexNode* find_Vertex(Graph*, int);
void DFS(Graph*, int);
void rDFS(Graph*, VertexNode*);
void free_IncidentEdges(VertexNode*);
void free_Vertices(Graph*);
void free_Edges(Graph*);

int main() {
	int n, m, s;
	Graph* graph = (Graph*)malloc(sizeof(Graph));

	scanf("%d %d %d", &n, &m, &s);
	init_Graph(graph, n, m);
	make_Vertic(graph, n);
	make_Edge(graph, m);
	DFS(graph, s);
	free_Vertices(graph);
	free_Edges(graph);
	free(graph);
	return 0;
}

void init_Graph(Graph* G, int n, int m) {
	G->verticies = NULL;
	G->edges = NULL;
	G->n = n;
	G->m = m;
}
void make_Vertic(Graph* G, int n) {
	for (int i = 1; i <= n; i++) {
		VertexNode* newVertex = (VertexNode*)malloc(sizeof(VertexNode));
		newVertex->V = i;
		newVertex->next = G->verticies;
		newVertex->iedges = NULL;
		G->verticies = newVertex;
	}
}
void make_Edge(Graph* G, int m) {
	int v1, v2;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &v1, &v2);
		EdgeNode* newEdge = (EdgeNode*)malloc(sizeof(EdgeNode));
		newEdge->V1 = v1;
		newEdge->V2 = v2;
		newEdge->next = G->edges;
		G->edges = newEdge;
		insert_IncidentEdge(G, newEdge, v1, v2);
	}
}
void sort_IncidentEdge(VertexNode* V) {
	IncidentEdge* F_IE = V->iedges;
	if (F_IE == NULL) return;
	while (F_IE->next != NULL) {
		if (opposite(V, F_IE) > opposite(V, F_IE->next)) {
			swap_IEdgeNode(F_IE, F_IE->next);
		}
		else
			F_IE = F_IE->next;
	}
}
void swap_IEdgeNode(IncidentEdge* E1, IncidentEdge* E2) {
	EdgeNode* tmp = E1->edge;
	E1->edge = E2->edge;
	E2->edge = tmp;
}
void insert_IncidentEdge(Graph* G, EdgeNode* edge, int v1, int v2) {
	VertexNode* V1 = G->verticies;
	while (V1 != NULL) {
		if (V1->V == v1) break;
		else V1 = V1->next;
	}
	VertexNode* V2 = G->verticies;
	while (V2 != NULL) {
		if (V2->V == v2) break;
		else V2 = V2->next;
	}
	if (V1 == NULL || V2 == NULL) {
		printf("Insert Error!");
		exit(0);
	}

	IncidentEdge* newIEdge1 = (IncidentEdge*)malloc(sizeof(IncidentEdge));

	newIEdge1->edge = edge;
	newIEdge1->next = V1->iedges;
	V1->iedges = newIEdge1;

	IncidentEdge* newIEdge2 = (IncidentEdge*)malloc(sizeof(IncidentEdge));

	newIEdge2->edge = edge;
	newIEdge2->next = V2->iedges;
	V2->iedges = newIEdge2;

	sort_IncidentEdge(V1);
	sort_IncidentEdge(V2);
}
int opposite(VertexNode* V, IncidentEdge* IE) {
	if (V == NULL) printf("Error1");
	if (IE == NULL) printf("Error2");
	if (V->V == IE->edge->V1)
		return IE->edge->V2;
	else
		return IE->edge->V1;
}
VertexNode* find_Vertex(Graph* G, int v) {
	VertexNode* V = G->verticies;
	while (V != NULL) {
		if (V->V == v)
			return V;
		else
			V = V->next;
	}
	if (V == NULL) {
		printf("Find_Vertex Error!");
		return V;
	}
}
void DFS(Graph* G, int s) {
	VertexNode* V = G->verticies, * S = NULL;
	EdgeNode* E = G->edges;
	for (int i = 0; i < G->n; i++) {
		V->state = 0;
		if (V->V == s) S = V;
		V = V->next;
	}
	for (int i = 0; i < G->m; i++) {
		E->state = 0;
		E = E->next;
	}
	if (S == NULL) {
		printf("DFS Error!");
		exit(0);
	}
	rDFS(G, S);
}
void rDFS(Graph* G, VertexNode* S) {
	S->state = 1; // �湮 ���� �����
	printf("%d\n", S->V);
	IncidentEdge* IE = S->iedges;
	while (IE != NULL) {
		if (IE->edge->state == 0) {
			int S_opposite = opposite(S, IE);
			VertexNode* V = find_Vertex(G, S_opposite);
			if (V->state == 0) {
				IE->edge->state = 2;
				rDFS(G, V);
			}
			else
				IE->edge->state = 3;
		}
		IE = IE->next;
	}
}
void free_IncidentEdges(VertexNode* V) {
	IncidentEdge* IE = V->iedges;
	IncidentEdge* IE2 = V->iedges->next;
	while (IE2 != NULL) {
		free(IE);
		IE = IE2;
		IE2 = IE2->next;
	}
	free(IE);

}
void free_Vertices(Graph* G) {
	VertexNode* V = G->verticies;
	VertexNode* V2 = G->verticies->next;
	while (V2 != NULL) {
		free_IncidentEdges(V);
		free(V);
		V = V2;
		V2 = V2->next;
	}
	free_IncidentEdges(V);
	free(V);
}
void free_Edges(Graph* G) {
	EdgeNode* E = G->edges;
	EdgeNode* E2 = E->next;
	while (E2 != NULL) {
		free(E);
		E = E2;
		E2 = E2->next;
	}
	free(E);
}