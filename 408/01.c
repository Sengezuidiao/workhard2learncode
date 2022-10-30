#include<stdio.h>
#include<stdlib.h>

#define InitSize 100 //表长度的初始定义

typedef bool{
	false,
	true
}bool;


typedef struct {
	ElemType *data;
	int MaxSize, length;
}SqList;
//插入操作
// *L 指针指向结构体，操作地址后面的元素，一级指针无法改变L本身，需二级指针
bool ListInsert(SqList *L, int x)
{
	printf("hello")	
}
int main()
{

	system("chcp 65001");


	return 0;
}
