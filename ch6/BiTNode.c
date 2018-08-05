// Copyright [2018] <mituh>
// BiTNode.c
// 二叉链表表示法(一数据, 两指针)

typedef int TElemType;

/* 二叉树的二叉链表结点结构定义 */
typedef struct BiTNode {
  TElemType data;
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
