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


/* 堆栈实现前序遍历非递归 */
void InOrderTraversal(BinTree BT) {
  BinTree T = BT;
  Stack S = CreateStack(MAXSIZE);
  while (T || !IsEmpty(S)) {
    while (T) {        /* 一直向左并将结点压入堆栈*/
      Push(S, T);
      printf("%5d", T->Data); /* 打印结点 */
      T = T->Left;
    }
    if (!IsEmpty(S)) {
      T = Pop(S);      /* 结点弹出堆栈 */
      T = T->Right;    /* 转向右子树 */
    }
  }
}


/* 队列实现层序遍历 */
void LevelOrderTraversal(BinTree BT) {
  Queue Q; BinTree T;
  if (!BT) return;    /* 空树则直接返回 */
  Q = CreateQueue(MAXSIZE);
  AddQ(Q, BT);
  while (!IsEmpty(Q)) {
    T = DeleteQ(Q);
    printf("%d", T->Data);
    if (T->Left) AddQ(Q, T->Left);
    if (T->Right) AddQ(Q, T->Right);
  }
}


/* 二叉树遍历应用: 输出所有的叶结点 */
void PreOrderPrintLeaves(BinTree BT) {
  if (BT) {
    if (!BT->Left && !BT->Right) {
      printf("%d", BT->Data);
    }
    PreOrderPrintLeaves(BT->Left);
    PreOrderPrintLeaves(BT->Right);
  }
}

/* 求二叉树的高度 */
int PostOrderGetHeight(BinTree BT) {
  int HL, HR, MaxH;
  if (BT) {
    HL = PostOrderGetHeight(BT->Left);
    HR = PostOrderGetHeight(BT->Right);
    MaxH = (HL > HR) ? HL : HR;
    return (MaxH + 1);   /* 带入根结点高度得到树高 */
  } else {
    return 0;    /* 空树树高为0 */
  }
}
