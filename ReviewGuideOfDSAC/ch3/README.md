# 第三章栈和队列错题笔记
## 3-1 栈

### 1.栈和队列具有相同的(逻辑结构)
```
逻辑结构包括:
(1)线性结构: 线性表, 栈, 队列, 串
(2)非线性结构: 树, 图

存储结构:
(1)顺序存储
(2)链式存储
```

### 3. (删除栈底元素)不是栈的基本操作
```
将栈置为空栈, createEmpty()是基本操作!题目看仔细
```

### 7. 设链表不带头结点且所有操作均在表头进行, 则下列最不适合作为链栈的是(只有表头结点指针, 没有表尾指针的单向循环链表)
```
没有看清这是一个循环链表, 若只有表头结点, 对表头结点操作后, 需要找到表尾, 复杂度为O(n)
而单向循环链表, 表尾很容易找到表头.
```


### 11. 3个不同元素依次进栈, 能得到(5)种不同的出栈顺序
```
卡特兰数, 公式:

另外一种考法是, 某个特定的条件依次进栈的顺序, 比如以b开头, 一般用穷举法.
```


### 24.
```
标识符的第一个字符必须是大小写英文字母或者下划线, 而不能是数字
```