#include<bits/stdc++.h>
using namespace std;
int cal(string s){
	stack<char> op;//�ַ�ջ��������� 
	stack<int> num;//����ջ
	int now = 0;//��ǰ������ 
	for(int i=0; i<s.size(); ++i){
		if(s[i]>='0' && s[i]<='9') now = now*10 + s[i] - '0';//��һ�����ַ���ת�������֣�����
		else{
			if(s[i] == '+' || s[i] == '-'){
				while(!op.empty() && )
			}
			
		} 
	} 
	
}
int main(void){

	return 0;
}

