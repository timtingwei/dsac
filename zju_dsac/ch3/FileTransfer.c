/* Copyright [2019] <mituh> */
/* FileTransfer.c           */
/* 并查集应用 */

/*
input:
5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
S

output:
no
no
yes
There are 2 components
*/

/* 集合结构数组的表示法
typedef struct {
  ElementType Data;
  int Parent;
} SetType;
*/

#include <stdio.h>
#define MAXSIZE 10
typedef int ElementType;
typedef int SetName;     /* 根结点的下标作为集合名称 */
typedef ElementType SetType[MAXSIZE];


SetName Find(SetType S, ElementType X) {
  for ( ; S[X] >= 0; X = S[X]) {}
  return X;   /* 该结点为根结点时 循环结束 */
}

void Union(SetType S, SetName Root1, SetName Root2) {
  /* 合并两个集合, 假设Roo1 != Root2 */
  /* 按秩合并: 根据结点规模 */
  if (S[Root1] < S[Root2]) {
    S[Root2] = Root1;    /* Root2的父结点为Root1 */
    S[Root1] += S[Root2];
  } else {
    S[Root1] = Root2;
    S[Root2] += S[Root1];
  }
}

void Initialization(SetType S, int n) {
  /* 将数组初始化为n个集合 */
  int i;
  for (i = 0; i < n; i++) S[i] = -1;
}

void Input_connection(SetType S) {
  /* 链接两个结点 */
  ElementType u, v;
  SetName Root1, Root2;
  scanf("%d %d\n", &u, &v);
  Root1 = Find(S, u-1);
  Root2 = Find(S, v-1);
  if (Root1 != Root2) {
    /* printf("Root1 = %d, Root2 = %d\n", Root1, Root2); */
    Union(S, Root1, Root2);
  }
}

void Check_connection(SetType S) {
  /* 检查两个结点是否链接 */
  ElementType u, v;
  SetName Root1, Root2;
  scanf("%d %d\n", &u, &v);
  Root1 = Find(S, u-1);
  Root2 = Find(S, v-1);
  if (Root1 != Root2) {
    printf("no\n");
  } else {
    printf("yes\n");
  }
}

void Check_network(SetType S, int n) {
  /* 检查网络中总共的集合个数 */
  int i, cnt;
  cnt = 0;
  for (i = 0; i < n; i++) {
    if (S[i] < 0) cnt++;
  }
  if (cnt == 1) {
    printf("The network is connected.\n");
  } else {
    printf("There are %d components.\n", cnt);
  }
}

int main() {
  /* File Transfer主框架 */
  SetType S;
  int n; char in;
  scanf("%d\n", &n);
  Initialization(S, n);
  do {
    scanf("%c", &in);
    switch (in) {
      case 'I': Input_connection(S); break;
      case 'C': Check_connection(S); break;
      case 'S': Check_network(S, n); break;
    }
  } while (in != 'S');

  return 0;
}

