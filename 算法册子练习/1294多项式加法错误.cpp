#include<bits/stdc++.h>
using namespace std;
typedef struct Term{
	int exp;
	int coef;
	Term *next;		
}*List;
typedef  List Polynomial ;
//void Insert(Polynomial &L, int e, float c){
//	List p = L->next, pre = L;
//	while(p && p->exp > e){
//			pre = p;
//			p = p->next;
//	}
//	if(p->exp == e){
//		p->coef = p->coef + c;
//		if(p->coef == 0){
//			pre->next = p->next;
//			free(p);
//		}
//	}else{
//		Term *q = new Term;
//		q->exp = e;
//		q->coef = c;
//		q->next = p;
//		pre->next = q; 
//	}
//}
void Insert(Polynomial &L, float c, int e){
    //在多项式链表L中插入系数为c，指数为e的新项
    Term * pre = L, *p = L->next; 
    while(p!=NULL && p->exp < e){
        pre = p;
        p = p->next;
    }
    if(p!=NULL && p->exp == e){
        if(p->coef + c != 0) p->coef += c;
        else{
            pre->next = p->next;
            free(p);
        }
    }
    else{
        Term *pc = new Term;
        pc->exp = e, pc->coef = c;
        pre->next = pc;
        pc->next = p;
    }
}

int main(void){
	Polynomial LA = new Term, LB = new Term;
	LA->next = NULL, LB->next = NULL; 
	int lengthA, lengthB;
	int exp;
	float coef;
	scanf("%d%d", &lengthA, &lengthB);
	for(int i=0; i<lengthA; ++i){
		scanf("%d%d", &exp, &coef);
		Insert(LA, coef, exp);
	}
	for(int i=0; i<lengthB; ++i){
		scanf("%d%d", &exp, &coef);
		Insert(LB, coef, exp);
	}
	List pb = LB->next;
	while(pb){
		Insert(LA, pb->exp, pb->coef);
		pb = pb->next;
	}
	Term *p = LA->next;
	while(p){
		printf("%d %d\n", p->exp, p->coef);
		p = p->next;
	}
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

