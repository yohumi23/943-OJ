#include<bits/stdc++.h>
using namespace std;
const int N = 101;
string s;
int a[N], c;

int getnum(){
	int ret = 0;
	while(c < s.size() && isdigit(s[c])){
		ret = ret * 10 + s[c] - '0';
		c++;
	}
	return ret;
}
int main(void){
	while(cin >> s){
		c = 0;
		int sign = 1, id = 0;
		if(s[c] == '-') sign = -1, c++;
		while(c < s.size()){
			int num1 = getnum();
			while(c < s.size() && s[c] == '*' || s[c] == '/'){
				char op = s[c++];
				int num2 = getnum();
				if(op == '*') num1 *= num2;
				else if(op == '/') num1 /= num2;
			}
			a[id++] = sign * num1;
			if(s[c] == '-') sign = -1;
			else if(s[c] == '+') sign = 1;
			else break;
			c++;
		}
		int ans = 0;
		for(int i=0; i<id; ++i) ans += a[i];
		printf("%d\n", ans);
	}

	return 0;
}

