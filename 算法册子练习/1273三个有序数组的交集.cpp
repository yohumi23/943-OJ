#include<bits/stdc++.h>
using namespace std;
const int N = 100005; 
int main(void){
	int n, m, q;
	int i, j, k, f, x;//i,j,k分别为遍历三个数组的指针，x为三个指针指向元素的最小值
	//f用来保证除第一个输出的元素外，之后每输出一个元素前面都有一个空格 
	int A[N], B[N], C[N]; 
	scanf("%d%d%d", &n, &m, &q);
	for(i=0; i<n; ++i) scanf("%d", &A[i]);
	for(i=0; i<m; ++i) scanf("%d", &B[i]);
	for(i=0; i<q; ++i) scanf("%d", &C[i]);
	for(f=i=j=k=0; i<n && j<m && k<q;){
		if(A[i] == B[j] && B[j] == C[k]){
			//若三个指针指向元素相等
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

