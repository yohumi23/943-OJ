#include<bits/stdc++.h>
using namespace std;
const int N = 101;
typedef struct BiTNode{
	int data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
BiTNode *CreateBiTreebyPreAndIn(int pre[], int l1, int r1, int in[], int l2, int r2){
	if(l1>r1 || l2>r2)
		return NULL;
	BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
	p->data = pre[l1];
	int i;
	for(i=l2; i<=r2; ++i){
		if(in[i] == pre[l1])
			break;
	}
	p->lchild = CreateBiTreebyPreAndIn(pre, l1+1, l1+i-l2, in, l2, i-1);
	p->rchild = CreateBiTreebyPreAndIn(pre, l1+i-l2+1, r1, in, i+1, r2);
	return p; 
}

void PostOrder(BiTree T){
	if(T){
		PostOrder(T->lchild); 
		PostOrder(T->rchild); 
		printf("%d ", T->data);
	}
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
	PostOrder(CreateBiTreebyPreAndIn(pre, 0, n-1, in, 0, n-1));
	return 0;
}

