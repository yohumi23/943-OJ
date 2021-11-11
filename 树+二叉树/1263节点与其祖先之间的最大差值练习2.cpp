#include<bits/stdc++.h>
#define MAXSIZE 101
using namespace std;
typedef struct BiTNode{
	int data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTNode *Create(void){
	int data;
	scanf("%d", &data);
	if(data == -1) return NULL;
	BiTNode *p = new BiTNode;
	p->data = data;
	p->lchild = Create();
	p->rchild = Create();
	return p;
}
BiTNode *stk[MAXSIZE];
int top = -1;
int MaxDifference(BiTree T){
	if(T){
		stk[++top] = T;
		int max = -999, tmp;
		BiTNode *p = T, *r = NULL;
		while(p || top>=0){
			if(p){
				stk[++top] = p;
				p = p->lchild;
			} 
			else{
				p = stk[top];
				if(p->rchild != NULL && p->rchild != r){
					p = p->rchild;
				}
				else{
					for(int i=top-1; i>=0; i--){
						if((tmp = abs(stk[i]->data - stk[top]->data)) > max){
							max = tmp;
						}
					}
					top--;
					r = p;
					p = NULL;
				}
			}
		}
		return max;
	}
}
int main(void){
	BiTree root = Create();
	cout << MaxDifference(root) << endl;
	return 0;
}

