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

/* 定义成全局, 不用重新定义一个堆了 */
#define MAXD -1001    /* 哨兵 */
#define MAXN 1000     /* 堆的最大容量 */

int H[MAXN], size;    /* 堆的数组和容量定义成全局! */

void Create() {
  size = 0;
  H[0] = MAXD;
}

void Insert(int X) {
  /* 将X插入到堆中, 要实时保持最小堆! */
  int i;
  for (i = ++size; H[i/2] > X; i /= 2) {
    H[i] = H[i/2];
  }
  H[i] = X;
}

int main() {
  int n, m, i, x, p;
  scanf("%d %d", &n, &m);   /* scanf不需要换行 */
  Create();    /* 创建并读入未排序的堆 */
  for (i = 0; i < n; i++) {
    scanf("%d", &x);
    Insert(x);
  }
  // BuildHeap(H);         /* 将堆建立成小顶堆 */   用的是创建空堆插入的方法!

  for (i = 0; i < m; i++) {
    scanf("%d", &p);    /* 读入结点下标 */
    printf("%d", H[p]);
    while (p > 1) {
      p /= 2;
      printf(" %d", H[p]);
    }
    printf("\n");
  }
  
  return 0;
}
