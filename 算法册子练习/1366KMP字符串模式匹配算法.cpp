#include<bits/stdc++.h>
using namespace std;
#define MAXSTRLEN 100
typedef char SString[MAXSTRLEN+2];

void InputString(SString str){
	//读取字符串
	scanf("%s", str + 1);//首先用scanf读取字符串
	str[0] = strlen(str+1); 
}

void get_next(SString T, int *next){
	int i = 1;
	next[1] = 0;
	int j = 0;
	while(i < T[0]){
		if(j == 0 || T[i] == T[j]){
			++i, ++j;
			next[i] = j;
		}else
			j = next[j];
	}
}

int Index_KMP(SString S, SString T, int pos){
	//利用模式串T的next函数求T在主串S中第pos个字符之后的位置
	int i = pos, j = 1;
	int next[255];
	get_next(T, next);
	while(i<=S[0] && j<=T[0]){
		if(j == 0 || S[i] == T[j]){
			++i, ++j;
		}else j = next[j];
	}
	for(int i=1; i<=T[0]; i++) printf("%d ", next[i]);
	if(j > T[0]) 
		return i - T[0];
	else return 0;
}
int main(void){
	int i;
	SString str, sub;
	for(i=0; i<3; ++i){
		InputString(str);
		InputString(sub);
		printf("\n%d\n", Index_KMP(str, sub, 1));
	}
	
	return 0;
}

