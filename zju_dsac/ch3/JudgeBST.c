// Copyright [2019] <mituh>
// JudgeBST.c
// 判断两个搜索树是否一致

/* 方法一: 建两棵搜索树遍历判断 */
/* 方法二: 不建树, 根据先插入的为根结点的特性, 递归判断 */
/* 方法三: 建一棵树和另外一个序列判断 */

#define ElementType int
typedef struct TreeNode *Position;
typedef Position Tree;

struct TreeNode {
  int v;
  Tree Left, Right;
  int flag;     /* 被访问的标记 */
};
