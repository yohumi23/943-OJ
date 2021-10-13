#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
char str[N];
int a[N];
int c;
int getnum(){
	int ret = 0;
	while(str[c]!='\0' && isdigit(str[c])){
		ret = ret * 10 + str[c] - '0';
		c++;
	}
	return ret;
}

int main(void){
	while(scanf("%s", str) != EOF){
		int sign = 1, id = 0;
		c = 0;
		if(str[c] == '-') c++, sign = -1;
		while(str[c] != '\0'){
			int num1 = getnum();//获得第一个数字
			while(str[c] != '\0' && (str[c] == '*' || str[c] == '/')) {//先处理乘除法 ,这个while是连续计算的意思 
				char op = str[c++];//获得表达式
				int num2 = getnum();//获得第二个数字
				if(op == '*')  num1 *= num2;//计算乘法
				else num1 /= num2;//计算除法 
			}
			a[id++] = sign*num1;//加上符号
			if(str[c] == '-')  sign = -1;//转入下一步（判断是加还是减）
			else if(str[c] == '+') sign = 1;
			else break;
			c++; 
		}
		int ans = 0;
		for(int i=0; i<id; ++i) ans += a[i];
		printf("%d\n", ans);
	}
	return 0;
}

