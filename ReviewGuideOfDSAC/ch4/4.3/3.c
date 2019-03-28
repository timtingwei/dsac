/* Copyright [2019] <mituh> */
/* 4.3/3.c */
/* 后序遍历二叉树的非递归版本 */

/* 需要记忆理解的标准版本 */
void PostOrder(BinTree T) {
  /* 用栈实现 */
  Stack S;
  BinTree p, r;
  InitStack(S);
  p = T; r = NULL;

  while (p || !IsEmpty(S)) {
    if (p) {
      push(S, p);
      p = p->lchild;
    } else {
      GetTop(S, p);
      if (p->rchild != NULL && p->rchild != r) {
        /* 右子树存在且未被访问过 */
        p = p->rchild;
        push(S, p);
        p = p->lchild;      /* 交给第一个if向左走 */
      } else {
        pop(S, p);
        Visit(p->data);
        r = p; p = NULL;    /* p置为空后, 不向左走, 进入第一个else向右或pop */
      }  // else
    }  // else
  }  // while
}

/* 我的标准版本  */
void PostOrder_nonrecuir(BinTree T) {
  /* 二叉树初始每个结点的访问属性设置成0 */
  /* Stack<TreeNode> S; 栈没有属性的? */
  Stack S;
  TreeNode pNode;
  if (T != NULL) {
    S.push(T);
    while (!S.empty()) {
      pNode = S.top();
      if (pNode->Left != NULL && !pNode->Left->v) {
        /* 存在未访问过的左孩子 */
        S.push(pNode->Left);
      } else if (pNode->Right != NULL && !pNode->Right->v) {
        /* 存在未访问过的右孩子 */
        S.push(pNode->Right);
      } else {
        Visit(pNode);
        pNode->v = 1;    /* 该结点此时被访问 */
        S.pop();         /* 弹出该结点(栈顶元素) */
      }
    }
  }
}
