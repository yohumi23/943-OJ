#include<bits/stdc++.h>
using namespace std;
void InsertSort(int a[], int n){
	int i, j;
	for(i=2; i<=n; ++i){
		if(a[i]<a[i-1]){
			a[0] = a[i];
			for(j=i-1; a[0]<a[j]; --j){
				a[j+1] = a[j];
			}
			a[j+1] = a[0];
		}
	}
	for(int i=1; i<=n; ++i) {
		printf("%d ", a[i]);
	} 
	printf("\n");
}

int main(void){
	int n;
	scanf("%d", &n);
	int a[n+1];
	for(int i=1; i<=n; ++i){
		scanf("%d", &a[i]);
	} 
	InsertSort(a, n);

	return 0;
}

