#include<bits/stdc++.h>
using namespace std;

int main(void){
	string s;
	stack<int> st;
	while(cin>>s){
		for(int i=0; i<s.size(); ++i){
			if(s[i]=='(') st.push(i);
			else if(s[i]==')'){
				int l = st.top();
				st.pop();
				int r = i;
				reverse(s.begin() + l, s.begin() + r + 1);
			}
		}
		string ans;
		for(int i=0; i<s.size(); ++i){
			if(s[i] != '(' && s[i]!=')') ans += s[i];
		}
		cout << ans << endl;
	} 
	return 0;
}

