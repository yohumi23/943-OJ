#include<bits/stdc++.h>
using namespace std;
void HeadAdjust(int a[], int k, int len);
//建立大根堆
void MaxHeap(int a[], int len){
	for(int i=len/2; i>0; --i){
		HeadAdjust(a, i, len);
	}
}

void HeadAdjust(int a[], int k, int len){
	a[0] = a[k];
	for(int i=k*2; i<=len; i*=2){
		if(i<len && a[i]<a[i+1]) i++;
		if(a[0]>=a[i]) break;
		else{
			a[k] = a[i];
			k = i;
		}
	}
	a[k] = a[0];

}

void HeapSort(int a[], int len){
	MaxHeap(a, len);
	for(int i=len; i>1; i--){
		swap(a[i], a[1]);
		HeadAdjust(a, 1, i-1);
	}
}
int main(void){
	int n;
	scanf("%d", &n);
	int a[n+1];
	for(int i=1; i<=n; ++i)
		scanf("%d", &a[i]);
	HeapSort(a, n);
	for(int i=1; i<=n; ++i)
		printf("%d ", a[i]);
	cout << endl;
	return 0;
}

