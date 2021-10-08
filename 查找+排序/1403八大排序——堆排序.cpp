#include<bits/stdc++.h>
using namespace std;

void BuildMaxHeap(int A[], int n){
	for(int i=n/2; i>0; i--){
		Adjust(A, n, i);
	}
}
void Adjust(int A[], int n, int k){//k指向需要调整的根结点 
	A[0] = A[k];//暂存A[k] 
	for(int i = 2*k; k<=n; i*=2){
		if(i<n && A[i+1]>A[i]) 
			++i;
		if(A[0] > A[i]) break;
		else{
			A[k] = A[i];
			k = i;//需要调整的点变成了i 
		}
	}
	A[k] = A[0];
}
void HeapSort(int A[], int n){
	BuildMaxHeap(A, n);
	for(int i=n; i>1; i--){
		swap(A[i], A[1]);
		Adjust(A, i-1, 1);//剩余的i-1个元素 
	}
}
int main(void){
	
	return 0;
}

