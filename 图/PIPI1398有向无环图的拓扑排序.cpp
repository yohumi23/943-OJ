#include<bits/stdc++.h>
using namespace std;
const int N = 51;
struct MGraph{
	int vexnum;
	int arcs[N][N];
};
//先求出所有点的入度，然后将每个入度为0的结点入栈
//当栈不为空时，取出栈顶元素，将与该点相邻的结点入度减1
//如果入度减为0，就加入栈中，如果最后已排序的点数小于图的顶点数
//就说明有环 
void topSort(MGraph G){
	int i, j, n = G.vexnum;
	stack<int> s;
	vector<int> id(n);//入度数组indegree 
	for(i=0; i<n; ++i){//入度记录 
		for(j=0; j<n; ++j){
			if(G.arcs[i][j]) id[j]++;
		}
	}
	for(i=0; i<n; ++i){
		if(id[i] == 0) s.push(i);//把入度为0的点入栈 
	}
	vector<int> ans;//记录排序的点
	while(!s.empty()) {
		int x = s.top();
		s.pop();
		id[x]--;//避免x重复入栈，入度为负，相当于标记
		ans.push_back(x);//记录
		for(i=0; i<n; ++i) {
			if(G.arcs[x][i]){
				id[i]--;
				if(id[i] == 0) s.push(i);
			}
		}
	}
	if(ans.size()<n) puts("ERROR");//图中还有剩余的点，必有环，输出ERROR
	else{
		for(i=0; i<n; ++i){
			printf("%d ", ans[i]);
		}
	} 
}
int main(void){
	int n;
	MGraph G;
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

