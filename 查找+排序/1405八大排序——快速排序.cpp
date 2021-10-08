#include<bits/stdc++.h>
using namespace std;

void QuickSort(int A[], int low, int high){
	if(low<high){
		int pivot = A[low], l = low, h = high;
		while(l<r){
			while(l<r && A[r] >= pivot) r--;
			//加 l<r条件，不能让l跑到r的后面 
			A[l] = A[r];
			while(l<r && A[l] <= pivot) l++;
			A[r] = A[l];
		}
		A[l] = pivot;
		Quick(A, low, l-1);
		Quick(A, l+1,high);		
	} 
}


int main(void){
	
	return 0;
}

