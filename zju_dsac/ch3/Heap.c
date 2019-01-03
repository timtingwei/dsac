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
  H->Data = malloc((MaxSize) * sizeof (struct HNode));
  H->Size = 0;
  H->Capacity = MaxSize;
  H->Elements[0] = MAXDATA;
  return H;
}
