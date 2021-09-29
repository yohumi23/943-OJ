#include<bits/stdc++.h>
using namespace std;
//pipi的油田 
const int N = 101;
char mp[N][N];//存储输入的矩阵 
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {1, -1, 0, 1, -1, 1, -1, 0};
int fa[N*N];//并查集
int get(int x){
	return x==fa[x]? x : fa[x] = get(fa[x]);
} 
int main(void){
	int n, m, i, j;
	while(~scanf("%d %d", &n, &m)){
		if(n==0 && m==0) break;
		for(i = 0; i < n; ++i){
			scanf("%s", mp[i]);
		}
		int count = m*n;
		for(i = 0; i < count; ++i) fa[i] = i;
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				if(mp[i][j] == '*') count--;
				else{
					for(int k = 0; k < 8; ++k){
						int nowj = j + dx[k];
						int nowi = i + dy[k];
						if(nowj>=0 && nowj<m && nowi>=0 && nowi<n && mp[nowi][nowj] == '@'){
							int fx = get(fa[i*m + j]);
							int fy = get(fa[nowi*m + nowj]);
							if(fx != fy){
								count--;
								fa[fx] = fy;
							}
						}
					}
				}
			}
		}
		printf("%d\n", count);
		
	}
	return 0;
}

