#include<bits/stdc++.h>
using namespace std;
void find(string s){
	int i, n = s.size();
	vector<int> a(n);//�洢�����±�
	stack<int> st;//���±�
	for(i=0; i<n; ++i){
		if(s[i]=='(') st.push(i); 
		else{
			a[st.top()] = i+1;//�ҵ������ŵĶ�Ӧ�±�
			st.pop(); 
		} 
	} 
	for(i=0; i<n; ++i){
		if(a[i]!=0) printf("%d %d\n", i+1, a[i]);//����±�
		//���ﲻ����0��ԭ����vector<int> Ĭ�ϳ�ʼԪ����0 
	}
}

int main(){
	string s;
	while(cin >> s){
		find(s);
	}
	return 0;
}
