// Copyright [2018] <mituh>
// polynomial.cpp
// 多项式链式构造
#inlcude <stdlib.h>

struct PolyNode {
  int coef;   /* 系数 */
  int expon;  /* 指数 */
  struct PolyNode *link;   /* 指向下一节点的指针 */
};
typedef struct PolyNode *Polynomial;   /* 多项式的类型 */
Polynomial P1, P2;


int Compare(int a, int b) {
  /* 比较a和b的大小 */
  if (a == b) {
    return 0;
  } else {
    if (a > b) {
      return 1;
    } else {
      return 0;
    }
  }
}

void Attach(int coef, int expon, Polynomial *pRear) {
  /* 将系数和指数构成的节点追加到尾节点之后 */
  // pRear是指针的指针, 因为要修改指针
  // struct PolyNode* Node = malloc(sizeof(struct PolyNode));
  Polynomial P;
  P->coef = coef; P->expon = expon;
  P->link = NULL;
  (*pRear)->link = P;
  (*pRear) = P;
}

Polynomial AddPoly(Polynomial P1, Polynomial P2) {
  /* 多项式相加 */
  // Polynomial front, rear = malloc(sizeof(struct PolyNode));   // ?
  // struct PolyNode temp;                                       // ?
  Polynomial front, rear, temp;
  int sum;
  rear = (Polynomial)malloc(sizeof(struct PolyNode));
  front = rear;
  while (P1 && P2) {
    switch (Compare(P1->expon, P2->expon)) {
      case 1:
          Attach(P1->coef, P1->expon, &rear);
          P1 = P1->link;
          break;
      case -1:
          Attach(P2->coef, P2->expon, &rear);
          P2 = P2->link;
          break;
      case 0:
          sum = P1->coef + P2->coef;
          if (sum) Attach(sum, P1->expon, &rear);
          P1 = P1->link;
          P2 = P2->link;
    }
  }  /* end while */
  for ( ; P1; P1 = P1->link) Attach(P1->coef, P1->expon, &rear);
  for ( ; P2; P2 = P2->link) Attach(P2->coef, P2->expon, &rear);
  /* 后续的扫尾工作 */
  rear->link = NULL;
  temp = front;
  front = front->link;
  free(temp);
  return front;
}


Polynomial MultiPoly(Polynomial P1, Polynomial P2);  // 多项式的乘法

Polynomial ReadPoly();   // 读取多项式

void PrintPoly(Polynomial P);   // 输出多项式


int main() {
  // 多项式加和乘框架
  Polynomial P1, P2, SP, PP;
  P1 = ReadPoly(); P2 = ReadPoly();
  SP = AddPoly(P1, P2);
  PP = MultiPoly(P1, P2);
  PrintPoly(SP);
  PrintPoly(PP);
  return 0;
}

// update
// update both
// Update today
// Update today
// not good today
// birthday
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
// update today
