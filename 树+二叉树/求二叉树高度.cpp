#include<bits/stdc++.h>
using namespace std;


typedef struct BiTNode{
	int data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTNode *BuildTree(void);
int Depth(BiTree T);
int Depth2(BiTree T);

int main(void){
	BiTree T = BuildTree();
	printf("%d\n", Depth2(T));
	return 0;
}



//构建二叉树 
BiTNode *BuildTree(void){
	int data;
	scanf("%d", &data);
	if(data==-1)
		return NULL;
	BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
	p->data = data;
	p->lchild = BuildTree();
	p->rchild = BuildTree();
	return p; 
}

int Depth(BiTree T){
	if(!T) return 0;
	int ld = Depth(T->lchild);
	int rd = Depth(T->rchild);
	return (ld>rd?ld:rd) + 1;
}

int Depth2(BiTree T){
	if(!T) return 0;
	BiTNode *Q[100];
	int front = -1, rear = -1, depth = 0;
	int last = 0;//代表当前处理的层数的最后一个结点在栈中的下标
	Q[++rear] = T;
	BiTNode *p;
	while(front < rear){
		p = Q[++front];
		if(p->lchild)
			Q[++rear] = p->lchild;
		if(p->rchild)
			Q[++rear] = p->rchild;
		if(front == last){
			depth++;
			last = rear;
		}	
	} 
	return depth;
} 
