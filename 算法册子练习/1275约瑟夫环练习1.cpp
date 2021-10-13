#include<bits/stdc++.h>
using namespace std;
struct node{
	int id;
	node *pre, *next;
	node(int x) : id(x), pre(NULL), next(NULL) {}
};
int main(void){
	int N, K;
	scanf("%d%d", &N, &K);	
	node *now, *p, *last;
	now = new node(1);
	last = now;
	for(int i=2; i<=N; ++i){
		p = new node(i);
		now->next = p;
		p->pre = now;
		now = p;
	}
	now->next = last;
	last->pre = now;
	while(last->next != last){
		for(int i=0; i<K-1; ++i) last = last->next;
		last->pre->next = last->next;
		last->next->pre = last->pre;
		last = last->next;
	}
	printf("%d", last->id); 

	return 0;
}

