/* Copyright [2019] <mituh> */
/* dfs.c           */
/* 优先深度遍历 */

void DFS(Vertex V) {
  visited[V] = true;
  for (V的每个临接点W) {
    if (!visited[W]) {
      DFS(W);
    }
  }
}
