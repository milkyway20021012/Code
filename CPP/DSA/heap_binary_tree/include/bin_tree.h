#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int BIN_Datatype;
typedef struct BTree_Node {
  struct BTree_Node *_left;
  struct BTree_Node *_right;
  BIN_Datatype _data;
} BTNode;
// 创建节点
BTNode *BuyNode(BIN_Datatype x);
BTNode *CreateTree();
// ⼆叉树结点个数
int BinaryTreeSize(BTNode *root);
// ⼆叉树叶⼦结点个数
int BinaryTreeLeafSize(BTNode *root);
// ⼆叉树第k层结点个数
int BinaryTreeLevelKSize(BTNode *root, int k);
// ⼆叉树的深度/⾼度
int BinaryTreeDepth(BTNode *root);
// ⼆叉树查找值为x的结点
BTNode *BinaryTreeFind(BTNode *root, BIN_Datatype x);
// ⼆叉树销毁
void BinaryTreeDestory(BTNode **root);
// 前序遍历(根->左->右)
void PreOrder(BTNode *root);
// 中序遍历(左->根->右)
void InOrder(BTNode *root);
// 后序遍历（左->右->根)
void PostOrder(BTNode *root);
// 层序遍历
void LevelOrder(BTNode *root);
// 判断⼆叉树是否是完全⼆叉树
bool BinaryTreeComplete(BTNode *root);