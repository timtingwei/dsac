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


## ch3. 栈和队列

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


## ch5 数组和广义表(空缺)

## ch6 树和二叉树


### 列出重点要掌握的知识点:
ref: https://www.cnblogs.com/ranjiewen/p/8094317.html

树的先，中，后非递归遍历
二叉排序树的查找，插入，删除操作
二叉排序树节点的下一个节点
平衡二叉树，查找，插入，删除操作
B-/+树基本概念，查找，插入，删除操作
（B树：二叉树，每个结点只存储一个关键字，等于则命中，小于走左结点，大于走右结点；

B-树：多路搜索树，每个结点存储M/2到M个关键字，非叶子结点存储指向关键字范围的子结点；所有关键字在整颗树中出现，且只出现一次，非叶子结点可以命中；

B+树：在B-树基础上，为叶子结点增加链表指针，所有关键字都在叶子结点中出现，非叶子结点作为叶子结点的索引；B+树总是到叶子结点才命中；

B*树：在B+树基础上，为非叶子结点也增加链表指针，将结点的最低利用率从1/2提高到2/3；1/3的数据到新结点，最后在父结点增加新结点的指针；所以，B*树分配新结点的概率比B+树要低，空间使用率更高。）

### 6.1 树的定义和基本术语

树的定义: 树(Tree)是n(n>=0)个结点的有限集。n=0时, 空树;
在任意非空树中,
> * 1, 有且仅有一个根结点
> * 2, 当n>1时, 其余结点可分为m（m>0)个互不相交的有限集T1, T2, ..., Tm, 每个集合本身又是一棵树

几个陌生的概念:

#### 结点分类
结点拥有的子树成为结点的度。
叶结点的度为0
树的度是树内各结点的最大值

#### 结点关系
孩子(Child): 结点的子树根
双亲(Parent): 孩子的上一结点
兄弟(Sibling): 同一个双亲孩子之间..

#### 其他:
层次(Level):根开始为第一层
深度(Depth):树中结点的最大层次, 也称为高度
有序树: 树中的结点的各子树从左至右有序
森林(Forest): 对树中每个结点而言, 其子树的集合。(涉及到森林和树与二叉树之间的转换)

### 树的存储结构 参考《大话数据结构》6.4

#### 双亲表示法

**版本1**

|data|parent|
|----|-------|
data是数据域, parent是指针域

在每个结点中, 附设一个指示器指示其双亲结点在数组中的位置。
约定根结点的位置域设置为-1

这样表示, 根据结点的parent指针很容易找到其双亲, 但要找到结点的孩子, 需要遍历整个结构(单向链表的意思)

**版本2**
|data |parent |firstchild|
|-----|-------|----------|
增加一个结点最左边孩子的域, 长子域, 没有孩子设置为-1

(毕竟孩子的数量不知道, 遍历倒是可以只在孩子中间进行)

**版本3**
|data |parent |rightsib|
|-----|-------|--------|
关注兄弟之间关系, 增加一个右兄弟域, 不存在则赋值为-1


以上几个版本独立的话, 孩子一多遍历时间还是长, 因此可以把他们设计成一个存储结构。
**存储结构的设计是一个非常灵活的过程.一个存储结构设计的是否合理, 取决于基于该存储结构的运算是否合适, 是否方便, 时间复杂度好不好?**
(个人感觉还是对问题的定义首先得清晰, 不然如何设计优美实用的结构呢?)

#### 孩子表示法

每个结点多个指针域, 每个指针指向一个子树的根结点, 多重链表表示方法

**方案一**
|data |child1 |child2| child3 |... |childd|
|-----|-------|------|--------|----|------|
一种指针域的个数就等于树的度, 各个结点度的最大值。

优缺:
各个结点度相差很小时, 开辟的空间被充分利用;
但各个结点度相差很大时, 很多指针域都是空的..

**方案二**
|data |degree |child1 |child2| child3 |... |childd|
|-----|-------|-------|------|--------|----|------|
改进, 按需分配空间。

优缺:
空间利用率高, 
但各个结点链表不同, 加上要维护结点度的数值, 运算上带来时间的损耗

**方案三**
想要找到既减少空指针(造成空间浪费), 又能使结点结构相同(不同带来维护和时间损耗)
最终的**孩子表示法**:

