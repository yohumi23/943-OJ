#include<bits/stdc++.h>
using namespace std;
const int N =101;
bool vis[N][N];
int m, n;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {0, 1, -1, 1, -1, 0, 1, -1};
char mp[N][N];//��ͼ
void dfs(int x, int y){//��ǰ���ʵ�x,y�� 
	vis[x][y] = 1;
	for(int i = 0; i < 8; ++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		//�õ���������
		if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny]  &&  mp[nx][ny] == '@' ) {
			//���жϱ߽緶Χ
			dfs(nx, ny); //�������ڵ����� 
		}
	} 
} 
void dfsTraval(){
	int i, j, cnt = 0;
	memset(vis, 0, sizeof(vis));//��������ʼ��������
	for(i = 0; i < m; ++i){
		for(j = 0; j < n; ++j){
			if(!vis[i][j] && mp[i][j]=='@'){
				dfs(i, j);//����˵����ǰ��ͨͼ������� 
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
}

int main(void){
	int i;
	while(~scanf("%d%d", &m, &n)){
		if(n==0&&m==0) break;
		for(i = 0; i < m; ++i){
			scanf("%s", mp[i]);
		}
		dfsTraval();
	
	
	}
	return 0;
}

