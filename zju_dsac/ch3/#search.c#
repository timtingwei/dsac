// Copyright [2018] <mituh>
// search.cpp
// 静态查找




#define MAXSIZE 10
typedef int ElementType;

typedef struct LNode *List;
struct LNode {
  ElementType Element[MAXSIZE];
  int Length;
};

/* 设置哨兵的方法查找k, 线性查找 */
// T(n): O(n)
int SequentialSearch(List Tbl, ElementType K) {
  /* 在Element[1] ~ Element[n]中查找K */
  int i;
  Tbl->Element[0] = K;    /* 建立哨兵 */
  for (i = Tbl->Length; Tbl->Element[i] != K; i--) {}
  return i;                /* 查找成功返回所在单元下标, 不成功返回0 */
}


/* 二分查找 */
/* T(n): O(logN) */
int BinarySearch(List Tbl, ElementType K) {
  int left, mid, right, NotFound = -1;

  left = 1;
  right = Tbl->Length;
  while (left <= right) {
    mid = (left + right) / 2;
    if (Tbl->Element[mid] < K) { left = mid + 1;
    } else if (Tbl->Element[mid] > K) { right = mid - 1;
    } else { return mid;     /* 中间下标所指元素与K相等 */ }
  }
  return NotFound;    /* 左右边界错位, 查找不成功返回-1*/
}
