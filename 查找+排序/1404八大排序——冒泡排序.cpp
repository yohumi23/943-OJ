#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
void BubbleSort(int A[], int n){
    for(int i=0; i<n-1; ++i){//i是排序好的数字放的位置
    //这里i<n-1或者i<n都能通过，但是书上是i<n-1，原因在于，只需要找到n-1最小的数，那么第n个数自然就排在最后了 
    	bool flag = false;//标记某趟是否交换了元素 
        for(int j=n-1; j>i; --j){
            if(A[j-1]>A[j]){
            	flag = true; 
                swap(A[j-1], A[j]);
            }
        }
        if(!flag) break;
    }
    //还有一种写法
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
