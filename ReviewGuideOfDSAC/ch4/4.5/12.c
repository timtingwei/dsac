/* Copyright [2019] <mituh> */
/* 4.5/12.c */
/* 给定一个二叉排序树,
   求第k小的结点(二叉树的存储结构中, 带有count成员属性, 带该结点为根的子树包含的所有结点个数) */

/* 先分左子树 空和非空 两种大情况 讨论*/
BSTNode* Search_SmallestK(BSTNode* bt, int k) {
  if (k < 1 || k > bt->count) return NULL;   /* 别忘了k值不符合的情况! */
  if (bt->lchild == NULL) {        /* 左子树为空 */
    if (k == 1) {
      return bt;
    } else {                       /* 在右子树寻找 */
      return Search_SmallestK(bt->rchild, k-1);
    }
  } else {                         /* 左子树非空 */
    if (bt->lchild == k-1) {       /* 根结点就是k小 */
      return bt;
    } else if (bt->lchild > k-1) { /* 在左子树中 */
      return Search_Smallest(bt->lchild, k);
    } else if (bt->lchild < k-1) { /* 在右子树中 */
      return Search_Smallest(bt->rchild, k-(bt->lchild+1));
    }
  }
}