<span style="color:red">线性表+单链表的存储方法: </span>
把每个孩子的结点排列起来, 以单链表作存储结构, 则n个结点有n个孩子链表, 如果叶子结点则此单链表为空。
然后n个头指针又组成一个线性表, 采用顺序存储结构, 存放进一个一维数组中.

孩子的链表结点:
|child |next|
|------|----|
child是数据域, 表示在表头数组中的下标, next是指针域, 用来存储指向某结点的下一个孩子结点的指针

表头数组的表头结点:
|data |firstchild |
|-----|-----------|
data是数据域, 存储某结点数据信息; firtstchild存该结点的孩子链表的头指针

```cpp
// CTree.c
// 树的孩子表示法(线性表+ 单链表)

typedef int TElemType;

#define MAX_TREE_SIZE 100
typedef struct CTNode {  /* 孩子结点 */
  int child;
  struct CTNode *next;
} *ChildPtr;

typedef struct {  /* 表头结构 */
  TElemType data;
  ChildPtr firstchild;
} CTBox;

typedef struct {
  CTBox nodes[MAX_TREE_SIZE];  /* 结点数组 */
  int r, n;                    /* 根的位置和结点数 */
} CTree;
```

优:
查找某一结点的孩子, 或者兄弟, 只需要查这个结点的孩子单链表;
要遍历整棵树, 对头结点的数组循环即可.
缺:
如何知道双亲是谁？

**孩子双亲表示法**
是一种孩子表示法的改进:

孩子的链表结点:
|child |next|
|------|----|

表头数组的表头结点:
|data |parent |firstchild |
|-----|-------|-----------|

	
#### 孩子兄弟表示法

|data |firstchild |rightsib   |
|-----|-----------|-----------|

```cpp
/* 树的孩子兄弟表示法 */
typedef struct CSNode {
  TElemType data;
  struct CSNode *firstchild, *rightsib;
} CSNode, *CSTree;
```

这个表示法, 可以把一棵复杂的树变成一棵二叉树..

### 6.2 二叉树(Binary Tree)

#### 6.2.1 二叉树的定义
特点:
每个结点至多只能有两棵子树(即二叉树中不存在度大于二的结点), 并且, 二叉树的子树有左右之分, 其次序不能任意颠倒。

5种基本形态:
> * 1, 空二叉树
> * 2, 只有一个根结点
> * 3, 根结点只有左子树
> * 4, 根结点只有右子树
> * 5, 根结点既有左又有右子树

#### 6.2.2 二叉树的性质

**3种特殊的二叉树**
斜树(所有结点只有左子树or右子树, 线性表是特殊表现)
满二叉树(所有分支结点都存在左子树和右子树, 并且所有叶子都在同一层上)
完全二叉树(按层序编号, 满二叉树一定是完全二叉树, 完全二叉树不一定是满二叉树)

##### 性质1:在二叉树的第i层至多有2^(i-1)个结点(i>=1)
```
2^(1-1) = 1
2^(2-1) = 2
2^(3-1) = 4
2^(4-1) = 8
```
##### 性质2:深度为k的二叉树, 至多有2^k-1个结点(k>=1)
```
2^1-1 = 1
2^2-1 = 1 + 2 
2^3-1 = 1 + 2 + 4
2^4-1 = 1 + 2 + 4 + 8
```

##### 性质3:对任何一棵二叉树T, 如果其终端结点数为n0, 度为2的结点数是n2, 则n0 = n2+1

即2度的结点数+1 = 叶子数量

推导:
```
总结点数:n2+n1+n0 = n;    // 012度的结点相加为总结点
总分支数=n-1=n1+2n2;      // 度为1的结点分支1, 度为2的结点分支2条, 叶子没有; 总结点数n-1
n1+2n2+1 = n0+n1+n2;
n2+1 = n0;               // 2度的结点数+1 = 叶子数量
```

##### 性质4:具有n个结点的完全二叉树的深度为floor(log2(n))+1

完全二叉树的结点数, 一定少于同样深度的满二叉树的结点树(2^k-1), 但一定多于2^(k-1)-1
2^(k-1)-1 < n <= 2^K-1, 化简后, k=floor(log2n)+1

##### 性质5: 如果一棵有n个结点的完全二叉树(深度floor(log2(n)+1))的结点按层序编号, 对任意结点i(1<=i<=n)有:
> * 1, 如果i=1, 结点i是树的根, 无双亲; 如果i>1, 则其双亲是结点floor(i/2)
> * 2, 如果2i>n, 则结点i无左孩子(结点i为叶子结点), 否则其左孩子是结点2i.
> * 3, 如果2i+1>n, 则结点i无右孩子; 否则其右孩子是结点2i+1

