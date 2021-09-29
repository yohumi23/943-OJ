#include<bits/stdc++.h> 
#define inf 99999
using namespace std;
const int N = 101;

struct MGraph{
	int vexnum;//���� 
	int arcs[N][N];//�ڽӾ��� 
};

struct LGraph{
	int vexnum;//���� 
	vector<int> vertices[N];//�ڽӱ� 
};

//����ķ�㷨 
void Prim(MGraph G){
	int i, n = G.vexnum;//j���� 
	vector<int> d(n);//����ǰ���ϵ�ʣ���ľ���
	vector<int> v(n);//��Ƿ������� 
	for(i = 1; i < n; ++i) d[i] = G.arcs[0][i];//��ʼʱ��ǰ���ϣ�����ʱ����ֻ��0��
	v[0] = 1;//����һ�����ν��뵱ǰ���� 
	int ans = 0; 
	for(int k = 1; k < n; ++k){
		int j = 0, m = inf;//j����Ѱ�ҵıߵĶ˵㣬m����ǰ��С���� 
		for(i = 0; i < n; ++i){
			if(!v[i] && d[i] < m){
				m = d[i];//m��Խ��ԽС��ֱ���ﵽ��Сֵ������ͬʱ��¼��������С���� 
				j = i;//��¼���뵱ǰ���Ͼ�����С�ĵ� 
			}
		}
		ans += m;//ѡ�иñߣ����ӻ���
		v[j] = 1;//����Ѿ�����
		//��Ҫ���µ�ǰ���ϵ����������С���� 
		for(i = 0; i < n; ++i){
			if(!v[i] && d[i] > G.arcs[j][i]){
				d[i] = G.arcs[j][i];
			}
		} 
	} 
	printf("%d", ans);
}
int main(){
	MGraph G;
	int i, j, n;
	scanf("%d", &n);
	G.vexnum = n;
	for(i = 0; i < n; ++i){
		for(j = 0; j < n; ++j){
			scanf("%d", &G.arcs[i][j]);
			if(G.arcs[i][j]==0) G.arcs[i][j] = inf;
		}
	}	
	Prim(G);
	
	return 0;
}
