#include <stdio.h>
#include <stdlib.h>

#define InitSize 10             //默认最大长度
typedef struct{
    int *data;                  //指示动态分配数组的指针
    int MaxSize;                //顺序表的最大容量
    int length;                 //顺序表当前长度
} SeqList;

//顺序表的基本操作——初始化
void InitList(SeqList &L){
    //用malloc 函数申请一片连续的存储空间
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;

    //初始化data数组
    for (int n = 0; n < L.MaxSize; n++){
        L.data[n]=n;
        L.length++;
    }
}

//顺序表的基本操作——插入
bool ListInsert(SeqList &L,int i,int e){
    if (i < 1 || i > L.length + 1)      //判断i的范围是否有效
        return false;
    if (L.length >= L.MaxSize)            //当前空间已满，不能插入
        return false;
    for (int j = L.length; j >= i; j--) //将第i个元素及之后的元素后移
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;                  //在位置i处放入e
    L.length++;                         //长度+1
    return true;
}

//顺序表的基本操作——删除
bool ListDelete(SeqList &L,int i,int &e){
    if (i < 1 || i > L.length )         //判断i的范围是否有效
        return false;
    e = L.data[i-1];                    //将被删除的元素赋值给e
    for (int j = i; j < L.length; j++)  //将第i个位置后的元素前移
        L.data[j - 1] = L.data[j];
    L.length--;                         //线性表长度减1
    return true;
}

//顺序表的基本操作——按位查找
int GetElem(SeqList L,int i){
    return L.data[i - 1];       //和访问普通数组一样
}

//顺序表的基本操作——按值查找
int LocateElem(SeqList L,int e){
//在顺序表L中查找第一个元素值等于e的元素，并返回其位序
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)     //数组下标为i的元素值等于e，返回其位序i+1
            return i + 1;       //退出循环，说明查找失败
    return 0;
}

//增加动态数组的长度
void IncreaseSize(SeqList &L,int len){
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++){
        L.data[i] = p[i];           //将数据复制到新区域
    }
    L.MaxSize = L.MaxSize + len;    //顺序表最大长度加 len
    free(p);                        //释放原来的空间
}

//写好注释
//尝试插入和删除代码
int main(){
    SeqList L;                      //声明一个顺序表
    InitList(L);                    //初始化顺序表
    /*printf("__________打印原data数组______________\n");
    for (int i = 0; i < L.MaxSize; i++)
        printf("data[%d]=%10d\t%p\n", i, L.data[i], &L.data[i]);*/
    IncreaseSize(L, 5);             //将数组长度增加5
    /*printf("_______打印添加长度后的data数组________\n");
    for (int j = 0; j < L.MaxSize; j++)
        printf("data[%d]=%10d\t%p\n", j, L.data[j], &L.data[j]);*/
    
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