#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

/* Binary search tree
* �ǻ��ڵ� �˰����� �������� �ʰ� �ۼ��� �����̴�.
* �ش� ���������� ����ִ� �ڽĳ��鿡�� �޸𸮸� �ο��ϴ� ������ ���� ���Ӱ� �ۼ��� �����̴�.
* �ƽ��� �����δ� ���γ��� �ܺγ�带 ���ϴ� �Լ��� ���� �Ͱ� ���� ���� 2����
* ��峢�� ��ü�϶�� ���� ������ �ۼ��Ǿ� ���� ���� ������ Ȯ���Ͽ� key ���� ��ü�� ���̴�.
*/

typedef struct b_TreeNode {
	int key;
	struct node* left, * right, * parent;
}B_TreeNode;

bool isroot(B_TreeNode*); // root �Ǻ�  �Լ�
B_TreeNode* rightchild(B_TreeNode*); // ������ �ڽ� ��ȯ
B_TreeNode* leftchild(B_TreeNode*); // ���� �ڽ� ��ȯ
B_TreeNode* createNode(int, B_TreeNode*); // ��� ���� �Լ�
B_TreeNode* findNode_binarytree(B_TreeNode*, int); // key���� ��� ã�Ƽ� ��ȯ
B_TreeNode* inorderSucc(B_TreeNode*); // ������ȸ �İ��� y ã��
void reduceExternal(B_TreeNode*); // �ܺ� Ʈ����� ����
void invalidNodeException(); // ���� �޽���
void insert_binarytree(B_TreeNode**, int, B_TreeNode*); // ��� ����
int search_binarytree(B_TreeNode*, int); // key���� ��� �ִ��� Ȯ�� �� ��ȯ (�Է� Ű ������ 'X'���)
int delete_binarytree(B_TreeNode*, int); // ��� ���� (Ű ������ 'X' ���)
void print_binarytree(B_TreeNode*); // Ʈ�� ��� ���

int main() {
	int c, key, x;
	B_TreeNode* root = NULL;

	while ((c = getchar()) != EOF && c != 'q') {
		if (c == 'i') {
			scanf("%d", &key);
			insert_binarytree(&root, key, root);
		}
		else if (c == 's') {
			scanf("%d", &key);
			x = search_binarytree(root, key);
			if (x > 0) printf("%d\n", x);
			else printf("X\n");
		}
		else if (c == 'd') {
			scanf("%d", &key);
			x = delete_binarytree(root, key);
			if (x > 0) printf("%d\n", x);
			else printf("X\n");
		}
		else if (c == 'p') {
			print_binarytree(root);
			printf("\n");
		}
	}

	return 0;
}

bool isroot(B_TreeNode* node) {
	if (node->parent == NULL) return true;
	return false;
}
B_TreeNode* rightchild(B_TreeNode* node) {
	if (node == NULL) return NULL;
	return node->right;
}
B_TreeNode* leftchild(B_TreeNode* node) {
	return node->left;
}
B_TreeNode* parent(B_TreeNode* node) {
	if (node == NULL) return NULL;
	return node->parent;
}
B_TreeNode* createNode(int key1, B_TreeNode* parent) {
	B_TreeNode* newnode = (B_TreeNode*)malloc(sizeof(B_TreeNode));

	newnode->key = key1;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->parent = parent;

	return newnode;
}
B_TreeNode* findNode_binarytree(B_TreeNode* node, int key) {
	B_TreeNode* H;
	if (node == NULL) return NULL;
	if (node->key == key) return node;
	H = findNode_binarytree(node->left, key);
	if (H != NULL) return H;
	H = findNode_binarytree(node->right, key);
	return H;
}
B_TreeNode* inorderSucc(B_TreeNode* node) {
	B_TreeNode* node2 = rightchild(node);
	if (node2==NULL)
		invalidNodeException();
	while (node2->left != NULL) {
		node2 = leftchild(node2);
	}
	
	return node2;
}

void reduceExternal(B_TreeNode* node) {
	B_TreeNode* H = parent(node), *node_sibling;
	if(!isroot(node)) {
		if (node->left != NULL)
			node_sibling = node->left;
		else
			node_sibling = node->right;

		if (H->left == node)
			H->left = node_sibling;
		else
			H->right = node_sibling;
	}
	free(node);


}

int delete_binarytree(B_TreeNode* node, int key) { // Ű ������ 'X' ���
	B_TreeNode* H = findNode_binarytree(node, key);

	if (H == NULL) return 0;

	if ((H->left != NULL) && (H->right != NULL)) { 
		B_TreeNode* P = inorderSucc(H);
		H->key = P->key; // ��屳ü���� �ʰ� Ű ���� ��ȯ.
		reduceExternal(P);
	}
	else { // (H->left == NULL) || (H->right == NULL)
		reduceExternal(H);
	}
	return key;
}

void invalidNodeException() {
	printf("invalid node exception!");
}
void print_binarytree(B_TreeNode* node) {
	if (node == NULL) return;
	printf(" %d", node->key);
	print_binarytree(node->left);
	print_binarytree(node->right);
}
int search_binarytree(B_TreeNode* node, int key) { // �Է� Ű ������ 'X'���
	int res = 0;
	if (node == NULL) return 0;
	if (node->key == key) return node->key;
	res = search_binarytree(node->left, key);
	if (res > 0) return res;
	res = search_binarytree(node->right, key);
	return res;
}
void insert_binarytree(B_TreeNode** node, int key, B_TreeNode* parent) {
	if (*node == NULL) {
		*node = createNode(key, parent);
		return;
	}
	if (key < (*node)->key) {
		insert_binarytree(&(*node)->left, key, *node);
	}
	else if ((*node)->key < key) {
		insert_binarytree(&(*node)->right, key, *node);
	}
}