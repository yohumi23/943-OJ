#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
char str[N];
int a[N];
int c;
int getnum(){
	int ret = 0;
	while(str[c]!='\0' && isdigit(str[c])){
		ret = ret * 10 + str[c] - '0';
		c++;
	}
	return ret;
}

int main(void){
	while(scanf("%s", str) != EOF){
		int sign = 1, id = 0;
		c = 0;
		if(str[c] == '-') c++, sign = -1;
		while(str[c] != '\0'){
			int num1 = getnum();//��õ�һ������
			while(str[c] != '\0' && (str[c] == '*' || str[c] == '/')) {//�ȴ���˳��� ,���while�������������˼ 
				char op = str[c++];//��ñ��ʽ
				int num2 = getnum();//��õڶ�������
				if(op == '*')  num1 *= num2;//����˷�
				else num1 /= num2;//������� 
			}
			a[id++] = sign*num1;//���Ϸ���
			if(str[c] == '-')  sign = -1;//ת����һ�����ж��Ǽӻ��Ǽ���
			else if(str[c] == '+') sign = 1;
			else break;
			c++; 
		}
		int ans = 0;
		for(int i=0; i<id; ++i) ans += a[i];
		printf("%d\n", ans);
	}
	return 0;
}

