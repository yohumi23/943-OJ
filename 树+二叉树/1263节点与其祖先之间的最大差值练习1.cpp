#include<bits/stdc++.h>
using namespace std;
typedef struct BiTNode{
	int data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
BiTNode *s[1000];
int top;
BiTNode *Create(){
	int data;
	scanf("%d", &data);
	if(data == -1){
		return NULL;
	}
	BiTNode *T = (BiTNode *)malloc(sizeof(BiTNode));
	T->data = data;
	T->lchild = Create();
	T->rchild = Create();
	return T;
}
//结点与其祖先之间的最大差值 
int Max(BiTree T){
//	if(!T) return 0;
	BiTNode *p = T, *r = NULL;
	top = -1;
	int tmp;
	s[++top] = p;
	int max = -1;	 
	while(p || top >= 0){
		if(p){
			s[++top] = p;
			p = p->lchild;
		}
		else{
			p = s[top];
			if(p->rchild && p->rchild!=r){
				p = p->rchild;
			}
			else{
				for(int i=top-1; i>=0; i--){
					tmp = abs(s[top]->data - s[i]->data);
					if(tmp > max){
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


//递归求解
int res = 0;
void MaxDifference(BiTree &T, int max, int min){
	if(T==NULL) return;
	if(T->data > max) max = T->data;
	if(T->data < min) min = T->data;
	if(max - min > res) res = max - min;
	MaxDifference(T->lchild, max, min);
	MaxDifference(T->rchild, max, min);
		
} 

int main(void){
	BiTNode *T = Create();
	int max = -999, min = 999;
	MaxDifference(T, max, min);
	cout << res << endl; 
	return 0;
}

