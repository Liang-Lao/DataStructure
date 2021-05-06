#include <stdio.h> 
#include <stdlib.h>

#define MaxSize 10              //定义最大长度
typedef struct{
	int data[MaxSize];          //用静态“数组”存放元素 
	int length;                 //顺序表当前长度 
}SqList;                        //顺序表类型定义

//！！！！！假设初始初始长度为6
//顺序表的基本操作——初始化
void InitList(SqList &L){
    for (int i = 0; i < MaxSize; i++)
        L.data[i]=0;            //将所有数据元素设置为默认的初始值
    L.length = 6;               //顺序表初始长度为0
}

//顺序表的基本操作——插入
bool ListInsert(SqList &L,int i,int e){
    if (i < 1 || i > L.length + 1)      //判断i的范围是否有效
        return false;
    if (L.length >= MaxSize)            //当前空间已满，不能插入
        return false;
    for (int j = L.length; j >= i; j--) //将第i个元素及之后的元素后移
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;                  //在位置i处放入e
    L.length++;                         //长度+1
    return true;
}

//顺序表的基本操作——删除
bool ListDelete(SqList &L,int i,int &e){
    if (i < 1 || i > L.length )         //判断i的范围是否有效
        return false;
    e = L.data[i-1];                    //将被删除的元素赋值给e
    for (int j = i; j < L.length; j++)  //将第i个位置后的元素前移
        L.data[j - 1] = L.data[j];
    L.length--;                         //线性表长度减1
    return true;
}

//顺序表的基本操作——按位查找
int GetElem(SqList L,int i){
    return L.data[i - 1];       //和访问普通数组一样
}

//顺序表的基本操作——按值查找
int LocateElem(SqList L,int e){
//在顺序表L中查找第一个元素值等于e的元素，并返回其位序
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)     //数组下标为i的元素值等于e，返回其位序i+1
            return i + 1;       //退出循环，说明查找失败
    return 0;
}

int main()
{
    SqList L;                   //声明一个顺序表
    InitList(L);                //初始化顺序表
    /*printf("_________打印经过初始化后的元素___________\n");
        //！！！Maxsize访问方式不太友好，应使用L.length
    for (int j = 0; j < MaxSize; j++)
        printf("data[%d]=%d\t%p\n", j, L.data[j], &L.data[j]);*/

    printf("本次查找的元素为%d\n", GetElem(L, 4));

    ListInsert(L, 4, 1);        //在数组第4个位置插入元素1
    /*printf("_设L.length=6__在数组第4个位置插入元素1___\n");
    for (int j = 0; j < L.length; j++)
        printf("data[%d]=%d\t%p\n", j, L.data[j], &L.data[j]);*/
    
    printf("本次查找的元素位序为%d\n", LocateElem(L, 1));

    int e = 6;                  //用变量e把删除的元素“带回来”
    if(ListDelete(L, 3, e))     //删除数组的第3个元素
        printf("已删除第3个元素，删除元素值为=%d\n", e);
    else
        printf("位序i不合法，删除失败\n");
    /*printf("_________删除数组第3个位置的元素1_________\n");
    for (int j = 0; j < L.length; j++)
        printf("data[%d]=%d\t%p\n", j, L.data[j], &L.data[j]);*/

    return 0;
}