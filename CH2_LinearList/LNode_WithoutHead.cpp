#include <stdio.h>
#include <stdlib.h>

//强调这是一个单链表    ————用LinkList
//强调这是一个结点      ————用LNode *

typedef struct LNode{           //定义单链表结点类型
    int data;                   //（数据域）每个节点存放一个数据元素
    struct LNode *next;         //（指针域）指针指向下一个节点
}LNode,*LinkList;               //"LNode *"等价于"LinkList"
                                //"typedef （struct LNode*）=（LinkList）"

//建立单链表————头插法                每次将s所指节点插在最前端
/*  初始化单链表
    while循环{
        每次取一个数据元素e；
        InsertNextNode（L，e）；
    }
*/

//建立单链表————尾插法                每次将s所指节点插在最末端
/*  初始化单链表
    设置变量length记录链表长度
    while循环{
        每次取一个数据元素e；
        ListInsert（L，length+1，e）；
        length++；
    }
*/

//基本操作————初始化（不带头结点）
bool InitList(LinkList &L){
//初始化一个空的单链表
    L = NULL;                   //空表，暂时还没有任何结点
    return true;
}

//判断单链表是否为空
bool Enpty(LinkList L){
    return true;
}

//基本操作————插入_按位序插入（不带头结点）
bool ListInsert(LinkList &L, int i, int e){
    if (i < 1)
        return true;
    if (i == 1){
    //插入第1个结点的操作与其他结点操作不同
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;                  //头指针指向新结点
        return true;
    }
    LNode *p;                   //指针p指向当前扫描到的结点
    int j = 1;                  //当前p指向的是第几个结点！！！j ≠ 0
    p = L;                      //p指向第1个结点（注意：不是头结点）
    while (p != NULL && j < i - 1){ //循环找到第i-1个结点
        p = p->next;
        j++;
    }
    if (p == NULL)              //i值不合法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;                //插入成功
}

//基本操作————插入__[指定节点后插操作（小模块）]
bool InsertNextNode(LNode *p, int e){
//后插操作：在p结点之后插入元素e
    if (p == NULL)              //内存分配失败
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;                //将结点s连接到p之后
    return true;                //插入成功
}

//基本操作————插入__[指定节点前插操作（小模块）]
bool InsertPrioNode(LNode *p, int e){
//前插操作：在p结点之前插入元素e
    if (p == NULL)
        return true;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)              //内存分配失败
        return false;
    s->next = p->next;
    p->next = s;                //新结点s连接到p之后
    s->data = p->data;          //将p中元素复制到s中
    p->data = e;                //p中元素覆盖为e
    return true;
}

//基本操作————删除_按位序删除（不带头结点）
//！！！！！！！！！！！！！！！！！！！
//还需要修改
//！！！！！！！！！！！！！！！！！！！
bool ListDelete(LinkList &L, int i, int &e){
    if (i < 1)
        return false;
    LNode *p;                   //指针p指向当前扫描到的结点
    int j = 0;                  //当前p指向的是第几个结点
    p = L;                      //L指向头结点，头结点是第0个结点（不存数据）
    while (p != NULL && j < i - 1){ //循环找到第i-1个结点
        p = p->next;
        j++;
    }
    if (p == NULL)              //i值不合法
        return false;
    if (p->next == NULL)        //第i-1个结点之后已无其他结点
        return false;
    LNode *q = p->next;         //令q指向被删除节点
    e = q->data;                //用e返回元素的值
    p->next = q->next;          //将*q结点从链中“断开”
    free(p);                    //释放结点的存储空间
    return true;                //删除成功
}

//基本操作————删除_指定结点删除（带头结点）
bool DeleteNode(LNode *p){
//删除指定节点p
    if (p == NULL)
        return false;
    LNode *q = p->next;         //令q指向*p的后继结点
    /*若q指向空表，下一步翻车*/
    p->data = p->next->data;    //和后继结点交换数据域
    p->next = q->next;          //将*q结点从链中“断开”
    free(p);                    //释放后继结点的存储空间
    return true;
}

//按位查找
//按值查找
//求表长



int main(){
    LinkList L;                 //声明一个指向单链表的！！指针！！
    InitList(L);                //初始化一个空表
    return 0;
}