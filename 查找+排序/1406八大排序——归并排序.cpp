#include<bits/stdc++.h>
using namespace std;
const int N = 101;
//二路归并排序 

int *B = (int *)malloc(sizeof(int)*N);
void MergeSort(int A[], int low, int high){
	if(low < high){
		int mid = (low + high) / 2, i, j, k;
		MergeSort(A, low, mid);
		MergeSort(A,  mid+1, high);
		//归并两个序列
		for(i=low; i<=high; i++){//使用帮助数组A[N]辅助排序 
			B[i] = A[i]; 
		} 
		for(i=low, j=mid+1, k=low; i<=mid&&j<=high; ++k){
			if(B[i]>B[j])//注意，这里不能写=号，不然会不稳定 
				A[k] = A[j++];
			else
				A[k] = B[i++]; 
		}
		while(i<=mid) A[k++] = B[i++];
		while(j<=high) A[k++] = B[j++];
	}
}

int main(void){

	return 0;
}

