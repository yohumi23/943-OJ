#include<bits/stdc++.h>
using namespace std;

bool Del_Min(int *L, int n, int &x){
	if(n==0) return false;
	int min = L[0], j = 0;
	for(int i=0; i<n; ++i){
		if(L[i] < min){
			min = L[i];
			j = i;
		}
	}
	x = min;
	L[j] = L[n-1];
	return true;
}
void traval(int *L, int n){
	for(int i=0; i<n; ++i) printf("%d ", L[i]);
	printf("\n");
}

int main(void){
	int L[100];
	int n; 
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		scanf("%d", &L[i]);
	}
	int x;
	bool flag = Del_Min(L, n, x);
	if(flag){
		printf("%d\n", x);
		for(int i=0; i<n-1; ++i){
			printf("%d ", L[i]);
		}
		printf("\n");
	}else printf("error");
}
