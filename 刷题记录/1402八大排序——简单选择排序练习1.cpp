#include<bits/stdc++.h>
using namespace std;
void SelectSort(int a[], int len){
	int i, j, minIndex;
	for(i=1; i<len; ++i){
		minIndex = i;//��С�±��ʼ��Ϊi
		for(j=i+1; j<=len; ++j){//ѡ��[i,n]����Сֵ
			if(a[minIndex] > a[j]) 
				minIndex = j;
		} 
		if(minIndex != i){//���i������С�±꣬�ͽ�����ֵ���н��� 
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

