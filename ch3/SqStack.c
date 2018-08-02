// copyright [2018] <mituh>
// SqStack.c

#include <stdlib.h>   // malloc(), free()

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;        // Status是函数返回的值
typedef int SElemType;     // 栈储存的元素类型

#define STACK_INT_SIZE 100     // 存储空间的初始分配量
#define STACKINCREMENT 10      // 存储空间的增量
// - - - - - 栈的顺序存储表示 - - - - -
typedef struct Stack {
  SElemType * base;      // 指向栈底元素的指针
  SElemType * top;       // 栈顶指针
  int stacksize;         // 当前已经分配的储存空间
}  SqStack;

// 构造一个空栈S
Status InitStack(SqStack * S) {
  (*S).base = (SElemType *) malloc (STACK_INT_SIZE* sizeof(SElemType));
  if (!(*S).base) exit(OVERFLOW);         // 存储空间分配失败
  (*S).top = (*S).base;
  (*S).stacksize = STACK_INT_SIZE;
  return OK;
}  // InitStack

// 若栈S为空栈, 则返回TRUE, 否则返回FALSE
Status StackEmpty(SqStack S) {
  if (S.top == S.base) return TRUE;
  return FALSE;
}  // StackEmpty

// 若栈不空, 则用e返回S的栈顶元素, 并返回OK; 否则返回ERROR
Status GetTop(SqStack S, SElemType *e) {
  if (S.top == S.base) return ERROR;     // 栈空
  (*e) = *(S.top-1);
  return OK;
}  // GetTop


// 将新元素e作为新的栈顶元素
Status Push(SqStack *S, SElemType e) {
  // 判断存储空间是否满, 需要重新分配存储空间
  // if (S->stacksize >= STACK_INT_SIZE) {}
  if (S->top - S->base >= S->stacksize) {   // 栈满追加存储空间
    S->base = (SElemType*) realloc (S->base,
                                    (S->stacksize + STACKINCREMENT)
                                    * sizeof(SElemType));
    if (!S->base) exit(OVERFLOW);           // 存储空间分配失败
    S->top = S->base + S->stacksize;        // 重新分配后, top也要改变
    S->stacksize += STACKINCREMENT;         // 栈的总长也改变
  }
  *(S->top)++ = e;                          // top指向e, top上移一位
  return OK;
}  // Push

// 若栈不空, 则删除S的栈顶元素, 用e返回其值, 并返回OK; 否则返回ERROR
Status Pop(SqStack *S, SElemType *e) {
  if (S->top == S->base) return ERROR;    // 栈空
  *e = *(--(S->top));
  return OK;
}  // Pop




