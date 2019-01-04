// Copyright [2019] <mituh>
// SetFind.c
// 集合的存储: 孩子双亲表示法, 以及在集合中查找

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
