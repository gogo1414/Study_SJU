#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

// tree�� node ����
typedef struct node {
	struct node* left;
	int data;
	struct node* right;
}TreeNode;

// ��Ʈ��� ���� �Լ�
TreeNode* rootinsert(int data, TreeNode* left, TreeNode* right) {
	TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
	
	newnode->left = left;
	newnode->right = right;
	newnode->data = data;

	return newnode;
}

void preorder(TreeNode* node); // ������ȸ �Լ�
bool isempty(TreeNode* node); // node�� �ִ��� Ȯ�� �Լ�

//main �Լ�
int main() {
	int n = 1;
	// root ���� �Լ��� ����� �ʱ�ȭ���ش�.
	TreeNode* f8 = rootinsert(80, NULL, NULL);
	TreeNode* f7 = rootinsert(130, NULL, NULL);
	TreeNode* f6 = rootinsert(120, f7, f8);
	TreeNode* f5 = rootinsert(90, NULL, NULL);
	TreeNode* f4 = rootinsert(70, NULL, NULL);
	TreeNode* f3 = rootinsert(50, NULL, f6);
	TreeNode* f2 = rootinsert(30, f4, f5);
	TreeNode* f1 = rootinsert(20, f2, f3);


	scanf("%d", &n);
		
	//switc �� ���� ���� ��ȸ �Լ� ȣ��
	switch (n) {
	case 1: preorder(f1); break;
	case 2: preorder(f2); break;
	case 3: preorder(f3); break;
	case 4: preorder(f4); break;
	case 5: preorder(f5); break;
	case 6: preorder(f6); break;
	case 7: preorder(f7); break;
	case 8: preorder(f8); break;
	default: preorder(NULL); break;
	}
	

	return 0;
}

// ���� ��ȸ �Լ� ����
void preorder(TreeNode* node) {
	if (isempty(node)) {
		printf("%d ", node->data);
		if(isempty(node->left))	printf("%d ", node->left->data);
		if (isempty(node->right)) printf("%d ", node->right->data);
	}
	else printf("-1");
}

// node Ȯ�� �Լ�
bool isempty(TreeNode* node) {
	if (node == NULL)
		return false;
	else
		return true;
}