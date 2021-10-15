#include<bits/stdc++.h>
using namespace std;
const int N = 101;
bool vis_col[N], ld[N], rd[N];
int n, ans = 0;
void dfs(int row){
	if(row == n){
		ans++;
		return;
	}
	for(int col=0; col<n; ++col){
		if(!vis_col[col] && !ld[row+col] && !rd[col-row+n-1]){
			vis_col[col] = ld[row+col] = rd[col-row+n-1] = 1;
			dfs(row+1);
			vis_col[col] = ld[row+col] = rd[col-row+n-1] = 0;
		}
	}
}
int main(void){
	scanf("%d", &n);
	dfs(0);
	cout << ans << endl;
	return 0;
}

