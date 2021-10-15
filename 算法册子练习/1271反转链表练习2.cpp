#include<bits/stdc++.h>
using namespace std;
struct LNode{
	int val;
	LNode *next;
	LNode (){}
	LNode(int x) : val(x), next(NULL) {}
}; 

LNode* reverseBetween(LNode *head, int l, int r){
	LNode *preL = NULL, *L = NULL, *sufR = NULL, *q, *H = new LNode;
	int flag = 0, c = 1;
	if(l==1) flag = 1;
	for(LNode *p=head; p!=NULL;c++){
		if(c==l-1) preL = p;
		else if(c==l) {
			L = p;
			flag = 1;	
		}
		else if(c==r+1){
			sufR = p;	
			flag = 0;
		} 
		if(flag){
			q = p->next;
			p->next = H->next;
			H->next = p;
			p = q;
		}else p = p->next;
		
	}
	L->next = sufR;
	if(preL){
		preL->next = H->next;
		return head;
	}else return H->next;
}
void print(LNode *x){
	printf("%d ", x->val);
	if(x->next) print(x->next);
} 
int main(void){
	int n, L, R, v;
	scanf("%d%d%d", &n, &L, &R);
	LNode *head = new LNode, *p = head;
	for(int i=1; i<=n; ++i){
		scanf("%d", &v);
		p->next = new LNode(v);
		p = p->next;
	}
	print(reverseBetween(head->next, L, R));
	cout << endl;
	return 0;
}

