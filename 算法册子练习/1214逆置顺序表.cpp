#include<bits/stdc++.h>
using namespace std;
void reverse(int *L, int n){
	int front = 0, rear = n-1;
	int tmp;
	while(front < rear){//������Ѳ��ȺŸĳ���С�ںž�ͨ���ˣ���֪��why?????? 
		tmp = L[front];
		L[front] = L[rear];
		L[rear] = tmp;
		front++;
		rear--;
	}
}
int main(void){
	int L[100];
	int n; 
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		scanf("%d", &L[i]);
	}
	reverse(L, n);
	for(int i=0; i<n; ++i){
		printf("%d ", L[i]);
	}
	printf("\n");
	return 0;
}

