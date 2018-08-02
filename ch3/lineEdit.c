// copyright [2018] <mituh>
// LineEdit.c
//
/*
行编辑程序(栈作为输入缓冲区)
在编辑每一行时用一个栈, 读入一个字符ch
ch == '#', 删除栈顶 case1: 栈顶为空的情况
ch == '@', 清空整个栈, case2: 清空空栈的情况
ch == '\n', 退出循环, 打印当前栈

case 1:
#

case 2:
@

case 3: 栈空

case 4:
whli##ilr#e(s#*s)

case 5:
  outcha@putchar(*s=#++);

bug1: 无法结束外层主循环,
bug2: 对于一个栈, 没分清楚ClearStack() 和 InitStack()的区别
bug3: 函数结束时, 没有销毁这个栈
*/

#include "SqStack.c"
#include <stdio.h>


// 清空一个栈 O(n)
void ClearStack(SqStack *S) {
  if (StackEmpty(*S)) return;       // 栈为空
  int e;                            // 用来保存被清空的元素
  for (; Pop(S, &e);) {}           // 不断出栈, 知道栈为空
}

// 从栈底打印一个栈 O(n)
void PrintStack_bottom(SqStack S) {
  // 创建一个用于打印的临时栈
  SqStack tmp_S; InitStack(&tmp_S);
  int e;
  while (!StackEmpty(S)) {
    Pop(&S, &e);
    Push(&tmp_S, e);
  }
  while (!StackEmpty(tmp_S)) {
    Pop(&tmp_S, &e);
    printf("%c", e);
  }
  printf("\n");
}

/*
bug1: 无法结束外层主循环,
bug2: 对于一个栈, 没分清楚ClearStack() 和 InitStack()的区别
bug3: 函数结束时, 没有销毁这个栈
void lineEdit() {
  SqStack S; int ch;
  for (;;) {
    InitStack(&S);
    while (((ch = getchar()) != EOF) && ch != '\n' && ch != '\r') {
      // ..
      int e;            // 用来储存 pop, top等操作的临时量
      if (ch == '#') {
        Pop(&S, &e);    // 删除一个空栈在Pop操作中已经定义完全
      } else if (ch == '@') {
        ClearStack(&S);
      } else {          // 输入字符中入栈部分
        Push(&S, ch);
      }
    }
    PrintStack_bottom(S);      // O(n), case3: 栈为空
    ClearStack(&S);            // 清空当前栈
  }
}
*/

// debug1: 在外循环进入前, 先getchar一个字符, 如果ch==EOF,
// 对于外层循环结束, 在内存循环结束后, 同样getchar()一次;
// debug2: 在声明一个stack后InitStack(), 如果只是清空stack缓存, ClearStack();
// debug3: 如果这个栈的函数结束后不再有作用, DestroyStack()
// ClearStack() 和 DestroyStack(), 定义和声明在Stack头文件中
// improve: 三个并列的if, 改写成switch
void lineEdit() {
  SqStack S, int ch;
  InitStack(&S);
  ch = getchar();
  while (ch != EOF) {
    while (ch != EOF && ch != '\r' && ch != '\n') {
      switch ch:
      case '#':
    }
  }
}
