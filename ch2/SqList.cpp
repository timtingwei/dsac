// copyright [2018] <mituh>
// SqList.c

#include <stdlib.h>
#include <stdio.h>


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;    // Status是函数返回的值

typedef int ElemType;    // 线性表储存的元素类型

// --------- 线性表的动态分配储存结构 -----------
#define LIST_INIT_SIZE 100    // 初始分配空间大小为100
#define LISTINCREMENT 10      // 扩容每次增量为10
typedef struct SqList {
  ElemType * elem;            // 储存空间基址
  int length;                 // 当前长度    why?均声明不定义, 造函数中定义
  int listsize;               // 当前分配的存储容量
}SqList;


Status initList_Sq(SqList &L) {
  // 构造一个空的线性表L
  L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
  if (!L.elem) exit(OVERFLOW);    // 存储分配失败
  L.length = 0;                     // 空表长度为0
  L.listsize = LIST_INIT_SIZE;      // 初始存储容量
  return OK;
}  // initList_Sq


Status ListInsert_Sq(SqList &L, int i, ElemType e) {
  // 在顺序线性表L中第i个位置之前插入新的元素e
  // 第i个元素, 1<=i<=ListLength(L)+1
  if (i < 1 || i > L.length+1) return ERROR;
  if (L.length >= L.listsize) {       // 存储空间是否分配满
    ElemType * newbase = (ElemType *)realloc(L.elem,
                                  (L.listsize + LISTINCREMENT) * sizeof(ElemType));
    if (!newbase) exit(OVERFLOW);
    L.elem = newbase;                 // 新基址
    L.listsize += LISTINCREMENT;      // 增加存储容量
  }
  ElemType *q, *p;
  q = &(L.elem[i-1]);
  for (p = &(L.elem[L.length-1]); p >= q; --p) *(p+1) = *p;  // 从
  *q = e;                  // 插入e
  ++L.length;              // 表长度增1
  return OK;
}


Status ListDelete_Sq(SqList &L, int i, ElemType &e) {
  // 在顺序线性表L中删除第i个元素, 并用e返回其值
  // 第i个元素满足, 1<=i<=Listlength(L)
  if (i < 1 || i > L.length+1) return ERROR;
  // why?是否需要缩容?
  ElemType *q, *p;
  p = &L.elem[i-1];                     // p指向要删除的值
  e = *p;                               // 用e返回删除的值
  q = L.elem + L.length - 1;            // 表尾元素的位置
  // q = &L.elem[L.length-1];           // 与上句等价
  for (++p; p <= q; ++p) *(p-1) = *p;   // 从i位置往左移
  --L.length;          // 表长减1  why?不处理被移在末尾元素
  return OK;
}  // ListDelete_Sq

// 在顺序线性表L中查找第1一个值与e满足compare()的元素序位

// 归并La和Lb得到新的顺序线性表Lc, Lc的元素也按非递减排列



Status ListPrint_Sq(SqList &L) {
  // 打印用于测试
  for (int i = 0; i < L.length; i++) printf("%d ", L.elem[i]);
  printf("\n");
  return OK;
}

int main() {
  SqList slst;
  initList_Sq(slst);
  ListInsert_Sq(slst, 1, 3);
  ListInsert_Sq(slst, 2, 2);
  ListInsert_Sq(slst, 3, 6);
  ListInsert_Sq(slst, 2, 14);

  ListPrint_Sq(slst);

  ElemType e;
  ListDelete_Sq(slst, 2, e);
  ListPrint_Sq(slst);
  return 0;
}
