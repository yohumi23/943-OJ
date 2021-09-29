#include<bits/stdc++.h>
using namespace std;
const int N = 101;

struct edge{//�߽�� 
	int x, y;//�˵�
	int w;//Ȩֵ
};
int fa[N];//���岢�鼯
int get(int x){//�Ҹ��� 
	if(x==fa[x]) return x;
	return fa[x] = get(fa[x]);
} 
void Kruskal(vector<edge> e, int n){//����߽���Ѿ��ź��� 
	for(int i = 1; i <= n; ++i) fa[i] = i;//��ʼ�����鼯
	int ans = 0;
	for(int i = 0; i < e.size(); ++i){
		int fx = get(e[i].x);
		int fy = get(e[i].y);
		if(fx != fy){//�������˵�û����ͨ����Ҫ�ϲ� 
			ans += e[i].w;
			fa[fx] = fy;
		}
	} 
	printf("%d\n", ans);
}
int main(void){
	int i, n;
	while(~scanf("%d", &n)) {
		if(n==0) break;
		int m= n*(n-1)/2;//�ߵ����� 
		vector<edge> e(m);
		for(i = 0; i < m; ++i){
			scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);
			int p;
			scanf("%d",&p);
			if(p==1) e[i].w = 0;//����޽� 	
		}
		sort(e.begin(), e.end(), [](edge a, edge b)->bool{return a.w<b.w;});
		//����ʱֻ��дsort(e.begin(), e.end());�ټӸ���Ȩֵ�Ա߽���������
		//����Ĭ�����ź���� 
		Kruskal(e, n);
	}
	
	return 0;
}

