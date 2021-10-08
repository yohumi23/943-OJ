#include<bits/stdc++.h>
using namespace std;

void BuildMaxHeap(int A[], int n){
	for(int i=n/2; i>0; i--){
		Adjust(A, n, i);
	}
}
void Adjust(int A[], int n, int k){//kָ����Ҫ�����ĸ���� 
	A[0] = A[k];//�ݴ�A[k] 
	for(int i = 2*k; k<=n; i*=2){
		if(i<n && A[i+1]>A[i]) 
			++i;
		if(A[0] > A[i]) break;
		else{
			A[k] = A[i];
			k = i;//��Ҫ�����ĵ�����i 
		}
	}
	A[k] = A[0];
}
void HeapSort(int A[], int n){
	BuildMaxHeap(A, n);
	for(int i=n; i>1; i--){
		swap(A[i], A[1]);
		Adjust(A, i-1, 1);//ʣ���i-1��Ԫ�� 
	}
}
int main(void){
	
	return 0;
}

