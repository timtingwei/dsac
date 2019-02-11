/* Copyright [2019] <mituh> */
/* 05-9_Huffman-Codes.c */
/* 考察对Huffman编码的理解 */

typedef char ElementType;
typedef int elem_weight;
typedef struct HTNode *HuffmanTree;
struct HTNode {
  WeightType Weight;
  HuffmanTree Left;
  HuffmanTree Right;
};

#define MaxSize 100
typedef struct HeapNode *MinHeap;
struct HeapNode {
  WeightType WeightType[MaxSize];
  ElementType Data[MaxSize];
  int Size;
  int Capacity;
};

#define MIN -10000
/* 建立空堆 */
MinHeap CreateHeap() {
  MinHeap H;
  H = (MinHeap)malloc(sizeof(struct HeapNode));
  H->Size = 0;
  H->Capacity = MaxSize;
  H->Weight[0] = MIN;   /* 哨兵 */
  return H;
}

/* 从最小堆中插入 */
void Insert(MinHeap H, ElementType elem, WeightType elem_weight) {
  /* 省略判满 */
  int i;
  WeightType Tmp; ElementType data_Tmp;
  H->Weight[++H->Size] = X;
  H->Data[H->Size] = elem;
  /* 重的下沉 */
  for (i = H->Size; H->Weight[i] < H->Weight[i/2]; i /= 2) {
    Tmp = H->Weight[i/2]; data_Tmp = H->Data[i/2];
    H->Weight[i/2] = H->Weight[i]; H->Data[i/2] = H->Data[i];
    H->Weight[i] = Tmp; H->Data[i] = Tmp_data;
  }
}

/* 将堆按权值调整 */
void BuildHeap(MinHeap H, int N) {
  int i;
  ElementType ch; WeightType v;
  for (i = 0; i < N; i++) {
    scanf("%c %d", &ch, &v);
    Insert(H, ch, v);
  }
}

/* 从最小堆中删除, 返回堆顶并Huffman化 */
HuffmanTree DeleteMin(MinHeap H) {
  /* 省略判空操作 */
  HuffmanTree HT;
  WeightType MinItem, X;
  int Parent, Child;
  MinItem = H->Weight[1];
  X = H->Weight[H->Size--];    /* 缩小堆的规模 */

  for (Parent = 1; Parent*2 <= H->Size; Parent = Child) {
    Child = Parent*2;
    if (Child != H->Size && H->Weight[Child] > H->Weight[Child+1]) {
      Child++;
    }
    if (X <= H->Weight[Child]) {    /* 找到合适的插入位置 */
      break;
    } else {
      H->Weight[Parent] = H->Weight[Child];
    }
  }
  H->Weight[Parent] = X;
  HT = (HuffmanTree)malloc(sizeof(struct HTNode));
  HT->Weight = MinItem;
  HT->Left = HT->Right = NULL;
  return HT;
}


/* 从最小堆建立Huffman树 */
HuffmanTree Huffman(MinHeap H) {
  int i, N;
  HuffmanTree T;

  BuildHeap(H);    /* 将堆按权值调整 */
  N = H->Size;
  for (i = 1; i < N; i++) {
    T = (HuffmanTree)malloc(sizeof(struct HTNode));
    T->Left = DeleteMin(H);
    T->Right = DeleteMin(H);
    T->Weight = T->Left->Weight + T->Right->Weight;
    Insert(H, T);     /* 跟已经写好的Insert不是很符合 */
  }
  return DeleteMin(H);     /* 返回最后剩下的一个结点作为根结点 */
}


int main() {
  int N;
  scanf("%d", &N);
  return 0;
}


// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
