#include<bits/stdc++.h>
using namespace std;

int main(void){
	string s;
	stack<char> s1, s2;
	cin >> s;
	for(int i=0; i<s.size(); ++i) {
		if(!s1.empty() && s1.top() == s[i]){
			s1.pop();
		}
		else s1.push(s[i]);
	}
	while(!s1.empty()){
		s2.push(s1.top());
		s1.pop();
	}
	while(!s2.empty()){
		printf("%c", s2.top()) ;
		s2.pop();
	}
	return 0;
}

