// Copyright [2018] <mituh>
// BinTreeTraversal.cpp
// 非递归遍历

/* 存储结构 */
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
  ElementType Data;
  BinTree Left;
  BinTree Right;
};


#define MAXSIZE 10
/* 堆栈实现中序遍历非递归 */
void InOrderTraversal(BinTree BT) {
  BinTree T = BT;
  Stack S = CreateStack(MAXSIZE);
  while (T || !IsEmpty(S)) {
    while (T) {        /* 一直向左并将结点压入堆栈*/
      Push(S, T);
      T = T->Left;
    }
    if (!IsEmpty(S)) {
      T = Pop(S);      /* 结点弹出堆栈 */
      printf("%5d", T->Data); /* 打印结点 */
      T = T->Right;    /* 转向右子树 */
    }
  }
}
