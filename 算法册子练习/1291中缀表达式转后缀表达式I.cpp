#include<bits/stdc++.h>
using namespace std;

int main(void){
	stack<char> stk;
	string s;
	int i, v[300];
	v['+'] = v['-'] = 0, v['*'] = v['/'] = 1, v['^'] = 2;
	cin >> s;
	for(i=0; i<s.length(); ++i){
		//����Сд��ĸ����ֱ�����
		if(s[i]>='a' && s[i]<='z') printf("%c", s[i]);
		else{
			//���ǲ������Ҹò��������ȼ�С�ڵ���ջ�����������ȼ�
			//���ջ��Ԫ�أ�֪��ջΪ�ջ��߸ò��������ȼ�����ջ������� 
			while(!stk.empty() && v[s[i]]<= v[stk.top()]){
				printf("%c", stk.top());
				stk.pop();
			}
			stk.push(s[i]);
		}
	}
	while(!stk.empty()){
		printf("%c",  stk.top());
		stk.pop();
	}
	printf("\n");
	return 0;
}

