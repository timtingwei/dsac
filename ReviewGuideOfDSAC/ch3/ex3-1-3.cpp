// Copyright[2018] <mituh>
// ex3-1-3.cpp

// 判定栈操作序列是否为合法序列
bool isValid(char* seq, int n) {
  int i, s;
  s = 0;
  for (i = 0; i < n; i++) {
    if (seq[i] == 'I') {
      s++;
    } else if (seq[i] == 'O') {
      if (s > 0) s--;
      else  return false;
    }
  }
  if (s) return false;
  else  return true;
}
