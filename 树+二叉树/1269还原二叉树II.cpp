#include<bits/stdc++.h>
using namespace std;
typedef struct BiTNode{
	int data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTNode *CreateBiTreeByInAndPost(int in[], int l1, int r1, int post[], int l2, int r2);
void PreOrder(BiTree T);
int main(void){
	int n;
	int in[105], post[105];
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		scanf("%d", &in[i]);
	} 
	for(int i=0; i<n; ++i){
		scanf("%d", &post[i]);
	}
	BiTNode *T = CreateBiTreeByInAndPost(in, 0, n-1, post, 0, n-1);
	PreOrder(T);
	return 0;
}

BiTNode *CreateBiTreeByInAndPost(int in[], int l1, int r1, int post[], int l2, int r2){
	if(l1>r1 || l2>r2)
		return NULL;
	BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = post[r2];//根结点的构建 
	int i;
	for(i=l1; i<r1; ++i){
		if(post[r2] == in[i])
			break;	
	}
	p->lchild = CreateBiTreeByInAndPost(in, l1, i-1, post, l2, l2+i-1-l1);
	p->rchild = CreateBiTreeByInAndPost(in, i+1, r1, post, l2+i-l1, r2-1);
	return p;
}

void PreOrder(BiTree T){
	if(T){
		printf("%d ", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
