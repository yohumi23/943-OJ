#include<bits/stdc++.h>
using namespace std;

typedef struct Term{
	float coef;
	int exp;
	Term *next;
}*List, Term;
typedef List Polynomial;
void Insert(Polynomial &L, float c, int e){
	List pre = L, p = L->next;
	while(p!=NULL && p->exp < e){
		pre = p;
		p = p->next;
	}
	if(p!=NULL && e == p->exp){
        if(p->coef + c != 0) p->coef += c;
        else{
            pre->next = p->next;
            free(p);
        }
	}
	else{
		Term* t = new Term;//t要取地址！！！ 
		t->coef = c;
		t->exp = e;
		pre->next = t;
		t->next = p;
	}
}

void MUL(Polynomial &A, Polynomial &B, Polynomial &C){
//	List pa = La;
//	while(pa){
//		List pb = Lb;
//		while(pb){
//			Insert(pa, pb->coef, pb->exp);
//			pb = pb->next;
//		} 
//		pa = pa->next;
//	}
	Term *pa, *pb;
	C = new Term;
	C->next = NULL;
	pa = A->next;
	while(pa != NULL){
		pb = B->next;
		while(pb){
			Insert(C, pa->coef * pb->coef,  pa->exp + pb->exp);
			pb = pb->next;
		}
		pa = pa->next;
	}
} 

int main(void){
	Polynomial LA = new Term, LB = new Term;
	LA->next = NULL, LB->next = NULL; 
	int n, m, expn;
	float coef;
	scanf("%d", &m);
	//scanf("%d", &n);
	for(int i=0; i<m; ++i){
		scanf("%d", &expn);
		scanf("%f", &coef);
		Insert(LA, coef, expn);
	}
	Term *p = LA->next;
	while(p){
		printf("%d %f\n", p->exp, p->coef);
		p = p->next;
	}
	return 0;
}

