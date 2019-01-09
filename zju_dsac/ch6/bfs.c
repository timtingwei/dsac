/* Copyright [2019] <mituh> */
/* bfs.c           */
/* 优先广度遍历 */

void BFS(Vertex V) {
  visited[V] = true;
  EnQueue(V, Q);
  while (!Empty(Q)) {
    DeQueue(Q);
    for (V的每个邻接点W) {
      if (!visited[W]) {
        visited[W] = true;
        EnQueue(W, Q);
      }
    }
  }
}
