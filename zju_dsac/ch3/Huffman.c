// Copyright [2019] <mituh>
// Huffman.c
// 哈夫曼树的储存和建立

#include <stdlib.h>
typedef int ElementType;
typedef struct TreeNode HuffmanTree;
struct TreeNode {
  int weight;
  HuffmanTree Left, Right;
};

typedef struct HeapNode *Heap;
struct HeapNode {
  ElementType *Elements;
  int Size;
  int Capacity;
};

typedef Heap MinHeap;
typedef Heap MaxHeap;

ElementType DeleteMin(MinHeap H);   /* 从最小堆中删除 */

void Insert(MinHeap H, HuffmanTree T);   /* 将哈夫曼树的结点插入最小堆 */

/* T(n) = O(nlogn) */
HuffmanTree Huffman(MinHeap H) {
  /* 从最小堆将树哈夫曼化 */
  int i; HuffmanTree T;
  BuildHeap(H);    /* 根据权重将堆调整成最小堆 */

  for (i = 1; i < H->Size; i++) {
    T = malloc(sizeof(struct TreeNode));
    T->Left = DeleteMin(H);
    T->Right = DeleteMin(H);
    T->weight = T->Left->weight + T->Right->weight;
    Insert(H, T);
  }
  T = DeleteMin(H);   /* 最后一个结点? 为什么不插入?*/
  return T;
}
