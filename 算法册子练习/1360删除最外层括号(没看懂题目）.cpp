#include<bits/stdc++.h>
using namespace std;
string solve(string s){
	stack<int> st;
	string ans;
	for(int i=0; i<s.size(); ++i){
		if(s[i] == '('){//�����ǰΪ������ 
			if(st.size()) ans += s[i];//ջ�����Ѿ����������ˣ�����������Ų��ֽܷ��ˣ������
			st.push(i);//���������±���ջ 
		}
		else{
			st.pop();//�ȳ�ջ
			if(st.size()) ans += s[i];//ֻҪջ�л���Ԫ�أ���ô���Ͳ�������������ţ��������� 
		} 
	}
	return ans; 
}


int main(void){
	string s;
	while(cin >> s) cout << solve(s) << endl;

	return 0;
}

