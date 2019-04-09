/* Copyright [2019] <mituh> */
/* ch5/4.c */
/* 邻接表转换成邻接矩阵 */

void convert(ALGraph G, int A[M][N]) {
  for (i = 0; i < G->vexnum; i++) {
    p = (G->v[i]).firstarc;            // 取出顶点的第一条边
    while (p != NULL) {                // 遍历边链表
      A[i][p->data] = 1;
      p = p->nextarc;                  // 取出下条边
    }
  }
}
