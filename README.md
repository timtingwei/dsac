动手实现一下《数据结构》严蔚敏

其他参考: 《大话数据结构》

## ch1 绪论

## ch2 线性表 

### 2.3 线性表链式实现

#### 2.3.1 线性链表

##### 单链表
> * 1, 线性表的单链表存储结构
> * 2, 单链表插入
> * 3, 单链表删除
> * 4, 头插法, 建立带头结点的单链线性表  (类似于插队, 参考《大话数据结构》)
> * 5, 尾插法 (正常的排队逻辑, 参考《大话数据结构》)
> * 6, 归并两个有序链表

##### 静态链表
> * 1, 线性静态链表存储结构
> * 2, 将space分量初始化成备用链表
> * 3, 手动实现malloc()分配空间
> * 4, 获取静态链表的长度
> * 5, 静态链表插入
> * 6, 静态链表删除
> * 7, 手动实现Free() 回收空间

> * 8, 静态链表中查找
> * 9, 静态链表整表添加
> * 10, 静态链表整体删除
> * 11, 归并两个有序静态链表(仍旧有问题, 需要参考数据结构p33)

#### 2.3.2 循环链表

特点:从表中最后一个结点的指针域指向头结点, 整个链表形成一个环
与线性链表的差别: 仅在于算法中的循环条件不是p或p->next是否为空，而是他们是否等于头指针.

```cpp
// 将两个循环链表合并成一个表, (参考大话数据结构)
p = rearA->next;   // 保存a表的头结点
rearA->next = rearB->next->next;       // 将本指向B表的第一个结点, 赋值给rearA->next
q = rearB->next;   // 保存b表的头结点
rearB->next = p;   // a表的头结点赋值给rearB->next
free(q);           // 释放q, b表原来的头结点被释放
```

#### 2.3.3 双向链表


单链表缺点: NextElem的执行时间为O(1), 而PriorElem的执行时间为O(n).
双向链表(double linked list)是在单链表的每个结点中, 再设置一个指向其前驱结点的指针

后继的前驱, 前驱的后继, 都是它自己
```cpp
d->next->prior = d->prior->next =  d;
```

插入:
1, s在p之后
```cpp
s->prior = p;        s->next = p->next;
p->next->prior = s;  p->next = s;
```

2, s在p之前
```cpp
s->prior = p->prior; s->next = p;
p->prior = s;        s->prior->next = s;
```

删除p
```cpp
p->prior->next = p->next;
p->next->prior = p->prior;
free(p);
```

实现:

> * 1, 双向链表存储结构
> * 2, 初始化成空的双向循环链表
> * 3, 返回双向循环链表的长度（bug, 解决）
> * 4, 双向循环链表的查找(bug, 凭空多处一位, 已经解决)
> * 5, 双向循环链表的插入
> * 6, 双向循环链表的删除



### 2.4 一元多项式的表示以及相加
暂时跳过, 学习栈和队列

### 总结一下:
线性表分为顺序存储和链式储存;
链式储存分为: 单链表, 静态链表, 循环链表, 双向链表


## 3. 栈和队列

### 3.1 栈(stack)

限定在表尾进行插入或者删除操作的线性表。
表尾称为 **栈顶** (top),  表头称为 **栈底** (top), 不含元素的空表称为空栈。
满足 **后进先出** (Last in First Out = LIFO)原则。
联想: 铁路调度站台, 土坑

> * 1, 栈的插入(push)
> * 2, 栈的删除(pop)
> * 3, 取栈顶元素(top)
> * 4, 栈的初始化(init)
> * 5, 判空(empty)

### 3.2 栈的应用举例

1, 数制转换, conversion(求余结果入栈, 先进后出原则, 先被计算的在最后被打印输出)
2, 括号匹配的检验, brackets_mactch(用栈表示期待的迫切程度,)
3, 行编辑程序, LineEdit(栈作为输入缓冲区)

```cpp
// 行编辑程序的记录
// debug1: 在外循环进入前, 先getchar一个字符, 如果ch==EOF,
// 对于外层循环结束, 在内存循环结束后, 同样getchar()一次;
// debug2: 在声明一个stack后InitStack(), 如果只是清空stack缓存, ClearStack();
// debug3: 如果这个栈的函数结束后不再有作用, DestroyStack()
// ClearStack() 和 DestroyStack(), 定义和声明在Stack头文件中
// improve: 三个并列的if, 改写成switch
```