举几个例子试试。
```cpp
       1
	 /    \
	2      3
   / \    / \
  4   5  6   7
 / \  / 
8  9 10
```

#### 6.2.3 二叉树的存储结构

##### 顺序存储
因为二叉树的严格定义, 一维数组存储二叉树中的结点, 并且结点存储位置, 也能体现出结点之间的逻辑关系。

将不存在的结点设置为"^", 对斜树这样对情况, 空间浪费很大.
```cpp
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
A ^ B ^ ^ ^ C ^ ^ ^  ^  ^  ^  ^  D
```

顺序存储结构一般只用于完全二叉树.

##### 二叉链表
二叉树每个最多有两个孩子, 所以为它设计一个数据域和两个指针域。
|lchild |data |rchild |
|-------|-----|-------|

data数据域, lchild和rchild是指针域

```cpp
/* 二叉树的二叉链表结点结构定义 */
typedef struct BiTNode {
  TElemType data;
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

```

如果有需要, 再增加双亲指针


### 6.3 遍历二叉树 和 线索二叉树
二叉树的遍历(traversing binary tree)是指从根结点出发, 按照某种次序访问二叉树种所有结点, 使得每个接地哪被访问一次且仅被访问一次.

#### 前序遍历
若二叉树为空, 则空操作返回, 否则先访问根结点, 然后前序遍历左子树, 再遍历右子树
中左右
#### 中序遍历
...
左中右
#### 后续遍历
...
左右中

#### 遍历结果推导
```
已知:
前 ABCDEF
中 CBAEDF
求
后: CBEFDA
```

```
已知:
中 ABCDEFG
后 BDCAFGE
求
前: EACBDGF
```

> * 已知前序遍历和中序遍历, 可求后序遍历
> * 已知中序遍历和后序遍历, 可求前序遍历

知道前后, 不能确定一棵二叉树!!

### 二叉树的建立
```cpp
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
  } else {
    *T = (BiTree) malloc (sizeof(BiTNode));
    if (!*T) exit(OVERFLOW);
    (*T) -> data = ch;
    printf("data=%c\n", (*T)->data);
    CreateBiTree(&((*T)->lchild));   /* 构造左子树 */
    CreateBiTree(&((*T)->rchild));   /* 构造右子树 */
  }
}
// AB#D##C##   前序
// #B#D#A#C#   中序
// ###DB##CA   后序
```


## ch9 查找

### 9.3 哈希表

刷PAT的时, 1005, 1029, 1033, 1038, 1039, 1042, 1043, 1047, 1083都涉及到有很多`Hash散列`的方法, 因此, 先把哈希表给学了。

参考《大话数据结构》8.9, 8.10, 8.11, 8.12, 8.13,(顺便说一下, 我在京东买的《数据结构》9.3这里竟然是空白页..)

#### 8.9 散列表查找(哈希表)概述

要解决的问题:是否能不通过"比较"来找到元素, 能否直接通过关键字key得到要查找记录的内存存储位置?

```
存储位置=f(key)
```
散列技术是在记录的存储位置和它的关键字之间, 建立一个确定的对应关系.

用散列技术, 将记录存储在一块连续的存储空间中, 存储空间成为`散列表`或者`哈希表`(Hash Table)

散列表与之前的数据结构区别:
> * 散列表既是一种存储结构, 也是一种查找方法;(面向查找的存储结构)
> * 之前的数据结构, 元素之间存在着逻辑关系, 可以用连线图表示, 而散列技术记录之间不存在什么逻辑关系,  只与关键词有关

散列表最适合的求解问题:
> * 查找与给定值相等的记录

散列技术中的关键问题: 
> * 设计一个简单, 均匀, 存储利用率高的散列函数
> * 散列冲突

散列冲突(collision): 两个关键字key1 != key2, 但却有f(key1) = f(key2), 成为这个散列函数的同义词(synonym)

#### 8.10 散列函数的构造方法
好的散列函数:
> 1. 计算简单: 散列函数的计算时间不应该超过其他查找技术与关键字比较的时间
> 2. 散列地址分布均匀: 散列地址均匀, 减少为处理冲突而耗费时间

