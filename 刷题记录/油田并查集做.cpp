#include<bits/stdc++.h>
using namespace std;
const int N = 101;
/**
不要把get()里的while写成if 

*/ 
char mp[N][N];
int fa[N*N];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {1, -1, 0, 1, -1, 1, -1, 0};
int get(int x){
	while(x != fa[x]) x = fa[x];//这里是while不是if 
	return x;
}
int main(void){
	int n, m;
	int i, j;
	while(~scanf("%d %d", &n, &m)){
		if(n==0 && m==0) break;
		for(i=0; i<n; ++i){
			scanf("%s", mp[i]);
		}
		int amount = m*n;
		for(int i=0; i<amount; ++i){
			fa[i] = i;
		} 
		for(i=0; i<n; ++i){
			for(j=0; j<m; ++j){
				if(mp[i][j] == '*') amount--;
				else{
					for(int k=0; k<8; ++k){
						int nx = i + dx[k];
						int ny = j + dy[k];
						if(nx>=0 && nx<n && ny>=0 && ny<m && mp[nx][ny]=='@'){
							int index_1 = get(i*m + j);
							int index_2 = get(nx*m + ny);
							if(index_1 != index_2){
								fa[index_1] = index_2;
								amount--;
							}
						}
					}
				}
			}
		} 
		cout << amount << endl;
	}
	return 0;
}

