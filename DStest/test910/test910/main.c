#include <stdio.h>
#include <stdlib.h>

// TreeNode 구조체 정의
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 배열을 이진 트리로 변환하는 함수 (수정하지 않음)
void GenerateArrayTree(int* tree) {
    int list[] = {1, 2, 9, 3, 5, 10, 13, 4, 6, 7, 8, 11, 12, 14, 15};
    for(int i = 0; i < 15; i++) {
        tree[i] = list[i];
    }
    for(int i = 0; i < 15; i++) {
        printf("%d ", tree[i]);
    }
    printf("\n");
}

// 전위 순회 (배열 인덱스를 사용)
void ArrayPreOrder(int* tree, int index, int size) {
    if (index >= size || tree[index] == -1) return;

    printf("[%2d] ", tree[index]);  // 루트 노드 출력
    ArrayPreOrder(tree, 2 * index + 1, size); // 왼쪽 자식 순회
    ArrayPreOrder(tree, 2 * index + 2, size); // 오른쪽 자식 순회
}

// 중위 순회 (배열 인덱스를 사용)
void ArrayInOrder(int* tree, int index, int size) {
    if (index >= size || tree[index] == -1) return;

    ArrayInOrder(tree, 2 * index + 1, size); // 왼쪽 자식 순회
    printf("[%2d] ", tree[index]);  // 루트 노드 출력
    ArrayInOrder(tree, 2 * index + 2, size); // 오른쪽 자식 순회
}

// 후위 순회 (배열 인덱스를 사용)
void ArrayPostOrder(int* tree, int index, int size) {
    if (index >= size || tree[index] == -1) return;

    ArrayPostOrder(tree, 2 * index + 1, size); // 왼쪽 자식 순회
    ArrayPostOrder(tree, 2 * index + 2, size); // 오른쪽 자식 순회
    printf("[%2d] ", tree[index]);  // 루트 노드 출력
}

// 트리 순회 함수 (배열 기반)
void ArrayOrders(int* tree, int size) {
    ArrayPreOrder(tree, 0, size);
    printf("\n");
    ArrayInOrder(tree, 0, size);
    printf("\n");
    ArrayPostOrder(tree, 0, size);
    printf("\n\n");
}

// 전위 순회
void LinkPreOrder(TreeNode* node) {
    if (node != NULL) {
        printf("[%2d] ", node->data);  // 루트 노드 출력
        LinkPreOrder(node->left);      // 왼쪽 서브트리 순회
        LinkPreOrder(node->right);     // 오른쪽 서브트리 순회
    }
}

// 중위 순회
void LinkInOrder(TreeNode* node) {
    if (node != NULL) {
        LinkInOrder(node->left);       // 왼쪽 서브트리 순회
        printf("[%2d] ", node->data);  // 루트 노드 출력
        LinkInOrder(node->right);      // 오른쪽 서브트리 순회
    }
}

// 후위 순회
void LinkPostOrder(TreeNode* node) {
    if (node != NULL) {
        LinkPostOrder(node->left);     // 왼쪽 서브트리 순회
        LinkPostOrder(node->right);    // 오른쪽 서브트리 순회
        printf("[%2d] ", node->data);  // 루트 노드 출력
    }
}

// 트리 순회 함수 (연결리스트 기반)
void LinkOrders(TreeNode* root) {
    LinkPreOrder(root);
    printf("\n");
    LinkInOrder(root);
    printf("\n");
    LinkPostOrder(root);
    printf("\n\n");
}

// 노드를 생성하는 함수
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 배열에서 인덱스를 사용해 이진 트리를 생성하는 함수
void InsertNode(TreeNode** node, int* list, int index, int size) {
    if (index >= size || list[index] == -1) return;

    if (*node == NULL) {
        *node = createNode(list[index]);
    }
    InsertNode(&(*node)->left, list, 2 * index + 1, size);
    InsertNode(&(*node)->right, list, 2 * index + 2, size);
}

int main() {
    int arr[15];
    GenerateArrayTree(arr);
        
        // 루트 노드를 생성하여 1로 초기화
    TreeNode* root = NULL;
    InsertNode(&root, arr, 0, 15);
        
    ArrayOrders(arr, 15);
    LinkOrders(root);
        
    return 0;
    }
           
