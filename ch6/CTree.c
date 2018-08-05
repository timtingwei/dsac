// Copyright [2018] <mituh>
// CTree.c
// 树的孩子表示法(线性表+ 单链表)

typedef int TElemType;

#define MAX_TREE_SIZE 100
typedef struct CTNode {  /* 孩子结点 */
  int child;
  struct CTNode *next;
} *ChildPtr;

typedef struct {  /* 表头结构 */
  TElemType data;
  ChildPtr firstchild;
} CTBox;

typedef struct {
  CTBox nodes[MAX_TREE_SIZE];  /* 结点数组 */
  int r, n;                    /* 根的位置和结点数 */
} CTree;



