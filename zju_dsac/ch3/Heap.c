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


void Insert(MaxHeap H, ELementType item) {
  /* 最大堆的插入 */
  int i;
  if (IsFull(H)) {
    print("堆满\n");
    return;
  }
  i = ++H->Size;    /* item初始作为最后一个元素插入 */
  for ( ; H->Data[i/2] < item; i /= 2) {   /* 与父节点比较并向上 */
    H->Data[i] = H->Data[i/2];             /* 与父节点交换位置 */
  }
  H->Data[i] = item;                       /* 将item插入 */
}
