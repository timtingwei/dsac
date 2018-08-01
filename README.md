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

