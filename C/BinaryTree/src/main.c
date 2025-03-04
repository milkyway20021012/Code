#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "../include/Queue.h"

typedef int BTDataType;
typedef struct BinaryTreeNode
{
    BTDataType data;
    struct BinaryTreeNode *left;  // 左子
    struct BinaryTreeNode *right; // 右子
} BTNode;

BTNode *BuyNode(BTDataType x)
{
    BTNode *node = (BTNode *)malloc(sizeof(BTNode));
    if (node == NULL)
    {
        perror("malloc fail");
        exit(0);
    }
    node->data = x;
    node->left = NULL;
    node->right = NULL;

    return node;
}

BTNode *CreatTree()
{
    BTNode *node1 = BuyNode(1);
    BTNode *node2 = BuyNode(2);
    BTNode *node3 = BuyNode(3);
    BTNode *node4 = BuyNode(4);
    BTNode *node5 = BuyNode(5);
    BTNode *node6 = BuyNode(6);
    node1->left = node2;
    node1->right = node4;
    node2->left = node3;
    node2->right = node5;
    node4->left = node6;
    return node1;
}
// 前序遍歷 根--左子樹--右子樹
void PreOrder(BTNode *root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    printf("%d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

// 中序遍歷 左子樹--根--右子樹
void InOrder(BTNode *root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}
// 後序遍歷 左子樹--右子樹--根
void PostOrder(BTNode *root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->data);
}
// 層序遍歷 (用隊列實現 -- 出上一層帶入下一層)
void LevelOrder(BTNode *root)
{
    Queue q;
    QueueInit(&q);
    if (root != NULL)
    {
        QueuePush(&q, root);
    }
    while (!QueueEmpty(&q))
    {
        BTNode *front = QueueFront(&q);
        QueuePop(&q);
        printf("%d ", front->data);

        if (front->left)
        {
            QueuePush(&q, front->left);
        }
        if (front->right)
        {
            QueuePush(&q, front->right);
        }
    }
    QueueDestroy(&q);
}

// 1

// int size = 0;
// // 求節點個數
// void TreeSize(BTNode *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     ++size;
//     TreeSize(root->left);
//     TreeSize(root->right);
// }

// 2 指揮打工人
// int TreeSize(BTNode *root)
// {
//     return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1; // +1 是加自己
// }

int TreeSize(BTNode* root){
    if(root == NULL){
      return 0;
    }
    int lnum = TreeSize(root->left);
    int rnum = TreeSize(root->right);
    return lnum + rnum + 1;
  }
// 求高度
int TreeHeight(BTNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = TreeHeight(root->left);
    int rightHeight = TreeHeight(root->right);

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}
// 
int TreeKLevel(BTNode *root, int k)
{
    if (root == NULL)
    {
        return 0;
    }
    if (k == 1)
    {
        return 1;
    }
    int lnum = TreeKLevel(root->left, k - 1);
    int rnum = TreeKLevel(root->right, k - 1);
    return lnum + rnum;
}

// 查找值為x的節點
BTNode *BinaryTreeFind(BTNode *root, BTDataType x)
{
    // 函數遞歸返回不會直接返回至最外層！！
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == x)
    {
        return root;
    }
    BTNode *lret = BinaryTreeFind(root->left, x);
    if (lret)
    {
        return lret;
    }
    BTNode *rret = BinaryTreeFind(root->right, x);
    if (rret)
    {
        return rret;
    }
    return NULL;
}

// 判斷一棵樹是否為完全二元樹
bool BinaryTreeComplete(BTNode *root)
{
    Queue q;
    QueueInit(&q);
    if (root != NULL)
    {
        QueuePush(&q, root);
    }
    while (!QueueEmpty(&q))
    {
        BTNode *front = QueueFront(&q);
        QueuePop(&q);
        if (front == NULL)
        {
            break;
        }
        else{
            QueuePush(&q, front->left);
            QueuePush(&q, front->right);
        }
    }
    // 判斷是不是完全二元樹
    // 後面有非空，說明空節點不是連續的
    while (!QueueEmpty(&q))
    {
        BTNode *front = QueueFront(&q);
        QueuePop(&q);
        if(front){
            QueueDestroy(&q);
            return false;
        }
    }
    QueueDestroy(&q);
    printf("\n");
    return true;
}

void TreeDestroy(BTNode *root){
    if(root == NULL){
        return;
    }
    TreeDestroy(root->left);
    TreeDestroy(root->right);
    free(root);
}
int main()
{

    BTNode *root = CreatTree();
    // PreOrder(root);
    // InOrder(root);
    // PostOrder(root);
    printf("%d ", TreeSize(root));
    printf("%d ", TreeSize(root));
    // printf("%d ", size);
    // size = 0; // 初始化
    // int ret = TreeHeight(root);
    // printf("%d ", ret);
    // int ret = TreeKLevel(root, 3);
    // printf("%d ", ret);

    // BTNode *ret = BinaryTreeFind(root, 2);
    // printf("%p\n", ret);
    // LevelOrder(root);

    // printf("Tree Complete:%d",BinaryTreeComplete(root));

    TreeDestroy(root);
    root = NULL;
    return 0;
}