#include<bits/stdc++.h>
using namespace std;
int main(void){
	stack<char> st;
	string s;
	int v[300];
	v['+'] = v['-'] = 1, v['*'] = v['/'] = 2, v['^'] = 3;
	cin >> s;
//	cout << s.length() << endl;
	for(int i=0; i<s.length(); ++i){
		if(s[i]>='a' && s[i]<='z') printf("%c", s[i]);
		else if(s[i] == '(') st.push(s[i]);
		else if(s[i] == ')'){
			while(st.top() != '('){
				printf("%c", st.top());
				st.pop();
			}
			st.pop();
		} 
		else{
			while(!st.empty() && st.top()!='(' && v[s[i]]<= v[st.top()]){
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
	printf("\n");
	return 0;
}

