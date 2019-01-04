/* Copyright [2019] <mituh> */
/* FileTransfer.c           */
/* 并查集应用 */


/* 集合结构数组的表示法 */
typedef struct {
  ElementType Data;
  int Parent;
} SetType;

int Find(SetType S[], ElementType X) {
  int i;
  for (i = 0; i < MaxSize && S[i].Data; i++) {}
  if (i >= MaxSize) return -1;    /* 没找到该元素 */
  for ( ; S[i].Parent >= 0; i = S[i].Parent) {}
  return i;
}
