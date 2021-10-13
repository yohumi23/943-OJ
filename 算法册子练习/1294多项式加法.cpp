#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
	int coef;
	int expn;
	struct Node *next;
}LNode, *poly;

void init(poly &La, poly &Lb){
	La = new LNode;
	Lb = new LNode;
	La->next = NULL;
	Lb->next = NULL;
	int m, n, coef, expn;
	scanf("%d", &m);
	scanf("%d", &n);
	for(int i=0; i<m; ++i){
		scanf("%d", &expn);
		scanf("%d", &coef);
		poly p = new LNode;
		p->next = NULL;
		p->coef = coef;
		p->expn = expn;
		poly L = La;
		while(L->next != NULL && p->expn > L->next->expn){
			L = L->next;
		}
		if(L->next != NULL && L->next->expn == p->expn){
			L->next->coef += p->coef;
		}else{
			p->next = L->next;
			L->next = p; 
		}
	}
	for(int i=0; i<n; ++i){
		scanf("%d", &expn);
		scanf("%d", &coef);
		poly p = new LNode;
		p->next = NULL;
		p->coef = coef;
		p->expn = expn;
		poly L = Lb;
		while(L->next != NULL && p->expn > L->next->expn){
			L = L->next;
		}
		if(L->next != NULL && L->next->expn == p->coef){
			L->next->coef += p->coef;
		}else{
			p->next = L->next;
			L->next = p; 
		}
	}
}

void polyAdd(poly La, poly Lb){
	poly pa = La->next;
	poly pb = Lb->next;
	while(pa != NULL && pb != NULL){
		if(pa->expn == pb->expn){
			if(pa->coef + pb->coef != 0)
				printf("%d %d\n", pa->expn, pa->coef + pb->coef);
			pa = pa->next;
			pb = pb->next;
		}
		else if(pa->expn < pb->expn){
			printf("%d %d\n", pa->expn, pa->coef);
			pa = pa->next;
		}else{
			printf("%d %d\n", pb->expn, pb->coef);
			pb = pb->next;
		}
	}
	while(pa != NULL){
		printf("%d %d\n", pa->expn, pa->coef);
		pa = pa->next;
	}
	while(pb != NULL){
		printf("%d %d\n", pb->expn, pb->coef);
		pb = pb->next;
	}
}
int main(void){
	poly La;
	poly Lb;
	init(La, Lb);
	polyAdd(La, Lb);	
	return 0;
}

