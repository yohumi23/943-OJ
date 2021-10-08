#include<bits/stdc++.h>
using namespace std;
queue<int> q[10];//队列数组0~9 
int A[100005];
void Collect(int A[]);
void Distribute(int A[], int n, int b);
int main(void){
	int n, amax = -1e9;
	scanf("%d", &n);
	for(int i=0; i<n; ++i) {
		scanf("%d", &A[i]);
		amax = max(A[i], amax);
	}
	int b = 1;
	while(amax){
		Distribute(A, n, b);//分配
		Collect(A);//收集
		amax /= 10;
		++b; 
	}
	for(int i=0; i<n; ++i){
		printf("%d ", A[i]);
	}
	printf("\n");
		
	return 0;
}

void Distribute(int A[], int n, int b){//b代表对第几位进行排序
	int mod = 1;//1， 10， 100 
	while(--b){
		mod *= 10;
	} 
	for(int i=0; i<n; i++){
		q[A[i]/mod%10].push(A[i]);//把数字各位存入对应队列 
	}
}
void Collect(int A[]){
	int loc = 0;
	for(int i=0; i<10; ++i){
		while(!q[i].empty()){
			A[loc++] = q[i].front();
			q[i].pop();
		}
	}
} 

