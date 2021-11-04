#include<bits/stdc++.h>
using namespace std;
void InsertSort(int a[], int len){
	int i, j;
	for(i=2; i<=len; ++i){
		a[0] = a[i];
		for(j=i-1; a[0]<a[j]; j--){
			a[j+1] = a[j];
		}
		a[j+1] = a[0];
	}
}

//ÕÛ°ë²åÈëÅÅÐò£¨ÓÅ»¯£©
void InsertSort2(int a[], int n){
	int i, j, low, high, mid;
	for(i=2; i<=n; ++i){
		a[0] = a[i];
		low = 1; high = i-1;
		while(low <= high){
			mid = (low+high)/2;
			if(a[0]<a[mid]) high = mid-1;
			else low = mid + 1;
		}
		for(j = i-1; j>=high+1; --j){
			a[j+1] = a[j];
		}
		a[j+1] = a[0];
	}
}

void ShellSort(int a[], int len){
	int i, j, dk;
	for(dk=len/2; dk>=1; dk/=2){
		for(i=dk+1; i<=len; ++i){
			if(a[i] < a[i-dk]){
				a[0] = a[i];
				for(j=i-dk; j>0 && a[j]>a[0]; j-=dk){
					a[j+dk] = a[j];
				}
				a[j+dk] = a[0];
			}
		}
	}
}










void shellsort(int a[], int len){
	int i, j, dk;
	for(dk=len/2; dk>=1; dk/=2){
		for(i=dk+1; i<=len; ++i){
			if(a[i] < a[i-dk]){
				a[0] = a[i];
				for(j=i-dk; j>0 && a[j]>a[0]; j-=dk){
					a[j+dk] = a[j];
				}
				a[j+dk] = a[0];
			}
		}
	} 
}
int main(void){
	int len;
	scanf("%d", &len);
	int a[len+1];
	for(int i=1; i<=len; ++i){
		scanf("%d", &a[i]);
	}
	ShellSort(a, len);
	for(int i=1; i<=len; ++i){
		printf("%d ", a[i]);
	}
	cout << endl; 
	return 0;
}

