# zju_dsa

## 1. 概论

### 1.1 什么是数据结构
#### 例2-printN

循环实现的函数
```cpp
#include <cstdio>
int main() {
  int N; scanf("%d", &N);
  int i;
  for (i = 1; i <= N; i++) {
    printf("%d\n", i);
  }
  return 0;
}
```


自己第一遍写的递归
```cpp
#include <cstdio>

void printN(int n) {
  if (n == 1) {
    printf("%d\n", n);
    return;
  }
  printN(n-1); printf("%d\n", n);
}

int main() {
  int N; scanf("%d", &N);
  printN(N);
  return 0;
}
```

简化递归函数
```cpp
#include <cstdio>

void printN(int n) {
  if (n) {
    printN(n-1); printf("%d\n", n);
  }
  return;
}

int main() {
  int N; scanf("%d", &N);
  printN(N);
  return 0;
}
```


#### 例3-多项式求值

直接法
```cpp
double f(int n, double a[], double x) {
  double ans = a[0];
  int i;
  for (i = 1; i <= n; i++) {
    ans += a[i]*pow(x, i);
  }
  return ans;
}
```


秦九韶法
```cpp
double f(int n, double a[], double x) {
  double ans = a[n];
  int i;
  for (i = n-1; i > 0; i--) {
    ans = ans * x + a[i-1];
  }
  return ans;
}

```


实现一个测试时间的模版
```
#include <cstdio>
#include <ctime>

clock_t start, stop;
double duration;

int main() {
  printf("%d\n", CLOCKS_PER_SEC);    // 1000000

  /* 不在测试范围内的写在之前 */
  start = clock();
  function();
  stop = clock();
  duration = ((double)(stop-start)) / CLOCK_PER_SEC;

  /* 测试范围之外的代码 写在之后*/

  return 0;
}
```


测试求多项式值的两种算法的时间, 抽象测试函数:
```cpp
#include <cstdio>
#include <ctime>
#include <cmath>

#define MAXN 10    /* 多项式的最大项数 阶数+1 */
#define MAXK 1e7   /* 被测函数最大调用次数 */

clock_t start, stop;
double duration;


double f1(int n, double a[], double x) {
  double ans = a[0];
  int i;
  for (i = 0; i <= n; i++) {
    ans += a[i]*pow(x, i);
  }
  return ans;
}

double f2(int n, double a[], double x) {
  double ans = a[n];
  int i;
  for (i = n-1; i > 0; i--) {
    ans = ans * x + a[i-1];
  }
  return ans;
}

void run(double(*f)(int, double*, double), double a[], int case_n) {
  int i;
  start = clock();
  for (i = 0; i < MAXK; i++) {
    (*f)(MAXN-1, a, 1.12212);
  }
  stop = clock();
  duration = ((double)(stop-start)) / CLOCKS_PER_SEC;
  printf("ticks%d = %f \n", case_n, (double)stop-start);
  printf("duration%d = % 6.2e \n", case_n, duration);
}

int main() {
  int i;
  double a[MAXN];

  for (i = 0; i < MAXN; i++) a[i] = (double)i;

  run(f1, a, 1);
  run(f2, a, 2);
  return 0;
}
```


#### 什么是数据结构?

数据对象在计算中的组织方式。
> * 逻辑结构: 线性结构(一对一), 树(一对多), 图(多对多)
> * 物理存储: 连续(数组), 随机(链表)

与加在上面的一系列操作相关联, 这些操作叫做算法.


##### 抽象数据类型(ADT)

###### 数据类型:
> * 1, 数据的对象集
> * 2, 数据集合相关的操作集合

面向对象语言封装在一个class里.

###### 抽象:
与机器无关,
与数据存储的物理结构无关, 
与实现操作的算法和编程语言无关.

###### 在描述它的时候, 只关注是什么, 而不关注如何做到. 

### 1.2 什么是算法?

#### 1.2.2 算法复杂度
空间复杂度, 占用存储单元的长度。
时间复杂度, 耗费时间的长度

渐进复杂度的上界和下界是不唯一的, 一般取能找到的最小的上界; 能找到的最大的下界.

logn是最好的函数.比n还要快.
nlogn介于n^2与n之间, 程序员的任务就是将n^2的复杂度, 优化成nlogn

复杂度分析窍门。
```
// 两个算法并列相加
T1(n) + T2(n) = max(O(f1(n)), O(f2(n)))
// 两个算法嵌套
T1(n) * T2(n) = O(f1(n) * f2(n))

如果Tn是关于n的k阶多项式的话, 真正起作用的只有最大一项. Tn = theta(n^k)

for循环代码的复杂度, 一共循环了多少次 * 循环体内部代码的复杂度

if-else if条件和另外两个分支中复杂度最大的. max(if-condition, if, else)
```

### 1.3 最大子列和问题

#### 算法1: 暴力求解 O(N^3)
#### 算法2: 二层循环 O(N^2)
#### 算法3: 分而治之 O(NlogN)
把复杂问题切分成小块, 最后组合结果.

