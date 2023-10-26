#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

/* AVL 트리 구현 (의사코드 참조)
* 노드를 생성할 때 마다 왼쪽 자식과 오른쪽 자식을 확장시키는 이진트리이다.
* 노드 구조 : key, height, left, right, parent
* 기능 : 삽입, 삭제, 탐색, 출력, 종료
* 어려움 : 
* 1. parent 를 제대로 전달하는 것
* 2. 포인터 노드를 전달하더라도 바뀐 내용이 저장되지 않는다는 것
* 3. 삭제할 때 노드의 높이 초기화를 하지 않은 것.
*/

typedef struct node {
	struct node* parent;
	struct node* left;
	struct node* right;
	int height;
	int key;
}Node; // 노드 구조
typedef struct tree {
	Node* root;
}Tree; // 트리 구조

bool isEmpty(Node*); // 비어있는 공간인지 확인
bool isRoot(Node*); // root인지 확인
bool isExternal(Node*); // 외부 노드 확인
bool isInternal(Node*); // 내부 노드 확인
bool isBalanced(Node*); // 균형확인
bool is_LRfind(Node*, Node*); // 왼쪽 true 오른쪽 false

int find_key(Node*, int); // 해당 키값 찾기 없으면 'X' 출력
int remove_Node(Tree*, int); // 노드 삭제
void insert_Key(Tree*, int); // 트리에 키 삽입
void print_Tree(Node*); // 트리 출력
void invalid_Node_Exception(); // 접근 불가 위치 에러
void height_reset(Node*); // 높이 설정 함수
void searchAndFixAfterInsertion(Tree*, Node*); // 삽입 후 균형 검사를 통해 높이균형 속성 회복
void destroy_Tree(Node*); // tree 메모리 해제
void searchAndFixAfterRemoval(Tree*, Node*); // 삭제 후 균형 검사를 통해 높이균형 속성 회복

Node* expand_node(Node*); // 노드 확장
Node* leftchild(Node*); // 노드 왼쪽 자식 노드 반환
Node* rightchild(Node*); // 노드 오른쪽 자식 노드 반환
Node* parent(Node*); // 노드의 부모 노드 반환
Node* tree_Search(Node*, int); // 해당 키값의 노드 반환 없을 시 외부노드 반환
Node* inOrderSucc(Node*); // 중위순회 후계자 반환
Node* sibling(Node*); // 자신과 형제인 노드가 내부노드라면 형제 반환
Node* reduceExternal(Node*); // 외부노드 축소 
Node* moreHeight(Node*); // 자식 노드들 중 더 높이가 높은 노드 반환
Node* restructure(Node*, Node*, Node*); // 노드 개조 수행후 해당 노드 반환


int main() {
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	tree->root = (Node*)malloc(sizeof(Node));
	tree->root->parent = NULL, tree->root->left = NULL, tree->root->right = NULL;
	int c, key, S;
	while ((c = getchar()) != EOF && c != 'q') {
		if (c == 'i') {
			scanf("%d", &key);
			insert_Key(tree, key);
		}
		else if (c == 'd') {
			scanf("%d", &key);
			S = remove_Node(tree, key);
			if (S != 0)
				printf("%d\n", S);
			else printf("X\n");
		}
		else if (c == 's') {
			scanf("%d", &key);
			S = find_key(tree->root, key);
			if (S != 0)
				printf("%d\n", S);
			else printf("X\n");
		}
		else if (c == 'p') {
			if (tree->root == NULL) continue;
			print_Tree(tree->root);
			printf("\n");
		}
	}
	if (tree->root != NULL)
		destroy_Tree(tree->root);
	free(tree);
	return 0;
}

