#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

/* Binary search tree
* 의사코드 알고리즘을 참고하지 않고 작성한 버전이다.
* 해당 문제에서는 비어있는 자식노드들에도 메모리를 부여하는 것으로 보여 새롭게 작성한 버전이다.
* 아쉬운 점으로는 내부노드와 외부노드를 비교하는 함수를 지운 것과 삭제 예시 2에서
* 노드끼리 교체하라는 말과 로직이 작성되어 있지 않은 것으로 확인하여 key 값만 교체한 것이다.
*/

typedef struct b_TreeNode {
	int key;
	struct node* left, * right, * parent;
}B_TreeNode;

bool isroot(B_TreeNode*); // root 판별  함수
B_TreeNode* rightchild(B_TreeNode*); // 오른쪽 자식 반환
B_TreeNode* leftchild(B_TreeNode*); // 왼쪽 자식 반환
B_TreeNode* createNode(int, B_TreeNode*); // 노드 생성 함수
B_TreeNode* findNode_binarytree(B_TreeNode*, int); // key값의 노드 찾아서 반환
B_TreeNode* inorderSucc(B_TreeNode*); // 중위순회 후계자 y 찾기
void reduceExternal(B_TreeNode*); // 외부 트리노드 삭제
void invalidNodeException(); // 오류 메시지
void insert_binarytree(B_TreeNode**, int, B_TreeNode*); // 노드 삽입
int search_binarytree(B_TreeNode*, int); // key값의 노드 있는지 확인 후 반환 (입력 키 없으면 'X'출력)
int delete_binarytree(B_TreeNode*, int); // 노드 삭제 (키 없으면 'X' 출력)
void print_binarytree(B_TreeNode*); // 트리 노드 출력

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

int delete_binarytree(B_TreeNode* node, int key) { // 키 없으면 'X' 출력
	B_TreeNode* H = findNode_binarytree(node, key);

	if (H == NULL) return 0;

	if ((H->left != NULL) && (H->right != NULL)) { 
		B_TreeNode* P = inorderSucc(H);
		H->key = P->key; // 노드교체하지 않고 키 값만 교환.
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
int search_binarytree(B_TreeNode* node, int key) { // 입력 키 없으면 'X'출력
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