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

Polynomial ReadPoly() {
  Polynomial P, Rear, t;
  int c, e, N;

  scanf("%d", &N);
  P = (Polynomial)malloc(sizeof(struct PolyNode));    /* 链表头空节点 */
  P->link = NULL;
  Rear = P;

  while (N--) {
    scanf("%d %d", &c, &e);
    Attach(c, e, &Rear);
  }
  t = P; P = P->link; free(t);   /* 删除临时生成的头节点 */
  return P;
}

Polynomial MultiPoly(Polynomial P1, Polynomial P2) {
  Polynomial P, Rear, t1, t2, t;
  int c, e;

  if (!P1 || !P2) return NULL;

  t1 = P1; t2 = P2;
  P = (Polynomial)malloc(sizeof(struct PolyNode)); P->link = NULL;
  Rear = P;
  while (t2) {   /* 先用P1的首项乘以P2的每一项 */
    Attach(t1->coef*t2->coef, t1->expon+t2->expon, &Rear);
    t2 = t2->link;
  }
  t1 = t1->link;
  while (t1) {
    t2 = P2; Rear = P;
    // ...
    while (t2) {
      // ...
      e = t1->expon+t2->expon;
      c = t1->coef*t2->coef;
      if (Rear->link && Rear->link->expon > e) {
        Rear = Rear->link;
      } else if (Rear->link && Rear->link->expon == e) {   /* 指数相同 */
        if (Rear->link->coef + c) {   // 相加系数非0
          // Attach(c+Rear->link->coef, e, &Rear);      /* 系数相加指数不变 */
          Rear->link->coef += c;      /* 不需要新的节点 */
        } else {   // 相加系数为0
          t = Rear->link;
          Rear->link = t->link;
          free(t)
          // ??
        }
        
      } else {
        /* 下一项系数比当前e小, 申请节点插入 */
        // Attach(c, e, &Rear);
        t = (Polynomial)malloc(sizeof(struct PolyNode));
        t->coef = c; t->expon = e;
        t->link = Rear->link;
        Rear->link = t; Rear = Rear->link;
      }
      t2 = t2->link;
    }
    t1 = t1->link;
  }

  t2 = P; P = P->link; free(t2);
  return P;
}

void PrintPoly(Polynomial P);   // 输出多项式

void PrintPoly(Polynomial P) {
  /* 输出多项式 */
  int flag = 0;    /* 用于控制打印格式 */

  if (!P) {
    printf("0 0\n"); return;
  }
  while (P) {
    if (!flag) {
      flag = 1;
    } else {
      printf(" ");
    }
    printf("%d %d", P->coef, P->expon);
    P = P->link;
  }
}


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