4, 迷宫求解(没做)
5, 表达式求值(没做)
四则运算表达式求值(《大话数据结构》没做)

### 3.3 栈的递归实现(没实现)

有的数据结构, 如二叉树, 广义表, 结构本身就有递归特性, 他们的操作可以递归描述;
有的一类问题, 问题本身没有递归描述, 但用递归求解比迭代求解更简单, 八皇后, Hanoi塔问题


### 3.4 队列

队列(queue)是一种先进先出(first in first out, FIFO)的线性表

只允许在队尾(rear)插入元素, 在队头(front)删除元素

应用: 操作系统中的作业排队

与栈的区别: 操作类似, 但队列的删除操作在队头(front)进行

双端队列: 限定插入和删除操作在表的两端进行的线性表;
输出受限(一端可插可删, 另一端只插), 输入受限（一端可插可删, 另一端只可删)
一个端点插入的元素, 只能从该端点删的双端队列, 变成了两个栈底相邻的栈.

### 3.4.2 链队列

需要头尾两个指针才能唯一确定;
空的链队列的判定条件: 头指针和尾指针指向头结点;

```cpp
// LinkQueue.c
// - - - - - 单链队列-----队列的链式存储结构 - - - - -
typedef struct QNode {
  QElemType       data;
  struct QNode   * next;
} QNode, * QueuePtr;

typedef struct {
  QueuePtr front;    // 队头指针
  QueuePtr rear;     // 队尾指针
}LinkQueue;
```

> * 1, 存储结构
> * 2, 构造空链队列
> * 3, 销毁队列
> * 4, 队列Q的队尾插入元素e(ps:插入新元素需要分配空间)
> * 5, 队列Q的队首删除元素e(考虑队列空的情况 和 删除最后一个结点的情况)

删除操作, 一般情况只要改变front中的指针, 但当队列中最后一个元素被删除后， 队列rear指针丢失, 需要对队尾指针重新赋值(与front相同, 指向头结点);


### 3.4.3 循环队列--队列的链式表示和实现

进行存储再分配扩大数组空间, 因为队列的实际可用空间并非占满, 一个比较巧妙的方法是将顺序队列臆造为一个 **环状空间**.

Q.front=Q.rear时, 环状空间可能满, 也可能空;
两种处理方法:
> * 其一是另设一个标志位以区别队列是"空"还是"满"
> * 其二是少用一个元素空间, 约定“队列头指针在队列尾指针的下一位置", 作为队列呈"满"状态的标志

如果设用循环队列, 必须为它设定一个最大队列长度; 如果无法估计, 就用链队列

算法描述:

```cpp
// SqQueue.c
// - - - - - 循环队列---队列的顺序存储结构 - - - - -
#define MAXQSIZE 100     // 最大队列长度
typedef struct {
  QElemType * base;      // 初始化的动态分配存储空间
  int front;             // 头指针, 队列不空, 指向头元素
  int rear;              // 尾指针, 队列不空, 指向队列尾元素的下一位置
}SqQueue;
```

实现了如下一些操作:
> * 1, 构造一个空队列
> * 2, 返回Q的元素个数, 即队列的长度
> * 3, 插入元素e作为Q的新队尾(注意队列满的情况)
> * 3, 删除Q的队头元素(注意队列为空的情况)

### 3.5 离散事件模拟(没做, 等待补充)

## ch4 串

### 4.1 串类型的定义

空串: 零个字符的串, 它的长度为0
子串: 串中任意个连续的字符组成的子序列
子串在主串中的位置: 子串的第一个字符在主串中的位置

**空格串**(blank string, 区别于空串):由一个或多个空格组成的串;  ' ';

串和线性表:
> * 逻辑结构: 相似, 区别在于串的数据对象约束为字符集
> * 基本操作: 很大区别。线性表多以"单个元素"作为操作对象, 串通常以"串的整体"作为操作对象

串的整体操作举例: 串中查找某个子串, 求取一个子串, 在串中某一位置上插入一个子串删除一个子串。

> * 1, 实现定位函数Index(S, T, pos), 依赖判等, 求串长, 求子串等操作 - 算法4.1

### 4.2 串的表示和实现

