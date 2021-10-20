#include<bits/stdc++.h>
using namespace std;
typedef struct BiTNode{
	int data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

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
int diameter = 0;
int Diameter(BiTree T){
	if(T==NULL) return 0;
	int ld = Diameter(T->lchild);
	int rd = Diameter(T->rchild);
	diameter = diameter < (ld + rd) ? (ld+rd) : diameter;
	return (ld>rd?ld:rd)+1;
}
int main(void){
	BiTree T;
	T = Create();
	Diameter(T);
	printf("%d\n", diameter);
	return 0;
}

