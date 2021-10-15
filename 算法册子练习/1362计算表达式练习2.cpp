#include<bits/stdc++.h>
using namespace std;
const int N = 101;
char str[N];
int c, a[N];
int getnum(){
	int ret = 0;
	while(str[c] != '\0' && isdigit(str[c])){
		ret = ret * 10 + str[c] - '0' ;
		c++;
	}
	return ret;
}
int main(void){
	
	while(scanf("%s", str) != EOF){
		c = 0;
		int id = 0, sign = 1;
		if(str[c] == '-') {
			sign = -1;
			c++;
		}
		while(str[c] != '\0'){
			int num1 = getnum();
			while(str[c] != '\0' && (str[c] == '*' || str[c] == '/')){
				char op = str[c++];
				int num2 = getnum();
				if(op == '*') num1 *= num2;
				else if(op == '/') num1 /= num2;
			}
			a[id++] = sign * num1;
			if(str[c] == '+') sign = 1;
			else if(str[c] == '-') sign = -1;
			else break;
			c++;
		}
		int	ans = 0;
		for(int i=0; i<id; ++i){
			ans += a[i];
		}
		printf("%d\n", ans);	
	}
	
	return 0;
}

