// Copyright [2019] <mituh>
// SetFind.c
// 集合的存储: 孩子双亲表示法, 并查集

typedef struct {
  ElementType Data;
  int Parent;
} SetType;

#define MaxSize 20
int Find(SetType S[ ], ElementType X) {
  /* 在集合S中查找元素X的根(所属的集合) */
  /* MaxSize全局, 是数组S的最大长度 */
  int i;
  for (i = 0; i < MaxSize && S[i].Data != X; i++) {}  /* !访问Data成员后比较 */
      /* 在S中先找到X所对应的元素下标 */
  if (i >= MaxSize) return -1;    /* 没找到元素X */
  for ( ; S[i].Parent >= 0; i = S[i].Parent) {}
  return i;  /* 找到X所属集合, 返回树根结点的下标 */
}

void Union(SetType S[ ], ElementType X1, ElementType X2) {
  /* 两个结点的集合并 */
  int Root1, Root2;
  Root1 = Find(S, X1);
  Root2 = Find(S, X2);
  if (Root1 != Root2) {   /* 两个不同的集合 */
    S[Root1].Parent = Root2;
  }
}