```cpp
int max(int a, int b, int c) {
  return a > b ? a > c ? a : c : b > c ? b : c;
}

int divideAndConquer(int A[], int left, int right) {
  int maxLeftSum, maxRightSum;
  int maxLeftBorderSum, maxRightBorderSum;

  int leftBorderSum, rightBorderSum;
  int center, i;
  if (left == right) {
    if (A[left] > 0) {
      return A[left];
    } else {
      return 0;
    }
  }

  center = (left+right) / 2;
  maxLeftSum = divideAndConquer(A, left, center);
  maxRightSum = divideAndConquer(A, center+1, right);

  leftBorderSum = 0; maxLeftBorderSum = 0;
  for (i = center; i >= left; i--) {
    leftBorderSum += A[i];
    if (leftBorderSum > maxLeftBorderSum) {
      maxLeftBorderSum = leftBorderSum;
    }
  }

  rightBorderSum = 0; maxRightBorderSum = 0;
  for (i = center+1; i <= right; i++) {
    rightBorderSum += A[i];
    if (rightBorderSum > maxRightBorderSum) {
      maxRightBorderSum = rightBorderSum;
    }
  }

  return max(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}
```
#### 算法4: 在线处理 O(N)

```cpp
int maxSubseqSum2(int A[], int N) {
  int i;
  int thisMax = 0, maxSum = INT_MIN;
  for (i = 0; i < N; i++) {
    thisMax += A[i];
    if (thisMax > maxSum) {
      maxSum = thisMax;
    } else if (thisMax < 0) {
      thisMax = 0;
    }
  }
  return maxSum;
}
```


## 2. 线性结构

一元多项式的存储:
> * 直接开数组, 指数最为下标, 系数作为值
> * 结构数组, 根据指数有序, 结构体里存系数和指数
> * 链表, coef系数, expon指数数据域, 和link指向下一个结点的指针域

加法运算, 类似与归并思路.

### 实现直接开数组的线性表

```cpp
#include <stdio.h>
/* malloc在stdlib中 */
#include <stdlib.h>              /* debug02 */

typedef int ElementType;

#define MAXSIZE 100

typedef int Status;
#define ERROR 0
#define OVERFLOW -1
#define OK 1

typedef int Position;
// typedef LNode *ptrToNode;     /* debug03 */
/* 定义结构指针需要加struct */
typedef struct LNode *ptrToNode;

struct LNode {
  Position Last;
  // ptrToNode Data[MAXSIZE];    /* debug01 */
  /* Data的类型是ElementType数组*/
  ElementType Data[MAXSIZE];
};

typedef ptrToNode List;


List makeEmpty() {
  List L;
  L = (List)malloc(sizeof(struct LNode));
  L->Last = -1;
  return L;
}

Status find(List L, ElementType elem) {
  Position i; Status NotFound = -1;
  /* 用while循环, 可统一用i作为判断找到与否的条件 */
  while (i <= L->Last && L->Data[i] != elem)
    i++;
  if (i > L->Last) {
    return NotFound;
  } else {
    return i;     /* 返回该元素的下标 */
  }
}

Status insert(List L, ElementType elem, Position i) {
  /* 检查表是否满 */
  if (L->Last == MAXSIZE-1) {
    printf("Overflow\n");
    return OVERFLOW;
  }

  /* 检查插入位置是否合法 */
  if (i < 1 || i > L->Last+2) {
    printf("Error\n");
    return ERROR;
  }

  /* 从右向左, 做整体向右移动的操作 */
  Position j;
  for (j = L->Last; j >= i-1; j--) {
    L->Data[j+1] = L->Data[j];
  }

  /* 插入元素 改变最后元素的下标 */
  L->Data[i-1] = elem;
  L->Last++;
  return OK;
}

Status delete(List L, Position i, ElementType *elem) {
  /* 检查插入位置的合法性 */
  if (i < 1 || i > L->Last+1) {
    printf("Error\n");
    return ERROR;
  }

  Position j;
  /* 记录被删除元素 */
  *elem = L->Data[i];
  /* for (j = i; j <= L->Last-1; j++) { */    /* debug04 */
  /* L->Last是最后一个元素下标, 同样需要移动 */
  for (j = i; j <= L->Last; j++) {
    L->Data[j-1] = L->Data[j];
  }
  L->Last--;
  return OK;
}
```


### 链式线性表存储


