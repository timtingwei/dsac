// Copyright [2018] <mituh>
// CSNode.c
// 树的孩子兄弟表示法(一结点, 两指针)

typedef int TElemType;

/* 树的孩子兄弟表示法 */
typedef struct CSNode {
  TElemType data;
  struct CSNode *firstchild, *rightsib;
} CSNode, *CSTree;
