/*
8.����һ���Թ���ͼ���õ�ͼ��ʶ���Թ�������λ�����꣬����
֪�Թ���λ�ô���״̬��Ϣ�����ô���ǽ����·���ƶ�����Ϊ�����ϣ�������4������
�����һ�����ݽṹ���Թ����д洢��������㷨������������Թ������һ������ڵ����ڵ�ͨ·��
��ó�û��ͨ·�Ľ���
*/

//��һ���ַ�����洢�Թ�������'-'��ʾ·�� '#'��ʾǽ
 
#include<bits/stdc++.h>
using namespace std;
const int N = 101;
char Maze[N][N];//�ַ�����洢�Թ� 
bool vis[N][N] = {false};//�������飬trueΪ�ѷ���
int m, n;//������m�У�n��
int travel[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
typedef struct pos{
	int x, y;//��¼���� 
}pos; 
//pos path[N];��Ŀ���ˣ�Ҫ�ܺ������еĵ㣬���룡���� 
pos path[N*N];
int cnt = 0;
//�β�Ҳд�������� 
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

