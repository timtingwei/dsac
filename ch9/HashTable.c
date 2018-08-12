/* Copyright [2018] <mituh> */
/* HashTable.c */
/* 实现散列表构造 */

#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;         /* Status是函数返回的值 */

#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE  12        /* 散列表数组长度 */
#define NULLKEY -32768      /* 空键值 */
typedef struct {
  int *elem;                /* 存放元素的动态数组 */
  int count;                /* 当前元素个数 */
} HashTable;

int m = 0;                  /* 散列表表长 */

Status InitHashTable(HashTable *H) {
  /* 初始化散列表 */
  int i;
  m = HASHSIZE;
  /* H->count = 0; */
  H->count = m;         /* why? 表长的意义是什么? 为什么count这个为表长? */
  H->elem = (int *) malloc (sizeof(int) * m);
  if (!(*H).elem) exit(OVERFLOW);
  for (i = 0; i < m; i++) {
    (*H).elem[i] = NULLKEY;
  }
  return OK;
}

/* 散列函数 根据键值来计算插入时地址 */
int Hash(int key) {
  return key % m;      /* 对key值求表长的余数为关键字 除留余数法*/
}

/* 插入关键字进散列表 */
void InsertHash(HashTable *H, int key) {
  int addr = Hash(key);
  while (H->elem[addr] != NULLKEY) {   /* 如果不为空则冲突 */
    addr = (addr + 1) % m;             /* 开放定址法的线性探测, 可更改为其他 */
  }
  H->elem[addr] = key;                 /* 直到有空位后插入关键字 */
}

/* 散列表查找关键字 */
Status SearchHash(HashTable *H, int key, int *addr) {
  *addr = Hash(key);
  while (H->elem[*addr] != key) {
    *addr = (*addr + 1) % m;
    if (H->elem[*addr] == NULLKEY || *addr == Hash(key)) {
      /* 下一个地址不存在, 或者回到原点 不是很理解*/
      return UNSUCCESS;               /* 关键字不存在 */
    }
  }
  return SUCCESS;
}




int main() {
  HashTable s;
  InitHashTable(&s);
  return 0;
}
