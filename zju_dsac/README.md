# zju_dsa

## 1. 概论

### 例2-printN

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
