/* Copyright [2019] <mituh> */
/* 06_2_Saving-James-Bond.c */
/* 优先深度遍历应用 */

/*
Input:
14 20
25 -15
-25 28
8 49
29 15
-35 -2
5 28
27 -29
-8 -28
-20 -35
-25 -20
-13 29
-30 15
-35 40
12 12
Output:
Yes

Input:
4 13
-12 12
12 12
-12 -12
12 -12
Sample Output 2:
No
*/

#include <stdio.h>
#include <math.h>

#define MaxSize 100
#define Yes 1
#define No 0
typedef struct Node {
  double x, y;
} Vertex;
/* #define Graph Vertex[] */
/* typedef Vertex Graph[]; */
typedef Vertex Graph[MaxSize];
/* 鳄鱼池边缘 */
double Up = 50.0, Down = -50.0, Left = -50.0, Right = 50.0;

Graph G;
int N;                  /* 结点个数 */
double MaxJump;         /* 跳跃最远距离 */
int visited[MaxSize];  /* 是否被踩过 */


void ReadGraph(Graph G) {
  int i;
  scanf("%d %lf", &N, &MaxJump);
  for (i = 0; i < N; i++) {
    scanf("%lf %lf", &G[i].x, &G[i].y);
  }
}

void ResetVisited() {
  int i;
  for (i = 0; i < N; i++) visited[i] = 0;
}

int Jump(Vertex W, Vertex V) {
  int ok; double dist;
  dist = sqrt(pow((V.x-W.x), 2) + pow((V.y - W.y), 2));
  ok = (dist <= MaxJump) ? Yes : No;
  return ok;
}

int FirstJump(Vertex V) {
  Vertex Center;
  Center.x = 0.0; Center.y = 0.0;
  return Jump(V, Center);
}

int IsSafe(Vertex W) {
  if ((Up - W.y <= MaxJump) ||
      (W.y - Down <= MaxJump) ||
      (W.x - Left <= MaxJump) ||
      (Right - W.x <= MaxJump)) {
    return Yes;
  } else {
    return No;
  }
}

int DFS(Vertex V, int vi) {
  int i, answer, neari, cnt;
  int nearVi[MaxSize];
  cnt = 0;
  visited[vi] = 1;
  if (IsSafe(G[vi])) {
    answer = Yes;
  } else {
    for (i = 0; i < N; i++) {
      if (vi != i && Jump(G[i], G[vi])) {
        nearVi[cnt++] = i;
      }
    }  /* 找出邻接结点序号 */

    for (i = 0; i < cnt; i++) {
      neari = nearVi[i];
      if (!visited[neari]) {
        answer = DFS(G[neari], neari);
        if (answer == Yes) break;
      }
    }
  }
  return answer;
}

void save007(Graph G) {
  Vertex V; int i;
  int answer;
  for (i = 0; i < N; i++) {
    V = G[i];
    if (!visited[i] && FirstJump(V)) {
      answer = DFS(V, i);
      if (answer == Yes) break;
    }
  }
  if (answer == Yes) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}

int main() {
  ReadGraph(G);      /* 读入图 */
  ResetVisited();    /* 访问清空 */
  save007(G);
  return 0;
}
