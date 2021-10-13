#include<bits/stdc++.h>
using namespace std;

int main(void){
	string s;
	stack<int> st; 
	while(cin >> s){
		int n = s.length();
		vector<int> pos(n);
		for(int i=0; i<n; ++i){
			if(s[i] == '(') st.push(i);
			else if(!st.empty() && s[i] == ')'){
				pos[st.top()] = i;
				st.pop();
			}
		} 
		for(int i=0; i<n; ++i){
			if(pos[i] != 0) printf("%d %d\n", i+1, pos[i] + 1); 
		}
	}
	return 0;
}

