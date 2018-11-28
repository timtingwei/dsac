// Copyright [2018] <mituh>
// polynomial.cpp
// 多项式链式构造

struct PolyNode {
  int coef;   /* 系数 */
  int expon;  /* 指数 */
  struct PolyNode *link;   /* 指向下一节点的指针 */
};
typedef struct PolyNode *Polynomial;   /* 多项式的类型 */
Polynomial P1, P2;
