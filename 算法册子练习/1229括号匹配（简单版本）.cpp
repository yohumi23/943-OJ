#include<bits/stdc++.h>
using namespace std;
string s;
stack<char> st;
//��Ҫ��ȷ���ǣ�ջ�в������һ�����ţ����־�ʱ�������� 
//���������Ƕ������룬��ÿ��Judge����Ҫ���ջ���������������������������������������������������������������������������������������������������� 
bool judge(string s){
//	while(!st.empty()) st.pop();
	for(int i=0; i<s.size(); ++i){
		if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
		else if(s[i] == ')'){
			if(!st.empty() && st.top() == '(') st.pop();
			else return false;
		}
		else if(s[i] == ']'){
			if(!st.empty() && st.top() == '[') st.pop();
			else return false;
		}	
		else if(s[i] == '}'){
			if(!st.empty() && st.top() == '{') st.pop();
			else return false;
		}	
	}
	if(!st.empty()) return false;
	return true;
}
		

int main(void){
	while(cin >> s){
		if(judge(s)) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}

