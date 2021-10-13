#include<bits/stdc++.h>
using namespace std;
const int N = 1011;
char str[N];
int c, a[N];
int getnum(){
	int t = 0;
	while(str[c] != '\0' && isdigit(str[c])){
		t = t * 10 + str[c] - '0';
		c++;
	}
	return t;
}

int main(void){
	while(scanf("%s", str) != EOF){
		int sign = 1, n = 0;
		c = 0;
		if(str[c] == '-') sign = -1, c++;
		while(str[c] != '\0'){
			int num1 = getnum();
			while(str[c] != '\0' && (str[c] == '*' || str[c] == '/')){
				char op = str[c++];
				int num2 = getnum();				
				if(op == '*') num1 *= num2;
				else if(op == '/') num1 /= num2;
			}
			a[n++] = num1*sign;
			if(str[c] == '+') sign = 1;
			else if(str[c] == '-') sign = -1;
			else break;
			c++;
		}
		int ans = 0;
		for(int i=0; i<n; ++i)
			ans += a[i];
		printf("%d\n", ans);
	}
	return 0;
}

