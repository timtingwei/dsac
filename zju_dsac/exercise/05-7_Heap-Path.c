/* Copyright [2019] <mituh> */
/* 05-7_Heap-Path.c */
/* 是建立最小堆的基本操作训练 */


/*
输入样例:
5 3
46 23 26 24 10
5 4 3

输出样例:
24 23 10
46 23 10
26 10
*/

#include <stdlib.h>
#include <stdio.h>

#define MIN -10001
#define MaxSize 1000
typedef int ElementType;
typedef struct HeapNode *MinHeap;
struct HeapNode {
  int Size;
  int Capacity;
  ElementType Data[MaxSize];
};

/* 建立一个容量为MaxSize的空最小堆 */
MinHeap BuildHeap() {
  MinHeap H;
  H = (MinHeap)malloc(sizeof(struct HeapNode));
  H->Size = 0;
  H->Data[H->Size] = MIN;  /* 设置最小哨兵 */
  H->Capacity = MaxSize;
  return H;
}

/* 将X插入小顶堆H */
void Insert(MinHeap H, ElementType X) {
  /* 省略判断空堆的代码 */
  int i;
  ElementType Tmp;
  H->Data[++H->Size] = X;

  for (i = H->Size; H->Data[i] < H->Data[i/2]; i/=2) {
    Tmp = H->Data[i/2];
    H->Data[i/2] = H->Data[i];
    H->Data[i] = Tmp;
  }
}

/* 打印下标p到根结点路径 */
void PrintPath(MinHeap H, int p) {
  int flag;
  flag = 0;
  while (p > 0) {
    if (!flag) {
      flag = 1;
    } else {
      printf(" ");
    }
    printf("%d", H->Data[p]);
    p /= 2;
  }
  printf("\n");
}

int main() {
  int N, M, i, p; 
  ElementType v;
  MinHeap H;
  scanf("%d %d", &N, &M);
  H = BuildHeap();
  for (i = 0; i < N; i++) {
    scanf("%d", &v);
    Insert(H, v);
  }
  for (i = 0; i < M; i++) {
    scanf("%d", &p);
    PrintPath(H, p);
  }
  return 0;
}

// Update
// Update
// Update
// Update
// Update
