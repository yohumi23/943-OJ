#include<bits/stdc++.h>
using namespace std;
bool vis_col[10], ld[20], rd[20];
int ans = 0;


void dfs(int row){
	if(row == 8) {
		ans++;
		return;
	}
	for(int col = 0; col < 8; col++){
		if(vis_col[col] == 0 && ld[row + col] == 0 && rd[col - row + 8 - 1] == 0){
			vis_col[col] = ld[row+col] = rd[col-row+8-1] = 1;
			dfs(row+1);
			vis_col[col] = ld[row+col] = rd[col-row+8-1] = 0;//»ØËÝ 
		}
	}
}

 
int main(void){
	dfs(0);
	cout << ans << endl;//92ÖÖ 
	return 0;
}

