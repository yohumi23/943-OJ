#include<bits/stdc++.h>
using namespace std;
typedef struct BiTNode{
	int data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
BiTNode *stk[100];
int top = -1;
void find_Ancestor(BiTree T, int x){
	if(!T) return;
	BiTNode *p = T, *r = NULL;
	while(p || top!=-1){
		if(p){
			stk[++top] = p;
			p = p->lchild;
		}
		else{
			p = stk[top];
			if(p->rchild && p->rchild!=r){
				p = p->rchild;
			}
			else{
				if(stk[top]->data == x){
					for(int i=top-1; i>=0; i--){
						printf("%d ", stk[i]->data);
					}	
					break;				
				}
				top--;
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
	find_Ancestor(T, 7);	
	return 0;
}

