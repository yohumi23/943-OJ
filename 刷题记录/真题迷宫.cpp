/*
8.给定一张迷宫地图，该地图标识了迷宫各处的位置坐标，并已
知迷宫各位置处的状态信息，即该处是墙还是路，移动方向为东，南，西，北4个方向。
请设计一个数据结构对迷宫进行存储，并设计算法对任意给定的迷宫，求出一条从入口到出口的通路，
或得出没有通路的结论
*/

//用一个字符数组存储迷宫，其中'-'表示路， '#'表示墙
 
#include<bits/stdc++.h>
using namespace std;
const int N = 101;
char Maze[N][N];//字符数组存储迷宫 
bool vis[N][N] = {false};//访问数组，true为已访问
int m, n;//数组有m行，n列
int travel[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
typedef struct pos{
	int x, y;//记录坐标 
}pos; 
//pos path[N];数目少了，要能涵盖所有的点，起码！！！ 
pos path[N*N];
int cnt = 0;
//形参也写得有问题 
void dfs(Maze M, pos s, pos t){
	vis[s.x][s.y] = 1;
	path[cnt++]  = s;
	if(s.x == t.x && s.y == s.y){
		for(int i=0; i<cnt; ++i){
			printf("%d ", path[i]);
		}
		cnt--;
		vis[s.x][s.y] = 0;
		return;
	}
	for(int i=0; i<4; ++i){
		int nx = s.x + travel[i][0];
		int ny = s.y + travel[i][1];
		if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && Maze[nx][ny] == '-'){
			dfs(Maze, {nx, ny}, t);
		}
		/*	
		cnt--;
		vis[s.x][s.y] = 0; 	
		*/
	}
	cnt--;
	vis[s.x][s.y] = 0;
}
//int main(void){
//	scanf("%d %d", &m, &n);
//	for(int i=0; i<m; ++i){
//		scanf("%s", Maze[i]);
//	}
//	dfs(Maze, {0, 0}, {m-1, n-1});
//	return 0;
//}
void solution(Maze M, pos s, pos t){
	for(int i=0; i<M.m; ++i){
		for(int j=0; j<M.n; ++j){
			vis[i][j] = 0;
		}
	}
	dfs(M, s, t);
	if(!flag) printf("No such path");
}

