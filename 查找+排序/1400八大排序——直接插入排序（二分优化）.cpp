#include<bits/stdc++.h>
using namespace std;

void InsertSort(int a[], int n){
	int i, j, l, r, mid;
	for(i=2; i<=n; ++i){
		a[0] = a[i];
		l = 1, r = i - 1;
		while(l<=r){
			mid = (l + r) / 2;
			if(a[mid] > a[0]) r = mid - 1;
			else l = mid + 1;
		}
		for(j=i-1; j>=r+1; --j){
			a[j+1] = a[j];
		}1]
		a[r+1] = a[0];
	} 
	for(i=1; i<=n; ++i){
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
	InsertSort(a, n);
	return 0;	
}

