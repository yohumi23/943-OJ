#include<bits/stdc++.h>
using namespace std;
const int N = 51;
struct MGraph{
	int vexnum;
	int arcs[N][N];
};
void topSort(MGraph G){
	int n = G.vexnum, t;
	stack<int> s;
	vector<int> id(n);
	vector<int> ans;
	for(int i=0; i<n; ++i) id[i] = 0;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(G.arcs[i][j]) id[j]++;
		}
	}
	for(int i=0; i<n; ++i){
		if(id[i] == 0) s.push(i);//把源点入栈 
	}
	while(!s.empty()){
		t = s.top();
		s.pop();
		id[t]--;
		ans.push_back(t);
		for(int i=0; i<n; ++i){
			if(G.arcs[t][i]){
				id[i]--;
				if(!id[i]) s.push(i);
			}
		}
	}
	if(ans.size() < n) puts("ERROR");
	else{
		for(int i=0; i<n; ++i) printf("%d ", ans[i]);
	} 
	
	
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

