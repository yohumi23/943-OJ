#include<bits/stdc++.h>
using namespace std;
const int N = 101;
struct MGraph{
	int vexnum;
	int arcs[N][N];
};
void topSort(MGraph G){
	int n = G.vexnum, t;
	int path[N], cnt = 0;
	vector<int> id(n);
	for(int i=0; i<n; ++i) id[i] = 0;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(G.arcs[i][j]) id[j]++;
		}
	}
	for(int i=0; i<n; ++i){
		if(id[i] == 0) t = i;
	}
	path[cnt++] = t;
	stack<int> s;
	s.push(t);
	while(!s.empty()){
		int num = 1;
		t = s.top();
		s.pop();
		id[t]--;
		for(int i=0; i<n; ++i){
			if(G.arcs[t][i]) id[i]--;
			s.push(i);
			path[cnt++] = i;
		}
	}
	if(cnt < G.vexnum) printf("ERROR\n");
	else{
		for(int i=0; i<cnt; ++i) printf("%d ", path[i]);
	} 
	putchar('\n');
	
}
int main(void){
	MGraph G;
	int n;
	scanf("%d", &n);
	G.vexnum = n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			scanf("%d", &G.arcs[i][j]);
		}
	}
	topSort(G);
	return 0;
}

