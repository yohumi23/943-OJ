#include<bits/stdc++.h>
using namespace std;

int main(void){
	string s;
	stack<char> st;
	int v[300];
	v['+'] = v['-'] = 1, v['*'] = v['/'] = 2, v['^'] = 3;
	cin >> s;
	for(int i=0; i<s.size(); ++i){
		if(s[i]>='a' && s[i]<='z') printf("%c", s[i]);
		else{
			while(!st.empty() && v[st.top()]>=v[s[i]]){
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

