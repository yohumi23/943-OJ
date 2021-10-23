#include<bits/stdc++.h>
using namespace std;
const int N = 101;

typedef struct BiTNode{
	int data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
BiTNode *CreateBiTreebyInAndPost(int in[], int l1, int r1, int post[], int l2, int r2){
	if(l1>r1 || l2>r2) return NULL;
	BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
	p->data = post[r2];
	int i;
	for(i=l1; i<=r1; ++i){
		if(in[i] == post[r2])
			break;
	}
	p->lchild = CreateBiTreebyInAndPost(in, l1, i-1, post, l2, l2+i-1-l1);
	p->rchild = CreateBiTreebyInAndPost(in, i+1, r1, post, l2+i-l1, r2-1);
	return p;
} 
void PreOrder(BiTree T){
	if(T){
		printf("%d ", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
int main(void){
	int in[N], post[N];
	int n;
	BiTree T; 
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		scanf("%d", &in[i]);
	}
	for(int i=0; i<n; ++i){
		scanf("%d", &post[i]); 
	}
	T = CreateBiTreebyInAndPost(in, 0, n-1, post, 0, n-1);
	PreOrder(T);
	return 0;
}

