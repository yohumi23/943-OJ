#include<bits/stdc++.h>
using namespace std;

int main(void){
	string s;
	stack<char> st;
	cin >> s;
	for(int i=0; i<s.length(); ++i){
		if(!st.empty() && st.top() == s[i]) st.pop();
		else st.push(s[i]);
	} 
	stack<char> st1;
	while(!st.empty()){
		st1.push(st.top());
		st.pop();
	}
	while(!st1.empty()){
		printf("%c", st1.top());
		st1.pop();
	}
	printf("\n");
	return 0;
}