bool isEmpty(Node* node) {
	if (node == NULL) return true;
	else return false;
}
bool isExternal(Node* node) {
	if ((node->left == NULL) && (node->right == NULL))
		return true;
	else return false;
}
bool isInternal(Node* node) {
	if ((node->left != NULL) || (node->right != NULL))
		return true;
	else return false;
}
bool isRoot(Node* node) {
	if (node->parent == NULL) return true;
	else return false;
}
bool isBalanced(Node* node) {
	int n = node->left->height > node->right->height ? (node->left->height) - (node->right->height) : (node->right->height) - (node->left->height);
	if (n <= 1)
		return true;
	else return false;
}
bool is_LRfind(Node* parent, Node* sibling) {
	if (parent->left == sibling) return true;
	else return false;
}

int remove_Node(Tree* tree, int key) {
	if (tree->root == NULL) return 0;
	Node* S = tree_Search(tree->root, key), * P = NULL;
	int n = 0;
	if (S->key == key) n = S->key;
	else return n;
	if (isExternal(S->left) || isExternal(S->right)) {
		if (isExternal(S->left))
			P = reduceExternal(S->left);
		else
			P = reduceExternal(S->right);
		if (isRoot(P))
			tree->root = P;
		if (parent(P) != NULL) {
			searchAndFixAfterRemoval(tree, parent(P));
		}
	}
	else {
		Node* P = inOrderSucc(S);
		S->key = P->key;
		P = reduceExternal(P->left);
		searchAndFixAfterRemoval(tree, parent(P));
	}

	return n;
}
void searchAndFixAfterRemoval(Tree* tree, Node* node) {
	Node* z = node; // 61
	while (!isRoot(z) && isBalanced(z)) {
		z = z->parent; // 38
	}
	if (isBalanced(z)) return;
	Node* y = moreHeight(z); // z의 높은 자식
	Node* x = moreHeight(y); // y의 높은 자식
	Node* b = restructure(x, y, z);
	while (!isRoot(b) && isBalanced(b)) {
		b = b->parent;
		if (!isBalanced(b)) {
			Node* y = moreHeight(b); // z의 높은 자식
			Node* x = moreHeight(y); // y의 높은 자식
			b = restructure(x, y, b);
		}
	}
	while (!isRoot(b)) {
		b = b->parent;
	}
	tree->root = b;

	return;
}
int find_key(Node* root, int k) {
	int S = 0;
	if (root == NULL || isExternal(root)) return 0;
	if (root->key == k) return k;
	S = find_key(root->left, k);
	if (S == k) return k;
	S = find_key(root->right, k);
	return S;
}
void invalid_Node_Exception() {
	printf("invaild Node Exception");
	exit(0);
}
void print_Tree(Node* root) {
	if (isExternal(root)) return;
	printf(" %d", root->key );
	print_Tree(root->left);
	print_Tree(root->right);
}
void height_reset(Node* node) {
	Node* P = node;

	while (!isEmpty(P)) {
		if (isInternal(P->left) && isInternal(P->right))
			P->height = (P->left->height) > (P->right->height) ? (P->left->height + 1) : (P->right->height + 1);
		else if (isInternal(P->right))
			P->height = P->right->height + 1;
		else
			P->height = P->left->height + 1;
		P = P->parent;
	}
}
void insert_Key(Tree* tree, int key) {
	if (isExternal(tree->root)) {
		tree->root->key = key;
		expand_node(tree->root);
	}
	else {
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->key = key;
		newnode = expand_node(newnode);
		Node* P = tree_Search(tree->root, key);
		if (P->key < key) {
			P->right = newnode;
		}
		else {
			P->left = newnode;
		}

		newnode->parent = P;
		height_reset(P); // 높이를 일정하게 맞춰주는 함수
		searchAndFixAfterInsertion(tree, P);
	}
}
void searchAndFixAfterInsertion(Tree* tree, Node* node) {
	Node* z = node;
	while (!isRoot(z) && isBalanced(z)) {
		z = z->parent;
	}
	if (isBalanced(z)) return;
	Node* y = moreHeight(z); // z의 높은 자식
	Node* x = moreHeight(y); // y의 높은 자식
	z = restructure(x, y, z);
	while (!isRoot(z)) {
		z = z->parent;
	}
	tree->root = z;

	return;
}
void destroy_Tree(Node* root) {
	if (!isExternal(root->left)) destroy_Tree(root->left);
	if (!isExternal(root->right)) destroy_Tree(root->right);
	free(root);
}

