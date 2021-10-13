#include<bits/stdc++.h>
using namespace std;
string solve(string s){
	stack<int> st;
	string ans;
	for(int i=0; i<s.size(); ++i){
		if(s[i] == '('){//如果当前为左括号 
			if(st.size()) ans += s[i];//栈里面已经有左括号了，那这个左括号不能分解了，加入答案
			st.push(i);//将左括号下标入栈 
		}
		else{
			st.pop();//先出栈
			if(st.size()) ans += s[i];//只要栈中还有元素，那么它就不是最外层右括号，将其加入答案 
		} 
	}
	return ans; 
}


int main(void){
	string s;
	while(cin >> s) cout << solve(s) << endl;

	return 0;
}

