#include<bits/stdc++.h>
using namespace std;
//�ؼ�����ÿ�����ջ�ռ� 
int main(void){
	string s;
	stack<char> st;
	while(cin >> s){
		while(!st.empty()) st.pop();
		for(int i=0; i<s.size(); ++i){
			if(s[i] == ')' && !st.empty() && st.top() == '(') st.pop();
			else if(s[i] == ']' && !st.empty() && st.top() == '[') st.pop();
			else if(s[i] == '}' && !st.empty() && st.top() == '{')	st.pop();
			else st.push(s[i]);
		}
		if(st.empty()) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}

