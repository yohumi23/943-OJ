#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
bool del[N];
int main(void){
	stack<int> st;
	string s;
	cin >> s;
	memset(del, 0, sizeof(del));
	for(int i=0; i<s.size(); ++i){
		if(s[i] == '('){
			st.push(i);
		}
		else {
			if(st.empty())del[i] = 1;
			else st.pop();
		}
	}
	while(!st.empty()){
		del[st.top()] = 1;
		st.pop();
	}
	for(int i=0; i<s.size(); ++i){
		if(!del[i]) printf("%c", s[i]);
	}
	return 0;
}

