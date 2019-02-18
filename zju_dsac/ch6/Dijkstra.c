/* Copyright [2019] <mituh> */
/* Dijkstra.c */
/* 有权图的单源最短路径 */

/* 给出图, 从顶点V出发到各个顶点的最短路径, 以及到W的路径 */

/* 初始化dist和path数组 */
/* dist全部为正无穷, path为-1 */
/* 源点dist为0, 直接与源点相邻的顶点dist[w]为E<v, w>, path为源点v */

/* collected清空 */


void Dijkstra(Vertex S) {
  /* 已经初始化好dist和path数组 */
  while (1) {
    V = 未被收录的顶点中dist最小者;
    if (不存在这样的V) {
      break;
    }
    collected[V] = true;
    for (V的每个邻接点W) {
      if (collected[W] == false) {
        if (dist[V] + E<V, W> < dist[W]) {
          dist[W] = dist[V] + E<V, W>;
          path[W] = V;
        }
      }
    }
  }
}
