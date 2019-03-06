/* Copyright [2019] <mituh> */
/* Merge_Sort_recursion.c */
/* 归并排序递归版本 */

/* 归并排序需要额外的空间 */

#include <stdlib.h>
#include <stdio.h>
typedef int ElementType;

/* 核心算法 */
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd) {
  int LeftEnd, Tmp, Num, i;
  LeftEnd = R-1;
  Tmp = L;
  Num = RightEnd - L + 1;
  while (L <= LeftEnd && R <= RightEnd) {
    if (A[L] <= A[R]) TmpA[Tmp++] = A[L++];
    else              TmpA[Tmp++] = A[R++];
  }
  while (L <= LeftEnd)  TmpA[Tmp++] = A[L++];
  while (R <= RightEnd) TmpA[Tmp++] = A[R++];
  for (i = 0; i < Num; i++, RightEnd--) {
    A[RightEnd] = TmpA[RightEnd];
  }
}


/* 分治法调用核心算法 */
void MSort(ElementType A[], ElementType TmpA[], int L, int RightEnd) {
  int center;
  if (L < RightEnd) {
    center = (L + RightEnd)/2;
    MSort(A, TmpA, L, center);
    MSort(A, TmpA, center+1, RightEnd);
    Merge(A, TmpA, L, center+1, RightEnd);
  }
}

/* 统一接口 */
void Merge_Sort(ElementType A[], int N) {
  ElementType TmpA;
  TmpA = malloc(sizeof(ElementType) * N);
  if (TmpA != NULL) {
    MSort(A, TmpA, 0, N-1);
    free(TmpA);
  } else {
    printf("Error, 空间不足\n");
  }
}
