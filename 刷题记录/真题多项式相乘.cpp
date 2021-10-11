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
	while(p!=NULL && p->exp > e){
		pre = p;
		p = p->next;
	}
	if(e == p->exp){
		p->coef = c + p->coef;
		if(p->coef == 0) {
			pre->next = p->next;
			free(p);
		}
	}
	else{
		Term* t = new Term;//tÒªÈ¡µØÖ·£¡£¡£¡ 
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

	return 0;
}