串的机内三种表示方法: 定长顺序存储表示, 堆分配存储表示, 串的块链存储表示

#### 4.2.1 定长顺序存储表示
用一组地址连续的存储单元, 存储串值的字符序列.

截断: 超过预定义长度的串值被舍去

串长的两种表示方法:
> * 1, 以下标为0的数组分量存放串的实际长度, 如PASCAL
> * 2, 在串值后面加入一个不计入串长的结束标记符, 如C中的"\0"表示串值终结, 此时串长为隐含值

该结构下串操作, (两个例子)


两个实现
> * 1, 实现串连接 - 算法4.2
> * 2, 实现求子串 SubString - 算法 4.3


##### 1, 串连接Concat(&T, S1, S2)

三种情况: 
1, 两个长度相加还没达到预设最大值, S1[0]+S2[0] <= MAXSTRLEN;
2, S2被一部分截断, S1[0] < MAXSTRLEN, S1[0]+S2[0] > MAXSTRLEN
3, 和串S1相等, S2被完全截断, S1[0] = MAXSTRLEN;

##### 2, 求子串(substring)
主要问题是判断用户给出数据是否合理, 判断代码如下:
```cpp
if (pos < 1 || pos > S[0] || len < 0 || len > S[0] - pos + 1)
    return ERROR;                             // 输入长度和位置不合法
```

#### 4.2.2 堆分配存储表示

插入操作:         // 在串S的pos个字符之前插入T
> * 插入位置是否合理?
> * 插入的串是不是空串?
> * 重新分配分配存储空间
> * 为插入T腾出位置
> * 插入T
> * 改变S的长度

堆分配存储优点: 既有顺序存储结构的特点, 处理方便, 操作中对串长又没有任何限制.

StrAssign操作:(生成一个其值等于串常量char的串T)
> * 判断常量串是否为为空串
> * 是: -> ch = null ,length=0;
> * 不是:
> * 别忘记为T的存储区分配空间,
> * 将常量串赋值给T
> * 别忘了赋值T的长度


**实现其他操作:**
> * 生成一个其值等于串常量char的串T
> * 求串长
> * 比较两个串, S>T, S<T, S=T
> * 清空串,(别忘记释放空间)
> * 连接两个串成一个新串,(为新串释放, 分配空间)
> * 求子串(注意pos代表是第几个元素, 索引是pos-1, 要判断pos,len是否合法, 释放原本存储空间, 判断空串, 为非空串分配空间, 赋值和赋长度)


几个要注意的点:

**1, 求子串操作中:**

<span style="color:red">注意pos代表是第几个元素, 索引是pos-1, 要判断pos,len是否合法, 释放原本存储空间, 判断空串, 为非空串分配空间, 赋值和赋长度</span>


**2, 初始化串**
<span style="color:red">在调用时, 需要用StrAssign初始化一个HString, 不然在Concat()和SubString()函数中, free()会抛出error </span>
日志如下:
```sh
a.out(86530,0x7fffb5570380) malloc: *** error for object 0x117077520: pointer being freed was not allocated
*** set a breakpoint in malloc_error_break to debug
Abort trap: 6
```

用gdb调试一下:
```cpp
(gdb) b Concat
Breakpoint 1 at 0x100000b3b: file ./HString.c, line 79.
(gdb) r
Starting program: /Users/htwt/timspace/dsac/ch4/a.out 
[New Thread 0xe03 of process 86462]
warning: unhandled dyld version (15)
len=5
cmp=2

Thread 2 hit Breakpoint 1, Concat (T=0x7ffeefbff8f0, S1=..., S2=...) at ./HString.c:79
79	  if ((*T).ch) { free((*T).ch); T->ch = NULL;}         // why not? ch=NULL?
(gdb) watch T->ch
Hardware watchpoint 2: T->ch
(gdb) n
a.out(86462,0x7fffb5570380) malloc: *** error for object 0x100003248: pointer being freed was not allocated
*** set a breakpoint in malloc_error_break to debug

Thread 2 received signal SIGABRT, Aborted.
0x00007fff7ceb1b6e in ?? ()
```

#### 4.2.3 串的块链存储表示

链表存储串值
结点大小: 一个结点可以存放1个或n个字符(结点大小为n)
链表中最后一个结点, 不被串值占满, 用"#"不上, "#"为非串值字符

