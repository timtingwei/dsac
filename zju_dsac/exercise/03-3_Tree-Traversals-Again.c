/* Copyright [2019] <mituh> */
/* 03-3_Tree-Traversals-Again.c */
/* 用栈实现中序遍历 */

#include <stdlib.h>
#include <stdio.h>
#define MaxSize 30
int pre[MaxSize];
int in[MaxSize];
int post[MaxSize];

typedef struct SNode *PtrToSNode;
struct SNode {
  int top;
  int Elements[MaxSize];
};
typedef PtrToSNode Stack;

Stack CreateStack() {
  Stack S;
  S = (Stack)malloc(sizeof(struct SNode));
  S->top = 0;
  return S;
}

void Push(int Elem, Stack S) {
  S->Elements[S->top++] = Elem;
}

int Pop(Stack S) {
  return S->Elements[--(S->top)];
}

void Print(int arr[], int N) {
  int i, flag;
  flag = 0;
  for (i = 0; i < N; i++) {
    if (!flag) {
      printf("%d", arr[i]);
      flag = 1;
    } else {
      printf(" %d", arr[i]);
    }
  }
  printf("\n");
}

void GetPreAndInOlder(int N) {
  int i, v, pre_i, in_i, tmp;
  char s[4];
  Stack S;
  pre_i = 0; in_i = 0;
  S = CreateStack();

  for (i = 0; i < 2*N; i++) {
    scanf("%s", s);
    if (s[1] == 'u') {
      scanf("%d", &v);
      pre[pre_i++] = v;
      Push(v, S);
    } else {
      tmp = Pop(S);
      in[in_i++] = tmp;
    }
  }
}

/* 已知前序遍历和中序遍历, 得到后序遍历 */
void slove(int PreL, int InL, int PostL, int n) {
  if (n == 0) return;
  if (n == 1) {
    post[PostL] = pre[PreL]; return;
  }
  int i, root, L, R;

  root = pre[PreL];
  post[PostL+n-1] = root;
  for (i = 0; i < n; i++) {
    if (in[InL+i] == root) break;
  }
  L = i; R = n-L-1;
  slove(PreL+1, InL, PostL, L);
  slove(PreL+L+1, InL+L+1, PostL+L, R);
}


int main() {
  int N;
  scanf("%d\n", &N);
  GetPreAndInOlder(N);
  slove(0, 0, 0, N);
  Print(post, N);
  return 0;
}
