/* Copyright [2019] <mituh> */
/* Floyd.c */
/* 有权图的多源最短路径 */

/* 稀疏图, N次调用Dijskra算法 O(|V|^3 + |E|*|V|);
   稠密图, Floyd算法 O(|V|^3) */

/* G初始化成G[i][j] = E<i, j>, 对角元为0 */

void Floyd() {
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      D[i][j] = G[i][j];
      path[i][j] = -1;
    }
  }

  for (k = 0; k < N; k++) {
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        if (D[i][k] + D[k][j] < D[i][j]) {
          D[i][j] = D[i][k] + D[k][j];
          path[i][j] = k;
        }
      }
    }
  }
}
