#include "../include/bin_tree.h"
#include "../include/queue.h"

// 创建节点
BTNode *BuyNode(BIN_Datatype x) {
  BTNode *newnode = (BTNode *)malloc(sizeof(BTNode));
  if (newnode == NULL) {
    perror("malloc fail:");
    return NULL;
  }
  newnode->_data = x;
  newnode->_left = NULL;
  newnode->_right = NULL;
  return newnode;
}
BTNode *CreateTree() {
  BTNode *n1 = BuyNode(1);
  BTNode *n2 = BuyNode(5);
  BTNode *n3 = BuyNode(2);
  BTNode *n4 = BuyNode(9);
  BTNode *n5 = BuyNode(4);
  BTNode *n6 = BuyNode(7);
  BTNode *n7 = BuyNode(10);
  n1->_left = n2;
  n1->_right = n4;
  n2->_left = n3;
  n4->_left = n5;
  n4->_right = n6;
  n5->_left = n7;
  return n1;
}
// ⼆叉树结点个数
int BinaryTreeSize(BTNode *root) {
  if (root == NULL) {
    return 0;
  }
  int _left = BinaryTreeSize(root->_left);
  int _right = BinaryTreeSize(root->_right);
  return _left + _right + 1; // 1 是根节点
}
// ⼆叉树叶⼦结点个数
int BinaryTreeLeafSize(BTNode *root) {
  if (root == NULL) {
    return 0;
  }
  if (root->_left == NULL && root->_right == NULL) {
    return 1;
  }
  int _left = BinaryTreeLeafSize(root->_left);
  int _right = BinaryTreeLeafSize(root->_right);
  return _left + _right;
}
// ⼆叉树第k层结点个数
int BinaryTreeLevelKSize(BTNode *root, int k) {
  if (k == 1 && root != NULL) {
    return 1;
  }
  if (root == NULL) {
    return 0;
  }
  int _left = BinaryTreeLevelKSize(root->_left, k - 1);
  int _right = BinaryTreeLevelKSize(root->_right, k - 1);
  return _left + _right;
}
// ⼆叉树的深度/⾼度
int BinaryTreeDepth(BTNode *root) {
  if (root == NULL) {
    return 0;
  }
  if (root->_left == NULL && root->_right == NULL) {
    return 1;
  }
  int _left = BinaryTreeDepth(root->_left);
  int _right = BinaryTreeDepth(root->_right);
  return _left > _right ? _left + 1 : _right + 1;
}
// ⼆叉树查找值为x的结点
BTNode *BinaryTreeFind(BTNode *root, BIN_Datatype x) {
  if (root == NULL) {
    return NULL;
  }
  if (root->_data == x) {
    return root;
  }
  BTNode *left_ret = BinaryTreeFind(root->_left, x);
  BTNode *right_ret = BinaryTreeFind(root->_right, x);
  return left_ret != NULL ? left_ret : right_ret;
}
// ⼆叉树销毁
void BinaryTreeDestory(BTNode **root) {
  if (root == NULL || *root == NULL) {
    return;
  }
  BinaryTreeDestory(&(*root)->_left);
  BinaryTreeDestory(&(*root)->_right);
  free(*root);
  *root = NULL;
}
void PreOrder(BTNode *root) {
  if (root == NULL) {
    printf("N ");
    return;
  }
  printf("%d ", root->_data);
  PreOrder(root->_left);
  PreOrder(root->_right);
}
void InOrder(BTNode *root) {
  if (root == NULL) {
    printf("N ");
    return;
  }
  InOrder(root->_left);
  printf("%d ", root->_data);
  InOrder(root->_right);
}
void PostOrder(BTNode *root) {
  if (root == NULL) {
    printf("N ");
    return;
  }
  InOrder(root->_left);
  InOrder(root->_right);
  printf("%d ", root->_data);
}
// 层序遍历
void LevelOrder(BTNode *root) {
  Queue q;
  QueueInit(&q);
  QueuePush(&q, root);
  while (!QueueEmpty(&q)) {
    BTNode *top = QueueFront(&q);
    printf("%d ", top->_data);
    QueuePop(&q);
    if (top->_left) {
      QueuePush(&q, top->_left);
    }
    if (top->_right) {
      QueuePush(&q, top->_right);
    }
  }
  QueueDestroy(&q);
}
// 判断⼆叉树是否是完全⼆叉树
bool BinaryTreeComplete(BTNode *root) {
  Queue q;
  QueueInit(&q);
  QueuePush(&q, root);
  while (!QueueEmpty(&q)) {
    BTNode *top = QueueFront(&q);
    QueuePop(&q);
    if (top == NULL) {
      break;
    }
    QueuePush(&q, top->_left);
    QueuePush(&q, top->_right);
  }
  while (!QueueEmpty(&q)) {
    BTNode *top = QueueFront(&q);
    QueuePop(&q);
    // 如果是完全二叉树，队列中剩余的元素应该全为 NULL
    if (top != NULL) {
      QueueDestroy(&q);
      return false;
    }
  }
  QueueDestroy(&q);
  return true;
}