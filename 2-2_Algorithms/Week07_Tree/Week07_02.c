#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

/* AVL Ʈ�� ���� (�ǻ��ڵ� ����)
* ��带 ������ �� ���� ���� �ڽİ� ������ �ڽ��� Ȯ���Ű�� ����Ʈ���̴�.
* ��� ���� : key, height, left, right, parent
* ��� : ����, Ž��, ���, ����
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
void insert_Key(Tree*, int); // Ʈ���� Ű ����
void print_Tree(Node*); // Ʈ�� ���
void invalid_Node_Exception(); // ���� �Ұ� ��ġ ����
void height_reset(Node*); // ���� ���� �Լ�
void searchAndFixAfterInsertion(Tree*, Node*); // ���� �˻縦 ���� ���̱��� �Ӽ� ȸ��
void destroy_Tree(Node*); // tree �޸� ����

Node* expand_node(Node*); // ��� Ȯ��
Node* leftchild(Node*); // ��� ���� �ڽ� ��� ��ȯ
Node* rightchild(Node*); // ��� ������ �ڽ� ��� ��ȯ
Node* parent(Node*); // ����� �θ� ��� ��ȯ
Node* tree_Search(Node*, int); // �ش� Ű���� ��� ��ȯ ���� �� �ܺγ�� ��ȯ
Node* moreHeight(Node*); // �ڽ� ���� �� �� ���̰� ���� ��� ��ȯ
Node* restructure(Node* , Node* , Node* ); // ��� ���� ������ �ش� ��� ��ȯ


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
		/*else if (c == 'd') { ���� ��� ���� X
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
	Node* a, * b, * c, *T0, *T1, *T2, *T3;
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