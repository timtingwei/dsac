/* Copyright [2019] <mituh> */
/* 4.5/7.c */
/* 求出指定结点在给点二叉排序树中的层次, 若不存在该结点, 返回NotFound */

#define NotFound 0
int GetLevel(BiTree T, BSTNode node) {
  if (T == NULL) return NotFound;    /* 空树为0层 */
  int level, find;
  BinTree p;
  level = 0; find = 0; p = T;    /* 层数, 找到标记, 工作结点 */
  while (p != NULL) {   /* 当前结点存在 */
    level++;
    if (node.data < p.data) {
      p = p->lchild;
    } else if (node.data > p.data) {
      p = p->rchild;
    } else {
      find = 1;    /* 修改成已找到 */
      break;       /* 退出循环 */
    }
  }
  return (find) ? level : NotFound;     /* 找到返回层数, 没找到返回0 */
}
