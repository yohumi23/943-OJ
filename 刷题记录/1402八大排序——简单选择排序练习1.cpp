#include<bits/stdc++.h>
using namespace std;
void SelectSort(int a[], int len){
	int i, j, minIndex;
	for(i=1; i<len; ++i){
		minIndex = i;//最小下标初始赋为i
		for(j=i+1; j<=len; ++j){//选出[i,n]的最小值
			if(a[minIndex] > a[j]) 
				minIndex = j;
		} 
		if(minIndex != i){//如果i不是最小下标，就将两个值进行交换 
			swap(a[i], a[minIndex]);
		}
	}
}
int main(void){
	int n;
	scanf("%d", &n);
	int a[n+1];
	for(int i=1; i<=n; ++i)
		scanf("%d", &a[i]);
//	InsertSort2(a, n);
	SelectSort(a, n);
	for(int i=1; i<=n; ++i)
		printf("%d ", a[i]);
	cout << endl;
	return 0;
}

