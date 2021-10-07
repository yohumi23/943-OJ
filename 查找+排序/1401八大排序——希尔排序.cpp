#include<bits/stdc++.h>
using namespace std;
void ShellSort(int a[], int n){
	int i, j, dk;
	for(dk = n/2; dk>=1; dk/=2){
		for(i=dk+1; i<=n; ++i){
			if(a[i]<a[i-dk]){
				a[0] = a[i];
				for(j=i-dk; a[0]<a[j] && j>=0; j-=dk){
					a[j+dk] = a[j];
				}
				a[j+dk] = a[0];
			}
		}
	}
	for(int i=1; i<=n; ++i){
		printf("%d ", a[i]);
	}
	putchar('\n');
	
}


int main(void){
	int n;
	scanf("%d", &n);
	int a[n+1];
	for(int i=1; i<=n; ++i){
		scanf("%d", &a[i]);
	} 
	ShellSort(a, n);
	return 0;
}

