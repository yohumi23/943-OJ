#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int main(void){
	string s;
	bool del[N];
	memset(del, 0, sizeof(del));
	stack<int> st;
	cin >> s;
	for(int i=0; i<s.length(); ++i){
		if(s[i] == '('){
			st.push(i);
		}
		else if(s[i] == ')'){
			if(st.empty()) del[i] = 1;
			else st.pop();
		}
	}
//	cout << st.size() << endl;
	while(!st.empty()){//这里是多余的左括号，没匹配成功的
		del[st.top()] = 1;
		st.pop();
	}
	for(int i=0; i<s.length(); ++i)
		if(!del[i]) cout << s[i];
	return 0;
}

