/* Copyright [2019] <mituh> */
/* ex-PrintPath.c           */
/* 将一系列给定数字插入一个初始为空的小顶堆H[],
   随后对任意给定的下标i, 打印从H[i]到根结点的路径 */

/*
input:
5 3
46 23 26 24 10
5 4 3

output:
24 23 10
46 23 10
26 10
*/

#include <stdio.h>
#include <stdlib.h>


#define ElementType int
typedef struct HeapNode *Heap;
struct HeapNode {
  ElementType *Elements;
  int Size;
  int Capacity;
};
typedef Heap MinHeap;

void Insert(MinHeap H, ElementType item) {
  /* 将元素插入到堆的最后一个结点 */
  H->Elements[++H->Size] = item;
}

#define MAXD -1001    /* 哨兵 */
#define MAXN 1000     /* 堆的最大容量 */
void CreateHeap(MinHeap H, int MaxSize) {
  /* 创建并读入未排序的堆 */
  ElementType item;
  H->Elements = (ElementType *)malloc(sizeof(ElementType) * (MaxSize + 1));
  H->Elements[0] = MAXD;
  H->Size = 0;
  H->Capacity = MAXN;
  while (MaxSize--) {
    scanf("%d", &item);
    Insert(H, item);
  }
  return H;
}

void PrecUp(MinHeap H, int p) {
  /* 过滤: 将H以p下标结点为根的子树排成最小堆 */
  ElementType X;
  int Parent, Child;
  X = H->Elements[p];

  for (Parent = p; Parent*2 <= H->Size; Parent = Child) {
    Child = Parent * 2;
    if ((Child != H->Size) &&
      (H->Elements[Child] > H->Elements[Child+1]))
      Child++;
    if (X <= H->Elements[Child]) {
      break;
    } else {
      H->Elements[Parent] = H->Elements[Child];
    }
  }
  H->Elements[Parent] = X;
}

void BuildHeap(MinHeap H) {
  /* 根据已经放好的堆, 建立最小堆 */
  int i;
  for (i = H->Size/2; i > 0; i /= 2) {
    PrecUp(H, i);
  }
}

void PrintPath(MinHeap H, int p) {
  /* 打印从下标p的结点到根结点的路径 */
  int i;
  printf("%d ", H->Elements[p]);
  for (i = p/2; i > 0; i /= 2) {
    printf(" %d", H->Elements[i]);
  }
  print("\n");
}

int main() {
  int n, m, p;
  scanf("%d %d\n", &n, &m);
  MinHeap H;
  CreateHeap(H, n);    /* 创建并读入未排序的堆 */
  BuildHeap(H);         /* 将堆建立成小顶堆 */

  while (m--) {
    scanf("%d", &p);    /* 读入结点下标 */
    PrintPath(H, p);    /* 打印从结点到根的路径 */
  }
  return 0;
}
