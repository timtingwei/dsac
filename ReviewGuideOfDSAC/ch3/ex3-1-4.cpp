// Copyright[2018] <mituh>
// ex3-1-4.cpp
// 用栈的思想判断链表是否对称

/*
#include <stack>
using namespace std;

bool is_p(List L, int n) {
  if (n <= 0) return false;
  if (n == 1) return true;     // 单个元素对称
  // 假设链表为不带头结点的链表
  stack<int> s;
  int i;
  List pNode = L;
  for (i = 1; i <= n/2; i++) {
    s.push(pNode->data);
    pNode = pNode->next;
  }
  // 奇数个时候跳过中间元素
  if (n % 2) pNode = pNode->next;

  while (pNode != nullptr) {
    // 当前元素是栈顶元素的对称元素
    if (pNode->data != s.top()) {
      return false;
    } else {
      s.pop();
    }
  }
  // 所有元素都对称
  return true;
}
*/


int dc(LinkList L, int n) {
  // L是带头结点的单向链表, n是结点个数
  // 对称返回1, 否则返回0
  int i;
  char s[n/2];
  LinkList pNode = L->next;
  for (i = 0; i < n/2; i++) {
    s[i] = pNode->data;        // 将当前结点元素赋值给栈顶元素
    pNode = pNode->next;
  }
  i--;
  if (n%2 == 1) pNode = pNode->next;     // 结点个数为奇数, 跳过中间结点
  while (pNode != NULL && s[i] == pNode->data) {
    pNode = pNode->next;
    i--;                                 // i充当栈顶指针
  }
  if (i == -1) {                         // 遍历后半部分链表
    printf("链表对称\n");
    return 1;
  } else {
    printf("链表不对称\n");
    return 0;
  }
}
