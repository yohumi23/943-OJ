#include<bits/stdc++.h>
using namespace std;
struct node{
	int id;
	node *pre, *next;//ǰ������� 
	node(int x) : id(x) {}
};

int main(void){
	int n, m;
	scanf("%d%d", &n, &m);
	node *head = new node(1), *last = head, *now;//Ϊ�˷��㽨����headΪָ��1�Ľ��
	for(int i=2; i<=n; ++i){//�ӱ��2��n���½��
		now = new node(i);//nowָ��ǰ�����Ľ��
		now->pre = last;//��now��ǰ��ָ��last
		last->next = now;//��last�ĺ��ָ��now
		last = now;//��last��ֵ��now
	}
	head->pre = last;
	last->next = head;//��λ����
	node *p = head;//ͨ��p�����ƶ��������ɾ�����
	while(p->next != p){//p->next = p˵��ֻʣ��һ������� 
		for(int i=0; i<m-1; ++i) p = p->next;//�ƶ�m-1�Σ���1�ƶ�m-1�ξ͵���Ҫ�����Ǹ����� 
		now = p->next;//�Ƚ�Now��ֵΪp->next;�´δ�now��ʼ1��2,3�������� 
		p->pre->next = p->next;
		p->next->pre = p->pre;
		p = now; 
	} 
	printf("%d\n", p->id);
	return 0;
}