Node* restructure(Node* x, Node* y, Node* z) {
	Node* a, * b, * c, * T0, * T1, * T2, * T3;
	if (is_LRfind(z, y)) { // y가 z의 왼쪽 자식이면 true
		if (is_LRfind(y, x)) { // 싱글회전
			a = x, b = y, c = z;
			T0 = x->left, T1 = x->right, T2 = y->right, T3 = z->right;
		}
		else { // 더블회전
			a = y, b = x, c = z;
			T0 = y->left, T1 = x->left, T2 = x->right, T3 = z->right;
		}
	}
	else {
		if (is_LRfind(y, x)) { // 더블회전
			a = z, b = x, c = y;
			T0 = z->left, T1 = x->left, T2 = x->right, T3 = y->right;
		}
		else { // 싱글회전
			a = z, b = y, c = x;
			T0 = z->left, T1 = y->left, T2 = x->left, T3 = x->right;
		}
	}
	if (!isRoot(z) && is_LRfind(z->parent, z)) z->parent->left = b;
	else if (!isRoot(z) && !is_LRfind(z->parent, z)) z->parent->right = b;
	b->parent = z->parent, z = b;

	a->left = T0, a->right = T1, T0->parent = a, T1->parent = a, a->parent = b;
	c->left = T2, c->right = T3, T2->parent = c, T3->parent = c, c->parent = b;

	b->left = a, b->right = c;
	height_reset(a);
	height_reset(c);
	return b;
}
Node* moreHeight(Node* node) {
	if ((node->left->height) >= (node->right->height)) return node->left;
	else return node->right;
}
Node* expand_node(Node* node) {
	Node* left = (Node*)malloc(sizeof(Node));
	Node* right = (Node*)malloc(sizeof(Node));

	left->left = NULL;
	left->right = NULL;
	left->height = 0;
	left->parent = node;

	right->left = NULL;
	right->right = NULL;
	right->height = 0;
	right->parent = node;

	node->height = 1;
	node->left = left;
	node->right = right;

	return node;
}
Node* leftchild(Node* node) {
	return node->left;
}
Node* rightchild(Node* node) {
	return node->right;
}
Node* parent(Node* node) {
	return node->parent;
}
Node* tree_Search(Node* root, int key) {
	Node* S = root;
	if (isExternal(S->left) && isExternal(S->right)) return S;
	else {
		if (key < S->key && isInternal(S->left))
			S = tree_Search(S->left, key);
		else if (key > S->key && isInternal(S->right)) {
			S = tree_Search(S->right, key);
		}
		return S;
	}
}
Node* inOrderSucc(Node* root) {
	Node* P = root->right;

	if (isExternal(P))
		invalid_Node_Exception();

	while (isInternal(P->left)) {
		P = P->left;
	}

	return P;
}
Node* sibling(Node* node) {
	if (isRoot(node))
		invalid_Node_Exception();
	if (leftchild(parent(node)) == node)
		return rightchild(parent(node));
	else
		return leftchild(parent(node));
}
Node* reduceExternal(Node* node) {
	Node* node_parent = parent(node);
	Node* node_sibling = sibling(node);
	if (isRoot(node_parent)) {
		node_sibling->parent = NULL;
	}
	else {
		Node* g = parent(node_parent);
		node_sibling->parent = g;
		if (node_parent == g->left)
			g->left = node_sibling;
		else
			g->right = node_sibling;
	}
	free(node);
	free(node_parent);
	height_reset(parent(node_sibling));
	return node_sibling;
}