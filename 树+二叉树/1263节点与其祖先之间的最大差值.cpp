#include<bits/stdc++.h>
using namespace std;
typedef struct BiTNode{
	int data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
BiTNode *stk[105];
int top;
BiTNode *Create(void){
	int data;
	scanf("%d", &data);
	if(data == -1) return NULL;
	BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = data;
	p->lchild = Create();
	p->rchild = Create();
	return p;
}
//void PreOrder(BiTree T){
//	if(T){
//		printf("%d ", T->data);
//		PreOrder(T->lchild);
//		PreOrder(T->rchild);
//	}
//}

int GetMaxDifference(BiTree T){
	BiTNode *p = T, *r = NULL;
	int max = -1, m = 0;
	top = -1;
	while(top!=-1 || p){
		if(p){
			stk[++top] = p;
			p = p->lchild; 
		}
		else{
			p = stk[top];
			if(p->rchild!=NULL && p->rchild!=r){
				p = p->rchild;
			}
			else{
//				for(int i=top; i>=0; --i){
//					printf("%d\n", stk[i]->data);
//				}
				for(int i=top-1; i>=0; --i){
					m = abs(stk[i]->data - stk[top]->data);
					if(m > max) max = m;
				}
				--top;
				r = p;
				p = NULL;
			}
		}
	}
	return max;

}


int res = 0;
void getMaxDifference(BiTree T, int max, int min){
	if(T==NULL) return;
	if(T->data > max)
		max = T->data;
	if(T->data < min)
		min = T->data;
	if(max-min > res) res = max - min;
	getMaxDifference(T->lchild, max, min);	
	getMaxDifference(T->rchild, max, min);
}


int main(void){
	BiTree T = Create();
//	PreOrder(T);
	cout << GetMaxDifference(T) << endl;
	int max = -999, min = 999;
	getMaxDifference(T, max, min);
	cout << res << endl;
	return 0;
}

