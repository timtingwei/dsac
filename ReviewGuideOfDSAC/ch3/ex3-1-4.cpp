// Copyright[2018] <mituh>
// ex3-1-4.cpp

#include <stack>
using namespace std;
// 用栈的思想判断链表是否回文
bool is_p(List L, int n) {
  if (n <= 0) return false;
  if (n == 1) return true;     /* 单个元素对称 */
  /* 假设链表为不带头结点的链表 */
  stack<int> s;
  int i;
  List pNode = L;
  for (i = 1; i <= n/2; i++) {
    s.push(pNode->data);
    pNode = pNode->next;
  }
  /* 奇数个时候跳过中间元素 */
  if (n % 2) pNode = pNode->next;

  while (pNode != nullptr) {
    /* 当前元素是栈顶元素的对称元素 */
    if (pNode->data != s.top()) {
      return false;
    } else {
      s.pop();
    }
  }
  /* 所有元素都对称 */
  return true;
}
