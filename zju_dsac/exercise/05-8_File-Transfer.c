/* Copyright [2019] <mituh> */
/* 05-8_File-Transfer.c */
/* 关于并查集, 以及相关优化 */
/*
Sample Input 1:
5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
S

Sample Output 1:
no
no
yes
There are 2 components.

Sample Input 2:
5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
I 1 3
C 1 5
S

Sample Output 2:
no
no
yes
yes
The network is connected.
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10010
int cset[MaxSize];

void BuildSet(int N) {
  int i;
  for (i = 1; i <= N; i++) cset[i] = -1;
}

int FindRoot(int c) {
  while (cset[c] != -1) {
    c = cset[c];
  }
  return c;
}

void connect(int c1, int c2) {
  int R1, R2;
  R1 = FindRoot(c1);
  R2 = FindRoot(c2);
  /* 将R1挂在R2上的做法 */
  cset[R1] = R2;
  /* 加权比较树高 */
  /* 加权路径压缩 */
}

void check(int c1, int c2) {
  int R1, R2;
  R1 = FindRoot(c1);
  R2 = FindRoot(c2);
  if (R1 == R2) {
    printf("yes\n");
  } else {
    printf("no\n");
  }
}

void PrintComponents(int N) {
  int i, cnt;
  cnt = 0;
  for (i = 1; i <= N; i++) {
    if (cset[i] == -1) cnt++;
  }
  if (cnt == 1) {
    printf("The network is connected.\n");
  } else {
    printf("There are %d components.\n", cnt);
  }
}

int main() {
  int N, c1, c2, ok;
  char cmd;
  scanf("%d", &N);
  ok = 1;
  BuildSet(N);
  for (;;) {
    scanf("%c", &cmd);
    if (cmd == 'S') {
      PrintComponents(N);
      ok = 0;
    } else {
      scanf("%d %d", &c1, &c2);
      if (cmd == 'I') {
        connect(c1, c2);
      } else if (cmd == 'C') {
        check(c1, c2);
      }
    }
    if (!ok) break;
  }
  return 0;
}
