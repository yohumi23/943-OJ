#include<bits/stdc++.h>
using namespace std;
/*
ע�⵽����������У�ÿ�δ����λ������Ӧ�ľ������ϸ�����ģ����һ���ҵ��յ㣬��ʱ�ľ��������̾�
ͬ���������ԭ���������ƶ�����λ����ʹ�õ��ж������в������ǲ���ǽ�ڡ��������߽磬
����һ������û�е��������Ϊ����Ѿ����������λ�ã���˵���Ѿ��и��̵�·���������λ�ã�
��ε������λ�õ�·���Ǹ���ģ������ܵõ����õ����ս⡣
��������������������������������
��Ȩ����������ΪCSDN������_Jason_ZHANG����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/Jason_Ranger/article/details/50768661

*/
const int N = 10;
int maze[N][N];
bool vis[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
struct node{
	int x, y;
};
//��¼��ǰ������һ����� 
struct Road{
	int x, y;
}road[N][N];

void dfs(int x, int y){
	if(x==-1 && y==-1) return;
	dfs(road[x][y].x, road[x][y].y);
	printf("(%d, %d)\n", x, y); 
}
int bfs(){
	memset(vis, 0, sizeof(vis));
	queue<node> q;
	q.push({0, 0});
	vis[0][0] = 1;
	road[0][0].x = -1;
	road[0][0].y = -1;
	while(!q.empty()){
		node now = q.front(); q.pop();
		if(now.x==4 && now.y==4){
			dfs(4, 4);
			return 0;
		}
		node next; 
		for(int i=0; i<4; ++i){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if(nx<0 || nx>=5 || ny<0 || ny>=5 || maze[nx][ny] || vis[nx][ny]) continue;
			next.x = nx, next.y = ny;
			vis[nx][ny] = 1;
			q.push(next);
			road[nx][ny].x = now.x;
			road[nx][ny].y = now.y;
		}
	}
}
int main(void){
	for(int i=0; i<5; ++i){
		for(int j=0; j<5; ++j){
			scanf("%d", &maze[i][j]);
		}
	}
	bfs();
	return 0;
}
