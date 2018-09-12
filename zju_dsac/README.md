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
