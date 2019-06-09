/* Copyright [2019] <mituh> */
/* 5.3/2.c */
/* 判断无向图是否为一棵树 */


/*
方法一: 判断是否有回路
int ans;
int visited[MaxSize];

void dfs(MGraph G, int v) {
  visited[v] = 1;
  for (w = FirstAdjV(G, v); w >= 0; w = NextAdjV(G, v, w)) {
    if (!visited[w]) {
      dfs(G, w);
    } else {     // 访问到已经访问的结点
      ans = 0;
    }
  }
}

int Judge(MGraph G) {
  if (G->vexnum == 0) return 0;     // 图不存在结点是不行的
  // 假设结点下标从0开始到n-1
  int i;
  ans = 1;     // 初始对树的判断为true
  for (i = 0; i < G->vexnum; i++) {
    visited[i] = 0;
  }
  dfs(G, i);    // 若dfs中访问已经访问过的结点, 不是树, ans 0
  for (i = 0; i < G->vexnum; i++) {
    if (!visited[i]) ans = 0;
  }
  return ans;
}

*/


/* 方法二: 根据遍历顶点数是否为图的顶点数,
   且遍历的边是图的顶点数-1(树的边和顶点关系性质)*/
#define TRUE  1
#define FALSE 0

void dfs(LGraph G, int v, int& VNum, int& ENum, int visited[]) {
  int w;
  VNum++; visited[v] = TRUE;
  w = FirstNeighhor(G, v);
  while (w != -1) {
    ENum++;           /* 双向 */
    if (!visited[w]) {
      dfs(G, w, VNum, ENum, visited);
    }
    w = NextNeighbor(G, v, w);
  }
}

int IsTree(LGraph G) {
  int visited[MaxSize];
  int i, VNum, ENum;
  for (i = 1; i <= G->vexnum; i++) {    /* 图的顶点数从1到n */
    visited[i] = FALSE;
  }
  Vnum = 0; ENum = 0;
  dfs(G, 1, VNum, ENum, visited);
  if (VNum == G->vexnum && ENum == 2*(G->vexnum-1)) {
    return TRUE;
  } else {
    return FALSE;
  }
}


// Update
// Update
// Update
// Update
// Update
// Update
