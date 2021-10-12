#include<bits/stdc++.h>
using namespace std;
struct Term{
	int exp;
	float coef;
	Term *next;		
}*Polynomial;
void Insert(Polynomial &L, int e, float c){
	Term *p = L->next, pre = L;
	while(p){
		if(p->exp > e){
			pre = p;
			p = p->next;
		}
	}
	if(p->exp == e){
		p->coef = p->coef + c;
		if(p->coef == 0){
			pre->next = p->next;
			free(p);
		}
	}else{
		Term *q = new Term;
		q->exp = e;
		q->coef = c;
		q->next = p;
		pre->next = q; 
	}
}

int main(void){
	Term *LA = new Term, Term *LB = new Term;
	int lengthA, lengthB;
	scanf("%d%d", &lengthA, &lengthB);
	for(int i=0; i<lengthA; ++i){
		int exp, coef;
		scanf("%d%d", &exp, &coef);
		Insert(L, exp, coef);
	}
	for(int i=0; i<lengthB; ++i){
		int exp, coef;
		scanf("%d%d", &exp, &coef);
		Insert(LB, exp, coef);
	}
	while(lengthA){
		while(lengthB--){
			pb = LB->next;
			Insert(LA, pb->exp, pb->coef);
		}
	}
	Term *p = LA->next;
	while(p){
		printf("%d %d\n", p->exp, p->coef);
	}
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

