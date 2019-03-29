/* Copyright [2019] <mituh> */
/* 4.4/5.c */
/* 孩子兄弟表示法存储的森林的叶子结点数 */

/* 孩子-兄弟表示法的树的存储 */
typedef struct CSNode {
  ElemenetType data;
  struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;

/* 由树构成的森林的存储 */
typedef struct FNode {
  CSNode Trees[MaxSize];
  int n;
} FNode, *Forest;

/* 计算一棵树上的叶子的数量 */
/*
int GetTreeLeaves(CSTree T) {
  if (T == NULL) return 0;    // 空树
  if (T->firstchild == NULL && T->nextsibling == NULL) {
    return 1;
  }
  // 递归: 一棵树总的叶结点, 左子树 + 右子树叶结点
  return GetTreeLeaves(T->firstchild) + GetTreeLeaves(T->nextsibling);
}
*/

/* 孩子-兄弟存储, 没有左孩子, 就没有叶结点 */
int GetTreeLeaves(CSTree T) {
  if (T == NULL) return 0;   /* 空树 */
  if (T->firstchild == NULL) {   /* 第一个孩子是叶节点 */
    return 1 + GetTreeLeaves(T->nextsibling);
  } else {
    return GetTreeLeaves(firstchild) + GetTreeLeaves(nextsibling);
  }
}

int CountForestLeaves(Forest F) {
  /* 计算森林中的叶子个数 */
  int cnt, i;
  cnt = 0;
  for (i = 0; i < F->n; i++) {
    cnt += GetTreeLeaves(F->Trees[i]);
  }
  return cnt;
}

// Update:
