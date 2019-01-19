/* Copyright [2019] <mituh> */
/* 04-6_Complete-Binary-Search-Tree.c */
/* 平衡二叉树的操作集合 */

#include <stdlib.h>
#include <stdio.h>
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
  ElementType Data;
  BinTree Left;
  BinTree Right;
};

void PreorderTraversal(BinTree BT); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal(BinTree BT);  /* 中序遍历，由裁判实现，细节不表 */
BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);
Position Find(BinTree BST, ElementType X);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);


int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}


void PreorderTraversal(BinTree BT) {
  if (BT) {
    printf("%d ", BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
  }
}

void InorderTraversal(BinTree BT) {
  if (BT) {
    InorderTraversal(BT->Left);
    printf("%d ", BT->Data);
    InorderTraversal(BT->Right);
  }
}

BinTree Insert(BinTree BST, ElementType X) {
  if (!BST) {
    BST = (BinTree)malloc(sizeof(struct TNode));
    BST->Data = X;
    BST->Left = BST->Right = NULL;
  } else if (X < BST->Data) {
    BST->Left = Insert(BST->Left, X);
  } else if (X > BST->Data) {
    BST->Right = Insert(BST->Right, X);
  }
  /* 如果相等则无需插入 */
  return BST;
}


Position FindMin(BinTree BST) {
  if (!BST) {
    return NULL;
  } else {
    while (BST->Left) {
      BST = BST->Left;
    }
    return BST;
  }
}

Position FindMax(BinTree BST) {
  if (!BST) {
    return NULL;
  } else if (!BST->Right) {
    return BST;
  } else {
    return FindMax(BST->Right);
  }
}

BinTree Delete(BinTree BST, ElementType X) {
  Position Tmp;
  if (!BST) {
    printf("Not Found\n");
  } else if (X < BST->Data) {
    BST->Left = Delete(BST->Left, X);
  } else if (X > BST->Data) {
    BST->Right = Delete(BST->Right, X);
  } else {
    /* 找到要删除元素的情况 */
    if (BST->Left && BST->Right) {
      /* 拥有两个子结点 */
      Tmp = FindMin(BST->Right);     /* 找到右子树最小的结点 */
      BST->Data = Tmp->Data;
      /* free(Tmp); */  /* 不能直接释放, 要从右子树释放 */
      BST->Right = Delete(BST->Right, BST->Data);
    } else {
      /* 有一个子结点或者无结点 */
      Tmp = BST;
      if (!BST->Left) {
        BST = BST->Right;
      } else {
        BST = BST->Left;
      }
      free(Tmp);
    }
  }
  return BST;
}

Position Find(BinTree BST, ElementType X) {
  if (!BST) {
    return NULL;
  } else {
    if (X < BST->Data) {
      return Find(BST->Right, X);
    } else if (X > BST->Data) {
      return Find(BST->Left, X);
    } else {
      return BST;   /* 找到该元素, 返回结点 */
    }
  }
}

// Update
