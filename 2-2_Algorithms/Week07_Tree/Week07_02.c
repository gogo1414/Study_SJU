#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

/* AVL 트리 구현 (의사코드 참조)
* 노드를 생성할 때 마다 왼쪽 자식과 오른쪽 자식을 확장시키는 이진트리이다.
* 노드 구조 : key, height, left, right, parent
* 기능 : 삽입, 탐색, 출력, 종료
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
void insert_Key(Tree*, int); // 트리에 키 삽입
void print_Tree(Node*); // 트리 출력
void invalid_Node_Exception(); // 접근 불가 위치 에러
void height_reset(Node*); // 높이 설정 함수
void searchAndFixAfterInsertion(Tree*, Node*); // 균형 검사를 통해 높이균형 속성 회복
void destroy_Tree(Node*); // tree 메모리 해제

Node* expand_node(Node*); // 노드 확장
Node* leftchild(Node*); // 노드 왼쪽 자식 노드 반환
Node* rightchild(Node*); // 노드 오른쪽 자식 노드 반환
Node* parent(Node*); // 노드의 부모 노드 반환
Node* tree_Search(Node*, int); // 해당 키값의 노드 반환 없을 시 외부노드 반환
Node* moreHeight(Node*); // 자식 노드들 중 더 높이가 높은 노드 반환
Node* restructure(Node* , Node* , Node* ); // 노드 개조 수행후 해당 노드 반환


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
		/*else if (c == 'd') { 삭제 노드 구현 X
			scanf("%d", &key);
			S = remove_Node(tree->root, key);
			if (S != 0)
				printf("%d\n", S);
			else printf("X\n");
		}*/
		else if (c == 's') {
			scanf("%d", &key);
			S = find_key(tree->root, key);
			if (S != 0)
				printf("%d\n", S);
			else printf("X\n");
		}
		else if (c == 'p') {
			print_Tree(tree->root);
			printf("\n");
		}
	}
	if(tree->root != NULL)
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
}
void print_Tree(Node* root) {
	if (isExternal(root)) return;
	printf(" %d", root->key);
	print_Tree(root->left);
	print_Tree(root->right);
}
void height_reset(Node* node) {
	Node* P = node;
	
	while (!isEmpty(P)){
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
	Node* a, * b, * c, *T0, *T1, *T2, *T3;
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
	return (node->left->height) > (node->right->height) ? (node->left) : (node->right);
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