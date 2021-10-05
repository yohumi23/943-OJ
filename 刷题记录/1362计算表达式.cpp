#include<bits/stdc++.h>
using namespace std;
int cal(string s){
	stack<char> op;//字符栈存运算符号 
	stack<int> num;//数字栈
	int now = 0;//当前的数字 
	for(int i=0; i<s.size(); ++i){
		if(s[i]>='0' && s[i]<='9') now = now*10 + s[i] - '0';//这一步将字符串转换成数字！！！
		else{
			if(s[i] == '+' || s[i] == '-'){
				while(!op.empty() && )
			}
			
		} 
	} 
	
}
int main(void){

	return 0;
}

