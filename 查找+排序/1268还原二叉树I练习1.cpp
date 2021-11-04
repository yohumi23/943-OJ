#include<bits/stdc++.h>
using namespace std;
typedef struct BiTNode{
	int data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
const int N = 101;
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
void PostOrder(BiTree T){
	if(!T) return;
	PostOrder(T->lchild);
	PostOrder(T->rchild);
	printf("%d ", T->data);
}

BiTNode *CreatebyPreAndIn(int pre[], int l1, int r1, int in[], int l2, int r2){
	if(l1>r1 || l2>r2) return NULL;
	BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
	p->data = pre[l1];
	int i;
	for(i=l2; i<=r2; ++i){
		if(in[i] == pre[l1]) break;
	}
	p->lchild = CreatebyPreAndIn(pre, l1+1, i-l2+l1, in, l2, i-1);
	p->rchild = CreatebyPreAndIn(pre, i-l2+l1+1, r2-l2+l1, in, i+1, r2);
	return p;
}
int main(void){
	int n;
	scanf("%d", &n);
	int pre[N], in[N];
	for(int i=0; i<n; ++i){
		scanf("%d", &pre[i]);
	}
	for(int i=0; i<n; ++i){
		scanf("%d", &in[i]);
	}
	BiTNode *T = CreatebyPreAndIn(pre, 0, n-1, in, 0, n-1);
	PostOrder(T);
	return 0;
}

