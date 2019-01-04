// Copyright [2019] <mituh>
// BuildHeap.c
// 堆的建立

#include <stdlib.h>
typedef int ElementType;
typedef struct HeapNode *Heap;
struct HeapNode {
  ElementType *Elements;   /* 存储元素的数组 */
  int Size;            /* 堆中当前元素的个数 */
  int Capacity;        /* 堆的最大容量 */
};

typedef Heap MaxHeap;
typedef Heap MinHeap;


void PrecDown(MaxHeap H, int p) {
  /* 下滤: 将H中以p为根结点的堆调整为最大堆 */
  int Parent, Child;
  ElementType X;

  X = H->Elements[p];
  for (Parent = 1; Parent * 2 <= H->Size; Parent = Child) {
    Child = Parent * 2;
    if ((Child != H->Size) &&
        (H->Elements[Child] < H->Elements[Child+1])) {
      Child++;
    }
    if (X >= H->Elements[Child]) {
      break;
    } else {
      H->Elements[Parent] = H->Elements[Child];
    }
  }
  H->Elements[Parent] = X;
}

void BuildHeap(MaxHeap H) {
  /* 建立最大堆 */
  int i;
  /* 从最后一个结点的父节点开始, 到根结点1 */
  for (i = H->Size/2; i > 0; i--) {
    PrecDown(H, i);
  }
}
