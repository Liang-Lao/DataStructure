#include <stdio.h> 

#define MaxSize 50
typedef struct{
	int data[MaxSize];			//顺序表元素 
	int length;					//顺序表当前长度 
}SqList;						//顺序表类型定义


//基本操作——初始化一个顺序表 
void InitList(SqList L){
    int i;
    for (i = 0; i < MaxSize; i++)
        L.data[i]=0;
	L.length=0;
}

int main()
{
    int j;
    SqList L;
    InitList(&L);
    //printf("Hello World!");
    for (j = 0; j < L.length; j++)
        printf("data[%d]=%d\n", j, L.data[j]);
    return 0;
}