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


typedef int ElementType;
typedef int SetName;     /* 根结点的下标作为集合名称 */
typedef ElementType SetType[MAXSIZE];


SetName Find(SetType S, ElementType X) {
  for ( ; S[X] >= 0; X = S[X]) {}
  return X;
}

void Union(SetType S, SetName Root1, SetName Root2) {
  if (Root1 != Root2) {
    S[Root2] = Root1;    /* Root2的父结点为Root1 */
  }
}

// Update
