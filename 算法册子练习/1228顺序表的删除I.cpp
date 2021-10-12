#include<bits/stdc++.h>
using namespace std;
int Del_x(int *L, int n, int x){
	int slow = 0;
	for(int fast=0; fast<n; ++fast){
		if(L[fast] != x){
			L[slow++] = L[fast];
		}
	}
	return slow;
}
int main(void){
	int n, x;
	int L[100];
	scanf("%d%d", &n, &x);
	for(int i=0; i<n; ++i){
		scanf("%d", &L[i]);
	}
	int length = Del_x(L, n, x);
	for(int i=0; i<length; ++i){
		printf("%d ", L[i]);
	}
	printf("\n");
	return 0;
}

