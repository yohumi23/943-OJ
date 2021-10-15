#include<bits/stdc++.h>
using namespace std;

typedef struct BiTNode{
	int data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
BiTNode *Create(void){
	int data;
	scanf("%d", &data);
	if(data == -1){
		return NULL;
	}
	BiTree T = (BiTNode *)malloc(sizeof(BiTree));
	T->data = data;
	T->lchild = Create();
	T->rchild = Create();
	
	return T; 
}

void Create2(BiTNode *&T){
	int data;
	scanf("%d", &data);
	if(data == -1){
		T = NULL;
		return;
	}
	T = (BiTNode*)malloc(sizeof(BiTNode));
	T->data = data;
	Create2(T->lchild);
	Create2(T->rchild); 
}
int main(void){
	Create();
	return 0;
}

