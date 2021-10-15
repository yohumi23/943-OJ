#include<bits/stdc++.h>
using namespace std;

int main(void){
	string s;
	stack<char> st;
	cin >> s;
	int v[300];
	v['+'] = v['-'] = 1, v['*'] = v['/'] = 2, v['^'] = 3;
	for(int i=0; i<s.size(); ++i){
		if(s[i]>='a'&&s[i]<='z') printf("%c", s[i]);
		else if(s[i] == '(') st.push(s[i]);
		else if(s[i] == ')'){
			while(!st.empty() && st.top() != '('){
				printf("%c", st.top());
				st.pop();
			}
			st.pop();
		}
		else{
			while(!st.empty() && st.top()!='(' && v[st.top()]>=v[s[i]]) {
				printf("%c", st.top());
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while(!st.empty()){
		printf("%c", st.top());
		st.pop();
	}
	return 0;
}

