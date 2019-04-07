/* Copyright [2019] <mituh> */
/* ch4/template.c */
/* 二叉树前序, 中序, 后序, 层序遍历非递归 */

void PreOrder2(BiTree bt) {
  Stack S; BiNode *p;
  InitStack(S); p = bt;
  while (p || !IsEmpty(S)) {
    if (p) {
      visit(p->data);      /* 第一次遍历到就访问根 */
      push(S, p);
      p = p->lchild;
    } else {
      pop(S, p);
      p = p->rchild;
    }
  }
}

void InOrder2(BiTree bt) {
  Stack S; BiNode *p;
  InitStack(S); p = bt;
  while (p || !IsEmpty(S)) {
    if (p) {
      push(S, p);
      p = p->lchild;     /* 先访问左子树 */
    } else {
      pop(S, p); visit(p->data);
      p = p->rchild;
    }
  }
}

/* 特征: 前中后序非递归遍历会遍历到所有的NULL! */


void PostOrder2(BiTree bt) {
  /* 非递归后序遍历, 需要一个辅助栈, 一个临时结点记录左右孩子是否被访问过 */
  Stack S;
  BiNode *p = bt, *r = NULL;        /* 工作指针, 记录上一个访问的指针 */
  InitStack(S);
  while (p || !IsEmpty(p)) {
    if (p) {
      push(S, p);
      p = p->lchild;
    } else {
      GetTop(S, p);               /* 获取栈顶结点 */
      if (p->rchild != NULL && p->rchild != r) {
        /* 右孩子存在且没被访问过 */
        p = p->rchild;
        push(S, p);
        p = p->lchild;
      } else {
        pop(S, p); visit(p->data);  /* 栈顶元素出栈并访问 */
        r = p; p = NULL;
      }
    }
  }
}


void LevelOrder(BiTree bt) {
  /* 层序遍历, 需要一个辅助队列 */
  Queue Q; BiNode *p;
  InitQueue(Q); p = bt;
  EnQueue(Q, p);                    /* 根结点先压入队列 */
  while (!IsEmpty(Q)) {
    DeQueue(Q, p);                  /* 出队 */
    visit(p->data);
    if (p->lchild != NULL) {
      EnQueue(Q, p->lchild);
    }
    if (p->rchild != NULL) {
      EnQueue(Q, p->rchild);
    }
  }
}

// Update:
// Update:
// Update:
// Update:
// Update:
// Update:
// Update:
// Update:
