#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

/* AVL Ʈ�� ���� (�ǻ��ڵ� ����)
* ��带 ������ �� ���� ���� �ڽİ� ������ �ڽ��� Ȯ���Ű�� ����Ʈ���̴�.
* ��� ���� : key, height, left, right, parent
* ��� : ����, ����, Ž��, ���, ����
* ����� : 
* 1. parent �� ����� �����ϴ� ��
* 2. ������ ��带 �����ϴ��� �ٲ� ������ ������� �ʴ´ٴ� ��
* 3. ������ �� ����� ���� �ʱ�ȭ�� ���� ���� ��.
*/

typedef struct node {
	struct node* parent;
	struct node* left;
	struct node* right;
	int height;
	int key;
}Node; // ��� ����
typedef struct tree {
	Node* root;
}Tree; // Ʈ�� ����

bool isEmpty(Node*); // ����ִ� �������� Ȯ��
bool isRoot(Node*); // root���� Ȯ��
bool isExternal(Node*); // �ܺ� ��� Ȯ��
bool isInternal(Node*); // ���� ��� Ȯ��
bool isBalanced(Node*); // ����Ȯ��
bool is_LRfind(Node*, Node*); // ���� true ������ false

int find_key(Node*, int); // �ش� Ű�� ã�� ������ 'X' ���
int remove_Node(Tree*, int); // ��� ����
void insert_Key(Tree*, int); // Ʈ���� Ű ����
void print_Tree(Node*); // Ʈ�� ���
void invalid_Node_Exception(); // ���� �Ұ� ��ġ ����
void height_reset(Node*); // ���� ���� �Լ�
void searchAndFixAfterInsertion(Tree*, Node*); // ���� �� ���� �˻縦 ���� ���̱��� �Ӽ� ȸ��
void destroy_Tree(Node*); // tree �޸� ����
void searchAndFixAfterRemoval(Tree*, Node*); // ���� �� ���� �˻縦 ���� ���̱��� �Ӽ� ȸ��

Node* expand_node(Node*); // ��� Ȯ��
Node* leftchild(Node*); // ��� ���� �ڽ� ��� ��ȯ
Node* rightchild(Node*); // ��� ������ �ڽ� ��� ��ȯ
Node* parent(Node*); // ����� �θ� ��� ��ȯ
Node* tree_Search(Node*, int); // �ش� Ű���� ��� ��ȯ ���� �� �ܺγ�� ��ȯ
Node* inOrderSucc(Node*); // ������ȸ �İ��� ��ȯ
Node* sibling(Node*); // �ڽŰ� ������ ��尡 ���γ���� ���� ��ȯ
Node* reduceExternal(Node*); // �ܺγ�� ��� 
Node* moreHeight(Node*); // �ڽ� ���� �� �� ���̰� ���� ��� ��ȯ
Node* restructure(Node*, Node*, Node*); // ��� ���� ������ �ش� ��� ��ȯ


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
	Node* y = moreHeight(z); // z�� ���� �ڽ�
	Node* x = moreHeight(y); // y�� ���� �ڽ�
	Node* b = restructure(x, y, z);
	while (!isRoot(b) && isBalanced(b)) {
		b = b->parent;
		if (!isBalanced(b)) {
			Node* y = moreHeight(b); // z�� ���� �ڽ�
			Node* x = moreHeight(y); // y�� ���� �ڽ�
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
		height_reset(P); // ���̸� �����ϰ� �����ִ� �Լ�
		searchAndFixAfterInsertion(tree, P);
	}
}
void searchAndFixAfterInsertion(Tree* tree, Node* node) {
	Node* z = node;
	while (!isRoot(z) && isBalanced(z)) {
		z = z->parent;
	}
	if (isBalanced(z)) return;
	Node* y = moreHeight(z); // z�� ���� �ڽ�
	Node* x = moreHeight(y); // y�� ���� �ڽ�
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
	if (is_LRfind(z, y)) { // y�� z�� ���� �ڽ��̸� true
		if (is_LRfind(y, x)) { // �̱�ȸ��
			a = x, b = y, c = z;
			T0 = x->left, T1 = x->right, T2 = y->right, T3 = z->right;
		}
		else { // ����ȸ��
			a = y, b = x, c = z;
			T0 = y->left, T1 = x->left, T2 = x->right, T3 = z->right;
		}
	}
	else {
		if (is_LRfind(y, x)) { // ����ȸ��
			a = z, b = x, c = y;
			T0 = z->left, T1 = x->left, T2 = x->right, T3 = y->right;
		}
		else { // �̱�ȸ��
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