链式存储中, 影响串处理的因素:
> * 1, 存储密度, = 串值所占存储位/实际分配的存储位;
> * 2, 内外存交换
> * 3, 串的字符集大小, 字符集小, 则串内的编码就短

链块存储的优缺点:
> * 优点: 连接操作方便;
> * 缺点: 不如前两种灵活, 存储量大, 操作复杂




### 4.3 串的模式匹配算法

#### 4.3.1 朴素的模式匹配算法
Index.c - 算法4.5

我自己实现的版本:
```cpp
// 返回子串T在主串S中第pos个字符之后的位置
int Index(SString S, SString T, int pos) {
  // 1<=pos<=S.length-T.length+1
  if (pos < 1 || pos > S[0]-T[0]+1) return ERROR;
  int i, j;
  for (i = pos; i <= S[0] - T[0]+1; i++) {
    int ok = 1;
    for (j = 0; j <= T[0]-1; j++) {
      if (S[i+j] != T[j+1]) { ok = 0; break; }
    }
    if (ok) return i;
  }
  return 0;
}
```

标准的朴素匹配版本:
<span style="color:red">注意指针的抽象的运用..(**回溯法**)</span>
```cpp
// 标准的朴素匹配 O(n) = (n-m+1)*m;
int Index(SString S, SString T, int pos) {
  // 1<=pos<=S.length-T.length+1
  // T非空, 1 <= pos <= StrLength(S)
  int i, j;
  i = pos, j = 1;
  while (i <= S[0] && j <= T[0]) {
    if (S[i] == T[j]) {
      i++; j++;
    } else {
      i = i-j+2; j = 1;          // i退回到下一位, j退回到首位 i = i-(j-1)+1=i-j+2;
    }
  }
  if (j > T[0]) {                // T被匹配完全才退出的循环
    return i-T[0];               // why? 完全匹配后, i = ans+Strlen(T);
  }
  return 0;
}
```


朴素版本效率低的例子:
```
S = "0000000000000000000000000000000000000001", n个0
T = "00000000001", m个0
```
前n-m-1次判断每次都需要判断m次, 最后一次匹配成功


01串: 
> * 在计算机图形显示中, 把画面表示成一个01串, 一页书就是几百万个0和1组成的串.
> * 二进制计算机处理的都是01串
> * 一个字符ascii可以看成8个二进位的01串, 汉字也被作为01串

#### 4.3.2 KMP模式匹配算法


##### 实现KMP
abcdefgab
abcdex

1, 子串中, a不与自己后面的子串的任何一个字符串相等, 而子串中后几位又和主串分别相等, a不可能与S串的第2位到第5位字符相等

2, 对于在子串中有与首字符相等的字符, 也是可以省略一部分不必要的判断步骤.

KMP算法中, 主串的i值是不断回溯的, KMP就是为了让这些没必要的回溯不发生.
考虑变化的只有j值, <span style="color:red">j的变化与主串无关, 关键取决于T串的结构中是否有重复的问题</span>

j的值多少取决于当前字符之前的串的前后缀的相似度:
```sh
           / 0, 当j=1时, 
next[j] = -  Max {k | 1<k<j, 且'p[1]...p[k-1]' = 'p[j-k+1]...p[j-1]'} 当此集合不空时
           \ 1, 其他情况
```

T=abcdex
```cpp
j       123456
模式串   abcdex
next[j] 011111
```

T=abcabx
```cpp
j       123456
模式串   abcabx
next[j] 011123
```

如果前后缀一个字符相等, k=2; n个字符相等, k=n+1

##### 改良KMP
利用首位next[1]的值去取代与它相等的后续next[j]的值

```cpp
if (T[i] != T[j])
  nextval[i] = j;
if (T[i] == T[j])
  nextval[i] = nextval[j];   // 如果与前缀相同, 将前缀的nextval赋值给他
```

计算出next值的同时, 如果a位字符与它next值指向的b位字符相等, 则该a位的nextval就指向b位的nextval;
如果不等, 则该a位的nextval值就是它自己a位的next的值。



### 4.4 串操作应用举例(待补充)

### 4 总结:

对串这种结构, 更关注子串的应用问题, 如查找, 替换等操作;
关注高级语言调用的函数;
理解它当中的原因, 碰到复杂问题时, 更灵活的使用.
