#include<bits/stdc++.h>
using namespace std;
bool vis[10];
int res[9];
void fullalignment(int n, int k){
	if(k == n) {
		for(int i=0; i<n; ++i) printf("%d ", res[i]);
		printf("\n");
	}
	for(int i=n; i>0; i--){
		if(!vis[i]){
			vis[i] = 1;
			res[k] = i;
			++k;
			fullalignment(n, k);
			--k;
			vis[i] = 0;
		}
		
	}
}
int main(void){
	int n;
	while(cin >> n){
		memset(vis, 0, sizeof(vis));
		fullalignment(n, 0);
	} 
	return 0;
}

