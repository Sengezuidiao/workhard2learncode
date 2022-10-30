#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 255 //预定义最大串的长度
				   
typedef struct{
	char ch[MAXLEN]; 	//每个分量存储一个字符
	int length;
}SString;

typedef struct{
	char *ch;
	int length;
}HString;

HString S;
//为什么堆区只能声明不能初始化
//S.ch = (char *)malloc(MAXLEN * sizeof(char));
//用完记得free
//S.length = 0;

//朴素模式匹配算法
int Index(SString S, SString T){
	int k;
	int i=k, j=1;
	while(i < S.length && j<=T.length){
		if(S.ch[i]==T.ch[j]){
			++i;
			++j;
		}else{
			k++;
			i=k;
			j=1;
		}
	}
	if(j > k)
		return k;
	else
		return 0;
}

int main()
{
	printf("hello");	
}
