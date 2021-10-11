#include<bits/stdc++.h>
using namespace std;
const int N = 101;
const int inf = 99999;
struct MGraph{
	int vexnum;
	int arcs[N][N];
};
void Dijkstra(MGraph G, int s){
	int n = G.vexnum; 
	vector<bool> vis(n);
	vector<int> d(n);
	for(int i=0; i<n; ++i) vis[i] = 0;
	for(int i=0; i<n; ++i) d[i] = G.arcs[s][i];
	vis[s] = 1;
	for(int k=1; k<n; ++k){
		int j, min = inf;
		for(int i=0; i<n; ++i){
			if(!vis[i] && d[i] < min){
				min = d[i];
				j = i;
			}
		}
		
		
		//�����ǰ�����Ҳ���ͨ��δ���ʵ��·���ˣ���ôʣ�µ�·�Ͳ������ˣ�ֱ�ӵ�����ӡ���� 
		if(min == inf){
			for(int i=0; i<n; ++i){
				if(!vis[i]) d[i] = -1;
			}
			break;
		}
		
		
		
		
		vis[j] = 1;
		for(int i=0; i<n; ++i){
			if(!vis[i] && d[i] > G.arcs[j][i] + min){
				d[i] = G.arcs[j][i] + min;
			}
		}
	}
	for(int i=0; i<n; ++i){
		if(i!=s) printf("%d ", d[i]);
	} 
	printf("\n");
	
}
int main(void){
	MGraph G;
	int n, s;//n�Ƕ�����,s�����
	scanf("%d%d", &n, &s);
	G.vexnum = n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			scanf("%d", &G.arcs[i][j]);
			if(i==j) G.arcs[i][j] = 0;
			else if(G.arcs[i][j] == 0){
				G.arcs[i][j] = inf;
			} 
		}
	} 
	Dijkstra(G, s); 
	return 0;
}

