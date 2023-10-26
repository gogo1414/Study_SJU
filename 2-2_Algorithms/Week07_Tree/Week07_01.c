#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

/* ����Ž��Ʈ�� ���� (�ǻ��ڵ� ����)
* ��带 ������ �� ���� ���� �ڽİ� ������ �ڽ��� Ȯ���Ű�� ����Ʈ���̴�.
* ��� ���� : key, left, right, parent
* ��� : ����, ����, Ž��, ���, ����
*/

typedef struct node {
	struct node* parent;
	struct node* left;
	struct node* right;
	int key;
}Node; // ����� ����
typedef struct tree {
	Node* root;
}Tree; // tree, root���

bool isRoot(Node*); // root���� Ȯ��
bool isExternal(Node*); // �ܺ� ��� Ȯ��
bool isInternal(Node*); // ���� ��� Ȯ��

int find_key(Node*, int); // �ش� Ű�� ã�� ������ 'X' ���
int remove_Node(Tree*, int); // ��� ����
void insert_Key(Tree*, int); // Ʈ���� Ű ����
void print_Tree(Node*); // Ʈ�� ���
void invalid_Node_Exception(); // ���� �Ұ� ��ġ ����
void destroy_Tree(Node*); // tree �޸� ����

Node* expand_node(Node*); // ��� Ȯ��
Node* leftchild(Node*); // ��� ���� �ڽ� ��� ��ȯ
Node* rightchild(Node*); // ��� ������ �ڽ� ��� ��ȯ
Node* parent(Node*); // ����� �θ� ��� ��ȯ
Node* tree_Search(Node*, int); // �ش� Ű���� ��� ��ȯ ���� �� �ܺγ�� ��ȯ
Node* inOrderSucc(Node*); // ������ȸ �İ��� ��ȯ
Node* sibling(Node*); // �ڽŰ� ������ ��尡 ���γ���� ���� ��ȯ
Node* reduceExternal(Node*); // �ܺγ�� ���


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

int remove_Node(Tree* tree, int key) {
	Node* S = tree_Search(tree->root, key), * P;
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
	}
	else {
		Node* P = inOrderSucc(S);
		S->key = P->key;
		reduceExternal(P->left);
	}
	return n;
}
int find_key(Node* root, int k) {
	int S = 0;
	if (isExternal(root)) return 0;
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
	printf(" %d", root->key);
	print_Tree(root->left);
	print_Tree(root->right);
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
	}
}
void destroy_Tree(Node* root) {
	if (!isExternal(root->left)) destroy_Tree(root->left);
	if (!isExternal(root->right)) destroy_Tree(root->right);
	free(root);
}

Node* expand_node(Node* node) {
	Node* left = (Node*)malloc(sizeof(Node));
	Node* right = (Node*)malloc(sizeof(Node));

	left->left = NULL;
	left->right = NULL;
	left->key = 0;
	left->parent = node;

	right->left = NULL;
	right->right = NULL;
	right->key = 0;
	right->parent = node;

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
	return node_sibling;
}