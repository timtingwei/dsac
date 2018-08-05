// Copyright [2018] <mituh>
// CreateBiTree.c
// 建立二叉树

#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;      // Status是函数返回的值



typedef char TElemType;

/* 二叉树的二叉链表结点结构定义 */
typedef struct BiTNode {
  TElemType data;
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;


// 中序遍历建立二叉树
void CreateBiTree(BiTree *T) {
  TElemType ch;
  scanf("%c", &ch);
  if (ch == '#') {
    *T = NULL;
  } else {                           /* why?????? */
    *T = (BiTree) malloc (sizeof(BiTNode));
    if (!*T) exit(OVERFLOW);
    CreateBiTree(&((*T)->lchild));   /* 构造左子树 */
    (*T) -> data = ch;
    printf("data=%c\n", (*T)->data);
    CreateBiTree(&((*T)->rchild));   /* 构造右子树 */
  }
}
// AB#D##C##
// #B#D#A#C#
// ###DB##CA

int main() {
  BiTree T;
  CreateBiTree(&T);
  return 0;
}
