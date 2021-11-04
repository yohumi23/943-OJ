#include<bits/stdc++.h>
using namespace std;
typedef struct BiTNode{
	int data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void PostOrder(BiTree T){
	if(!T) return;
	BiTNode *p = T, *r = NULL;
	stack<BiTNode*> s;fafdafdafdafdasfdsafdsafdaff
	while(p || !s.empty()){
		if(p){
			s.push(p);
			p = p->lchild;
		}
		else{
			p = s.top();
			if(p->rchild && p->rchild!=r){
				p = p->rchild;
			}
			else{
				s.pop();
				printf("%d ", p->data); 
				r = p;
				p = NULL;
			} 
		}
	}
}
BiTNode *Create(void){
	int data;
	scanf("%d", &data);
	if(data==-1) return NULL;
	BiTNode *T = (BiTNode*)malloc(sizeof(BiTNode));
	T->data = data;
	T->lchild = Create();
	T->rchild = Create();
	return T; 
}
int main(void){
	BiTNode *T = Create();
	PostOrder(T);	
	return 0;
}

