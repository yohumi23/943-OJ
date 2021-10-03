#include<bits/stdc++.h>
using namespace std;
const int N = 51;
struct MGraph{
	int vexnum;
	int arcs[N][N];
};
//��������е����ȣ�Ȼ��ÿ�����Ϊ0�Ľ����ջ
//��ջ��Ϊ��ʱ��ȡ��ջ��Ԫ�أ�����õ����ڵĽ����ȼ�1
//�����ȼ�Ϊ0���ͼ���ջ�У�������������ĵ���С��ͼ�Ķ�����
//��˵���л� 
void topSort(MGraph G){
	int i, j, n = G.vexnum;
	stack<int> s;
	vector<int> id(n);//�������indegree 
	for(i=0; i<n; ++i){//��ȼ�¼ 
		for(j=0; j<n; ++j){
			if(G.arcs[i][j]) id[j]++;
		}
	}
	for(i=0; i<n; ++i){
		if(id[i] == 0) s.push(i);//�����Ϊ0�ĵ���ջ 
	}
	vector<int> ans;//��¼����ĵ�
	while(!s.empty()) {
		int x = s.top();
		s.pop();
		id[x]--;//����x�ظ���ջ�����Ϊ�����൱�ڱ��
		ans.push_back(x);//��¼
		for(i=0; i<n; ++i) {
			if(G.arcs[x][i]){
				id[i]--;
				if(id[i] == 0) s.push(i);
			}
		}
	}
	if(ans.size()<n) puts("ERROR");//ͼ�л���ʣ��ĵ㣬���л������ERROR
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

