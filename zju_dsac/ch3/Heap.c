// Copyright [2019] <mituh>
// Heap.c
// 堆的存储, 创建, 插入, 删除

#include <stdlib.h>
typedef struct HNode *Heap;
struct HNode {
  ElementType *Data;   /* 存储元素的数组 */
  int Size;            /* 堆中当前元素的个数 */
  int Capacity;        /* 堆的最大容量 */
};

typedef Heap MaxHeap;
typedef Heap MinHeap;

#define MAXDATA 1000  /* 该值大于堆中的任意值 */
MaxHeap CreateHeap(int MaxSize) {
  /* 创建一个最大堆 */
  MaxHeap H = malloc(sizeof(struct HNode));
  H->Data = malloc((MaxSize + 1) * sizeof(ElementType));
  H->Size = 0;
  H->Capacity = MaxSize;
  H->Elements[0] = MAXDATA;
  return H;
}


/* T(n) = O(logn) 树的高度 */
void Insert(MaxHeap H, ELementType item) {
  /* 最大堆的插入 */
  int i;
  if (IsFull(H)) {
    print("堆满\n");
    return;
  }
  i = ++H->Size;    /* item初始作为最后一个元素插入 */
  for ( ; H->Data[i/2] < item; i /= 2) {   /* 与父节点比较并向上 */
         /* 用哨兵元素控制越界 */
    H->Data[i] = H->Data[i/2];             /* 与父节点交换位置 */
  }
  H->Data[i] = item;                       /* 将item插入 */
}


ElementType DeleteMax(MaxHeap H) {
  /* 最大堆的删除 */
  int Parent, Child;
  ElementType MaxItem, temp;
  if (IsEmpty(H)) {
    printf("栈空\n"); return;
  }
  MaxItem = H->Data[1];
  temp = H->Data[H->Size--];
  for (Parent = 1; Parent*2 <= H->Size; Parent = Child) {
    Child = Parent * 2;
    if (Child != H->Size &&
        H->Data[Child] < H->Data[Child+1])
      Child++;   /* 找到左右孩子中较大的 */
    if (temp >= H->Data[Child]) {
      break;
    } else {
      H->Data[Parent] = H->Data[Child];
    }
  }
  H->Data[Parent] = temp;
  return MaxItem;
}
