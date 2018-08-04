// copyright [2018] <mituh>
// test-4-2-2.c

// 测试堆分配

#include <stdio.h>
#include "HString.c"

void PrintStr(HString S) {
  for (int i = 0; i <= S.length-1; i++) {
    printf("%c ", S.ch[i]);
  }
  printf("\n");
}

int main() {
  HString S, T;
  StrAssign(&S, "mituh");
  int len = StrLength(S);
  printf("len=%d\n", len);
  PrintStr(S);
  StrAssign(&T, "mit");
  PrintStr(T);
  int cmp = StrCompare(S, T);
  printf("cmp=%d\n", cmp);

  HString S_concat;
  StrAssign(&S_concat, "");
  Concat(&S_concat, S, T);
  PrintStr(S_concat);
  HString Sub;
  StrAssign(&Sub, "");    // 需要用StrAssign初始化一个HString
  SubString(&Sub, S_concat, 1, S_concat.length);
  PrintStr(Sub);
  return 0;
}

/*
// 需要用StrAssign初始化一个HString
a.out(86530,0x7fffb5570380) malloc: *** error for object 0x117077520: pointer being freed was not allocated
*** set a breakpoint in malloc_error_break to debug
Abort trap: 6
*/