##### 8.10.1 直接的定址法
取某个关键字的某个线性函数值为散列地址
```cpp
f(key) = a * key + b;(a.b 为函数)
```
例如:统计90后出生年份人数, f(key) = key - 1980

优点:
> * 这个样的散列函数简单, 均匀, 也不会产生冲突
缺点:
> * 需要预先知道关键字的分布情况, 适合查找表较小且连续的情况.

##### 8.10.2 数字分析法
抽取方法是使用关键字的一部分来计算散列存储位置和方法.
```cpp
1596833 | 3523
1596833 | 2348
1594342 | 1023
```
适合处理关键字位数比较大的情况, 如果市县知道关键的分布, 且关键字的若干位分布比较均匀, 就可以考虑用这个方法。

##### 8.10.3 平方取中法 
数字开平方之后取中间3位
```cpp
1234 -> ^2 -> 1522756 -> 227
4321 -> ^2 -> 18671041 -> 671
```
适合于不知道关键字的分布, 而数位又不是很大的情况。

(why?难道不会造成冲突吗？)

##### 8.10.4 折叠法

将数按散列表长n分成几个段, 每一段数字求和后, 取后n位得到地址
```cpp
9876543210
987|654|321|0, 987+654+321+0=1962, 后3位962
```

如果这样还不能保证分布均匀, `从一端向另外一端来回折叠后对齐相加`
```cpp
789+654+123+0 = 1566, 后3位566
```

##### 8.10.5 除留余数法
最常用的构造散列函数方法
```cpp
f(key) = key mod p(p <= m)
```

f(key) = key mod 12
```sh
下标   | 0  1   2   3   4   5   6   7  8   9   10 11
关键字 | 12 25  38  15  16  29  78  67 56  21  22  47
```

f(key) = key mod 12
```sh
下标   | 0  0   0   0   0
关键字 | 12 24  36  48  60
```
凉凉。

这个时候p选11, 只有12和144有冲突, 会好很多。

一个经验：
**若散列表表长为m, 通常p为小于或等于表长(最好接近m)的最小质数或不包括小于20质因子的合数**

##### 8.10.6 随机数法

当关键字的长度不等时, 用这个方法比较合适。
```cpp
f(key) = random(key)
```

random是随机函数。

关键字是字符串, 英文.中文.符号, 都可以转化为某种数字来对象, 比如ascii码, 或者Unicode码等.

##### 8.10.7 小结

构造散列函数的考虑因素:
> * 1, 计算散列地址所需要的时间
> * 2, 关键字的长度
> * 3, 散列表的大小
> * 4, 关键字的分布情况
> * 5, 记录查找的频率

#### 8.11 处理散列冲突的方法

散列函数不可能完美, 因此要考虑如何处理.

散列函数, key1 != key2, 但是却有f(key1) = f(key2), 这就是冲突.

<span style="color:red">(在学构造散列函数的时候, 总是给出了问题, 但不知道用计算机如何来解决, 这里的处理方法, 应该就是让计算机算法来解决冲突, 得到一张新散列表。 这里的疑惑是, 散列表是否可能不存在冲突呢？)</span>
##### 8.11.1 开放定址法

###### 线性探测法
```cpp
fi(key) = (f(key) + di) mod M, (di = 1, 2, 3, ..., m-1)
```

如果mod的是12, f(48)与f(12)在0位置上冲突, 检查(f(48)+1) mod 12是不是冲突, 如果冲突, 可以一直检测下去, 直到找到一个合理的位置, 如果不冲突的话, 就插入

堆积:
> * 如果48和37这种本来都不是同义词却需要争夺一个地址的情况, 称为堆积

###### 二次探测法
堆积情况多了, 无论存入还是查找都会降低效率。

可以考虑双向寻找..

增加平方运算的目的为了不让关键字都聚集在某一个区域.

```cpp
fi(key) = (f(key) + di) mod M (di = 1^2, -1^2, 2^2, -2^2..q^2, -q^2, q<=m/2)
```

###### 随机探测法

在冲突时, 对于位移量di采用随机函数计算得到。

随机如何获得相同的地址?
> * 伪随机, 设置的随机种子相同, 则不断调用随机函数可以生成不会重复的数列, 保证相同的fi得到相同的散列地址

```cpp
fi(key) = (f(key) + di) mod M (di是一个随机数列)
```

###### 开放定址法小节
在表未满时, 都能找到不发生冲突的地址, 常用解决冲突的方法
