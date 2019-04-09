/* Copyright [2019] <mituh> */
/* ch5/3.c */
/* dfs的非递归算法 */

void dfs(LGraph G, int v) {
  /* dfs只能用于遍历一个连通分量 */
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
    if (!exist) {    /* 若v结点不存在未访问 */
      pop(S, v);
    }
  }
}
