#include <stdio.h>
#include <stdlib.h>

#define InitSize 10             //默认最大长度
typedef struct{
    int *data;                  //指示动态分配数组的指针
    int MaxSize;                //顺序表的最大容量
    int length;                 //顺序表当前长度
} SeqList;

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
    SeqList L;                  //声明一个顺序表
    InitList(L);                //初始化顺序表o
    //尝试打印原data数组
    for (int i = 0; i < L.MaxSize; i++)
        printf("data[%d]=%10d\t%p\n", i, L.data[i], &L.data[i]);
    printf("__________________\n");
    IncreaseSize(L, 5);
    //尝试打印添加长度后的data数组
    for (int j = 0; j < L.MaxSize; j++)
        printf("data[%d]=%10d\t%p\n", j, L.data[j], &L.data[j]);
    return 0;
}