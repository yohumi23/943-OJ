#include<bits/stdc++.h>
using namespace std;
void BubbleSort(int a[], int n){
	for(int i=0; i<n-1; i++){
		bool flag = false;
		for(int j=n-1; j>i; j--){
			if(a[j-1] > a[j]){
				swap(a[j-1], a[j]);	
				flag = true;
			}
		}
		if(!flag) break;
	}
}
int main(void){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i=0; i<n; ++i){
		scanf("%d", &a[i]);
	} 
	BubbleSort(a, n);
	    for(int i=0; i<n; ++i){
    	printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
