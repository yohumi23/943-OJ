#include<bits/stdc++.h>
using namespace std;
bool vis[15];
int res[15];//用来记录全排列，相当于记录路径 

void FullAlignment(int n, int x){//n表示n排列
	if(x == n)  {
		for(int i=0; i<n; ++i) printf("%d ", res[i]);
		printf("\n");
		return;
	}
	for(int i=n; i>0; i--){
		if(!vis[i]){
			vis[i] = 1;
			res[x] = i;
			++x;
			FullAlignment(n, x);
			vis[i] = 0;
			--x; 
		}
	}
} 

int main(void){
	int n;
	while(~scanf("%d", &n)){
		memset(vis, 0, sizeof(vis));
		FullAlignment(n, 0);
	}
	return 0;
}

