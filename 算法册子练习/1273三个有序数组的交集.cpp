#include<bits/stdc++.h>
using namespace std;
const int N = 100005; 
int main(void){
	int n, m, q;
	int i, j, k, f, x;//i,j,k�ֱ�Ϊ�������������ָ�룬xΪ����ָ��ָ��Ԫ�ص���Сֵ
	//f������֤����һ�������Ԫ���⣬֮��ÿ���һ��Ԫ��ǰ�涼��һ���ո� 
	int A[N], B[N], C[N]; 
	scanf("%d%d%d", &n, &m, &q);
	for(i=0; i<n; ++i) scanf("%d", &A[i]);
	for(i=0; i<m; ++i) scanf("%d", &B[i]);
	for(i=0; i<q; ++i) scanf("%d", &C[i]);
	for(f=i=j=k=0; i<n && j<m && k<q;){
		if(A[i] == B[j] && B[j] == C[k]){
			//������ָ��ָ��Ԫ�����
			if(f) printf(" ");
			f = 1, printf("%d", A[i]);
			i++, j++, k++;
		}
		else{
			x = min(A[i], B[j], C[k]);
			if(x==A[i]) i++;
			if(x==B[j]) j++;
			if(x==C[k]) k++;
		}
	}
	printf("\n");
	return 0;
}

