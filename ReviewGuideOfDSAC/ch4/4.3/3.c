/* Copyright [2019] <mituh> */
/* 4.3/3.c */
/* 后序遍历二叉树的非递归版本 */

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
