#include<bits/stdc++.h>
using namespace std;

int main(void){
	stack<char> stk;
	string s;
	int i, v[300];
	v['+'] = v['-'] = 0, v['*'] = v['/'] = 1, v['^'] = 2;
	cin >> s;
	for(i=0; i<s.length(); ++i){
		//若是小写字母，则直接输出
		if(s[i]>='a' && s[i]<='z') printf("%c", s[i]);
		else{
			//若是操作符且该操作符优先级小于等于栈顶操作符优先级
			//输出栈顶元素，知道栈为空或者该操作符优先级大于栈顶运算符 
			while(!stk.empty() && v[s[i]]<= v[stk.top()]){
				printf("%c", stk.top());
				stk.pop();
			}
			stk.push(s[i]);
		}
	}
	while(!stk.empty()){
		printf("%c",  stk.top());
		stk.pop();
	}
	printf("\n");
	return 0;
}

