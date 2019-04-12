/* Copyright [2019] <mituh> */
/* ch5/3.c */
/* dfs的非递归算法 */

/* 自己手写的版本: */
/*
void dfs(LGraph G, int v) {
  // dfs只能用于遍历一个连通分量
  int w, i, exist;
  int visited[MaxSize];
  InitStack(S);
  for (i = 0; i < G->vexnum; i++) {
    visited[i] = 0;
  }
  push(S, v);
  while (!IsEmpty(S)) {
    exist = 0;
    GetTop(S, v);
    Visit(v);
    visited[v] = 1;
    
    for (w = G->vertices[v]->first; w >= 0; w = vertices[w]->next) {
      if (!visited[w]) {
        exist = 1;
        push(S, w);
      }
    }
    if (!exist) {    // 若v结点不存在未访问
      pop(S, v);
    }
  }
}
*/

/* 非递归dfs遍历, 标准版本 */
#define MaxSize 100
#define TRUE  1
#define FALSE 0
void dfs_non_rc(LGraph G, int v) {
  int i, w;
  stack S;                // 用一个辅助栈S记录, 下一步可能会访问的结点
  int visited[MaxSize];   // 已经访问结点标记
  InitStack(S);
  for (i = 0; i < G->vexnum; i++) {
    visited[i] = FALSE;
  }
  Push(S, v); visited[v] = TRUE;      // 非递归 在push同时改变visit!!
  while (!IsEmpty(S)) {
    Pop(S, v);      // 第一个元素出栈!! 不需要查看栈顶元素
    Visit(v);       // 先访问, 再将其子结点入栈
    for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
      if (!visited[w]) {
        Push(S, w); visited[w] = TRUE;
      }  // if
    }  // for
  }  // while
}  // dfs_non_rc