我自己写的插入的方法, 用两个结点去移动, 插入一个新分配的结点
```cpp
#define ERROR_P NULL
List insert(List L, ElementType elem, int i) {
  if (i < 1) {
    return ERROR_P;     /* 链表头部之前的插入位置不合法 */
  }
  /* debug1: 统一为插入结点分配空间 */
  List node;
  node = (List)malloc(sizeof(struct LNode));
  node->Data = elem;    /*debug05: 结点的元素也可以事先分配 */
  if (i == 1) {        /* 在链表头部插入 */
    node->Next = L;
    return node;
  } else {            /* 在表头以外的位置插入 */
    Position prevP = L, p;
    /* p = L->Next; */
    if (prevP == NULL) {
      /* 此时i不为1, 插入不合法 */  /* debug04: 空链表L->Next不合法 */
      free(node);
      return ERROR_P;
    }
    p =  L->Next;
    /* int j = 2; */  /* debug02: prevP存在, 可在尾部n+1插入*/
    int j = 1;
    while (prevP && j != i-1) {
      prevP = prevP->Next;
      p = prevP->Next;
      j++;
    }
    // if (j == i ) {
    if (j == i-1 && prevP) {  /* prevP此时为插入序号的前一个 */
      node->Next = p;
      prevP->Next = node;
      return L;
    } else {
      free(node);        /* debug03: 插入失败要回收结点 */
      return ERROR_P;    /* 在链表尾部不存在可插入的结点 */
    }
  }
}
```
<span style="color:red">实际上只要移动前缀结点, 当前结点用prev->Next去记录,</span>
```
node->Next = prev->Next;
prev->Next = node;
```
这个是修改链接关系的核心代码.

插入的正确代码(不带头结点)
```cpp
#define ERROR_P NULL
List insert(List L, ElementType elem, int i) {
  if (i < 1) {
    return ERROR_P;
  }
  List node, prev;
  node = (List)malloc(sizeof(struct LNode));
  node->Data = elem;
  if (i == 1) {
    node->Next = L;
    return node;
  } else {
    prev = L;
    int cnt = 1;
    while (prev && cnt < i-1) {
      prev = prev->Next; cnt++;
    }
    if (prev && cnt == i-1) {
      node->Next = prev->Next;
      prev->Next = node;
      return L;
    } else {
      free(node);
      return ERROR_P;
    }
  }
}
```


### 广义表(Generalized List)

广义表是线性表的推广
对于线性表而言, n个元素都是基本的单元素。
广义表中, 不仅仅可以是单元素, 还是是另外一个广义表.

(链表中嵌套链表)

表示, 标记+union

```cpp
typedef struct GNode *GList;
struct GNode {
  int tag;     // 标记域, 0代表单元素, 1代表结点是广义表
  union {      // 子表指针域和Data域复用, 即共同的存储空间
    ElementType Data;
    GList subList;
  };
  GList next;
};
```

### 多重链表

一个结点的指针域会有多个
包含多个指针域的不一定是多重链表, 如双向链表

树, 图广泛应用

## 3. 栈

### 表达式求值

前缀表达式
中缀表达式
后缀表达式

```
“前缀表达式”，即运算符号位于运算数之前,比如a+b*c的前缀表达式是+a*bc。
你能写出a+b*c-d/e的前缀表达式吗？

Solution: +a*bc-/de
Answer:   -+a*bc/de
```


### 数据类型描述

stack.
一个0个或多个元素的有穷线性表。
操作集: 长度为Maxsize的堆栈S, 堆栈元素item

五个操作
> * 创建一个空栈 Stack createEmpty(int maxSize);
> * 判断栈是否空 int isEmpty(Stack S);
> * 判断栈是否满 int isFull(Stack S, int maxSize);
> * 入栈        void push(Stack S, ElementType elem);
> * 出栈        ElementType pop(Stack S);

#### 代码
```
#include <stdlib.h>

#define MAXSIZE 10
typedef int ElementType;
typedef int Position;

typedef int bool;
#define true 1
#define false 0

/*
// 自己实现栈的存储
struct Stack {
  ElementType Data[MAXSIZE];
  Position top;
};

typedef struct Stack Stack;
*/

// 正确的版本
typedef struct SNode *ptrToNode;
struct SNode {
  ElementType *Data;
  Position top;
  int maxSize;
};
typedef ptrToNode Stack;

Stack createEmpty(int maxSize) {
  Stack S;
  // S = (Stack*)malloc(sizeof(Stack));    // bebug01
  S = (Stack)malloc(sizeof(struct SNode));
  // 除了为S指针分配空间, 还要为Data数组分配空间.
  S->Data = (ElementType*)malloc(sizeof(ElementType) * maxSize);
  S->top = -1;
  // 之前的版本竟然没有用到maxSize;
  S->maxSize = maxSize;
  return S;
}

/*
其实不需要写if-else语句
bool isEmpty(Stack S) {
  if (S->top == -1) return true;
  else  return false;
}


bool isFull(Stack S) {
  if (S->top == S->maxSize-1) return true;
  else  return false;
}
*/

bool isEmpty(Stack S) { return S->top == -1; }

bool isFull(Stack S) { return S->top == S->maxSize-1;}


void push(Stack S, ElementType elem) {
  if (isFull(S)) {
    return;
  } else {
    S->Data[++S->top] = elem;
  }
}

/*
bool pop(Stack S, ElementType *elem) {
  if (isEmpty(S)) {
    return false;
  } else {
    *elem = S->Data[(S->top)--];
    return true;
  }
}

*/

#define ERROR -1
// -1是返回的elem的特殊标记值
ElementType pop(Stack S) {
  if (isEmpty(S)) {
    return ERROR;
  } else {
    return S->Data[(S->top)--];
  }
}
```
