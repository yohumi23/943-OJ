#include<bits/stdc++.h>
using namespace std;
struct LNode{
	int data;
	LNode *next;
	LNode(){}
	LNode(int x) : data(x), next(NULL){}
};
LNode *reverse(LNode *head, int m, int n){
	LNode *preL = NULL, *L = NULL, *sufR = NULL, *H = new LNode, *q;
	int flag = 0, c = 1;
	if(m==1) flag = 1;
	for(LNode *p = head; p; c++){
		if(c==m-1) preL = p;
		else if(c==m) {
			flag = 1;
			L = p;
		}
		else if(c==n+1) {
			//flag = 1;
			flag = 0;
			sufR = p;
		}
		if(flag){
			q = p->next;
			p->next = H->next;
			H->next = p;
			p = q;
		}
		else p = p->next;
	} 
	L->next = sufR;
	if(preL){
		preL->next = H->next;
		return head;
	}else{
		return H->next;
	}
}

void print(LNode *head){
	printf("%d ", head->data);
	if(head->next) print(head->next);
}
int main(void){
//	int n, L, R, v;
//	LNode *head = new LNode, *r = head;
//	scanf("%d%d%d", &n, &L, &R);
//	for(int i=0; i<n; ++i){
//		scanf("%d", &v);
//		r->next = new LNode(v);
//		r = r->next;
//	}
//	print(reverse(head->next, L, R));
//	
	int n, L, R, v;
	scanf("%d%d%d", &n, &L, &R);
	LNode *head = new LNode, *p = head;
	for(int i=1; i<=n; ++i){
		scanf("%d", &v);
		p->next = new LNode(v);
		p = p->next;
	}
	print(reverse(head->next, L, R));
	return 0;
}

