#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
void BubbleSort(int A[], int n){
    for(int i=0; i<n-1; ++i){//i������õ����ַŵ�λ��
    //����i<n-1����i<n����ͨ��������������i<n-1��ԭ�����ڣ�ֻ��Ҫ�ҵ�n-1��С��������ô��n������Ȼ����������� 
    	bool flag = false;//���ĳ���Ƿ񽻻���Ԫ�� 
        for(int j=n-1; j>i; --j){
            if(A[j-1]>A[j]){
            	flag = true; 
                swap(A[j-1], A[j]);
            }
        }
        if(!flag) break;
    }
    //����һ��д��
	for(int i=0; i<n-1; ++i){
		for(int j=n-2; j>=i; j--){
			if(A[j]>A[j+1]) swap(A[j], A[j+1]);
		}
	}
	 
    for(int i=0; i<n; ++i){
    	printf("%d ", A[i]);
	}
	printf("\n");
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
