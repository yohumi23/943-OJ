#include<bits/stdc++.h>
using namespace std;
const int N = 101;
struct MGraph {
	int vexnum;
	int arcs[N][N];
};

void topSort(MGraph G){
	int n = G.vexnum, i, j;
	vector<int> id(n);
	for(i=0; i<n; ++i) id[i] = 0;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			if(G.arcs[i][j]) id[j]++;
		}
	}
	stack<int> st;
	for(i=0; i<n; ++i){
		if(id[i]==0){
			st.push(i);
		}
	}
	while(!st.empty()){
		int p = st.top();
		printf("%d ", p);
		st.pop();
		id[p]--;
		for(i=0; i<n; ++i){
			if(G.arcs[p][i]){
				id[i]--;
				if(id[i]==0){
					st.push(i);
				}
			}
		}
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
	printf("\n");
	return 0;
}

