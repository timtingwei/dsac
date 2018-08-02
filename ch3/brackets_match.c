// copyright [2018] <mituh>
// 括号匹配的检验, brackets_mactch(用栈表示期待的迫切程度)
/*
用栈表示 期待的迫程度,每到碰到一个括号,
判断字符与栈顶元素
匹配()[]    -> 栈顶出栈
不匹配(](]( -> 新的括号入栈
非法        -> 跳过非法判断下一个字符
判断完成所有字符后,
栈空 -> 正确; 否则错误

debug case:
case1: -> 1
[([][])]

case2:  非法字符的情况 -> 1
ds[dsd]dsd(dsds[dsd])

case3: -> 0
[([[]))]

case4: ->0
[])

case5:  跨行匹配
aa[
dsds]cs(s
dsd)

case6: 中间过程栈空的情况
aa[0(ds)]aa[[]]

case7: 空栈时, 读入一个 ) or ], 肯定错误
aa[s])aasd()

case 8: 完全不输入

debug 9: [ / ]   ()因此计算匹配不能简单相减
*/
#include <stdio.h>
#include "SqStack.c"

int is_brackets(int ch) {
  char s[5] = "[]()";
  for (int i = 0; i < 4; i++) {
    if (s[i] == ch) return 1;
  }
  return 0;
}

int is_match(int e, int ch) {
  if ((e == '[' && ch == ']') || (e == '(' && ch == ')'))
    return 1;
  return 0;
}

Status brackets_match() {
  SqStack S;
  InitStack(&S);           // 构造空栈
  int ch;
  while ((ch = getchar()) != EOF) {
    if (!is_brackets(ch))
      continue;            // 跳过非法字符  case 2, case5
    if (StackEmpty(S)) {   // 栈空时
      if (ch == ']' || ch == ')') return ERROR;    // case 7
      Push(&S, ch);
    } else {               // 非空栈, 有括号期望匹配
      int e;
      GetTop(S, &e);
      if (is_match(e, ch)) {
        Pop(&S, &e);       // 匹配, 栈顶出战
      } else {
        Push(&S, ch);      // 不匹配, 新括号入栈
      }
    }
  }
  if (StackEmpty(S)) {     // 空栈匹配完全
    return OK;
  } else {
    return ERROR;
  }
}
