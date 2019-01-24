/* Copyright [2019] <mituh> */
/* 04-6_Complete-Binary-Search-Tree.c */
/* 完全二叉树的插入和树的层序遍历 */

/*
Sample Input:
10
1 2 3 4 5 6 7 8 9 0

Sample Output:
6 3 8 1 5 7 9 0 2 4
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MaxSize 2000
int A[MaxSize], T[MaxSize];

int GetLeftTreeLength(int n) {
  int H, X, L;
  H = (int)log2(n+1);
  X = n-pow(2, H)+1;
  X = (X < pow(2, H-1)) ? X : pow(2, H-1);
  L = pow(2, H-1)+1-X;
  return L;
}

void solve(int ALeft, int ARight, int TRoot) {
  /* 初始调用为 solve(0, N-1, 0);*/
  int n, L, LeftRoot, RightRoot;
  n = ARight - ALeft + 1;
  if (n == 0) return;
  L = GetLeftTreeLength(n);
  T[TRoot] = A[ALeft + L];
  LeftRoot = TRoot*2+1;
  RightRoot = LeftRoot+1;
  solve(ALeft, ALeft+L-1, LeftRoot);
  solve(ALeft+L+1, ARight, RightRoot);
}

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int main() {
  int N, i, flag;
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  qsort(A, N, sizeof(int), compare);
  solve(0, N-1, 0);   /* 以根结点开始赋值 */
  flag = 0;
  for (i = 0; i < N; i++) {
    if (!flag) {
      flag = 1;
    } else {
      printf(" ");
    }
    printf("%d", T[i]);
  }
  return 0;
}


