#include<bits/stdc++.h>
using namespace std;
const int N = 101;
//��·�鲢���� 

int *B = (int *)malloc(sizeof(int)*N);
void MergeSort(int A[], int low, int high){
	if(low < high){
		int mid = (low + high) / 2, i, j, k;
		MergeSort(A, low, mid);
		MergeSort(A,  mid+1, high);
		//�鲢��������
		for(i=low; i<=high; i++){//ʹ�ð�������A[N]�������� 
			B[i] = A[i]; 
		} 
		for(i=low, j=mid+1, k=low; i<=mid&&j<=high; ++k){
			if(B[i]>B[j])//ע�⣬���ﲻ��д=�ţ���Ȼ�᲻�ȶ� 
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

