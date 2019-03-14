/* Copyright [2019] <mituh> */
/* 4.2/5.c */
/* 在顺序存储的二叉树中, 查找结点i和结点j的最近公共祖先 */

/* T(n) = O(log2n), S(n) = O(1)*/
#define ERROR -1
ElementType Comm_Ancester(SqTree T, int i, int j) {
  /* 在二叉树中查找结点i和结点j的最近公共祖先 */
  if (T[i] != '#' && T[j] != '#') {   /* 结点存在 */
    while (i != j) {
      if (i > j) {
        i = i/2;
      } else {
        j = j/2;
      }
    }
    return T[i];
  } else {
    return ERROR;
  }
}
