/* Copyright [2019] <mituh> */
/* ch5/2.c */
/* 判断无向图是否为一棵树 */

int ans;
int visited[MaxSize];

void dfs(MGraph G, int v) {
  visited[v] = 1;
  for (w = FirstAdjV(G, v); w >= 0; w = NextAdjV(G, v, w)) {
    if (!visited[w]) {
      dfs(G, w);
    } else {     /* 访问到已经访问的结点 */
      ans = 0;
    }
  }
}

int Judge(MGraph G) {
  if (G->vexnum == 0) return 0;     /* 图不存在结点是不行的 */
  /* 假设结点下标从0开始到n-1 */
  int i;
  ans = 1;     /* 初始对树的判断为true */
  for (i = 0; i < G->vexnum; i++) {
    visited[i] = 0;
  }
  dfs(G, i);    /* 若dfs中访问已经访问过的结点, 不是树, ans 0 */
  for (i = 0; i < G->vexnum; i++) {
    if (!visited[i]) ans = 0;
  }
  return ans;
}

