#include<bits/stdc++.h>
using namespace std;
void find(string s){
	int i, n = s.size();
	vector<int> a(n);//存储括号下标
	stack<int> st;//存下标
	for(i=0; i<n; ++i){
		if(s[i]=='(') st.push(i); 
		else{
			a[st.top()] = i+1;//找到左括号的对应下标
			st.pop(); 
		} 
	} 
	for(i=0; i<n; ++i){
		if(a[i]!=0) printf("%d %d\n", i+1, a[i]);//输出下标
		//这里不等于0的原因是vector<int> 默认初始元素是0 
	}
}

int main(){
	string s;
	while(cin >> s){
		find(s);
	}
	return 0;
}
