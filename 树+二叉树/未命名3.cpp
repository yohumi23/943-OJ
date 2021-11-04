#include<bits/stdc++.h>
using namespace std;
typedef struct BiTNode{
	int data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

int Depth1(BiTree T){
	if(T==NULL) return 0;
	int ld = Depth1(T->lchild);
	int rd = Depth1(T->rchild);
	return (ld > rd) ? (ld+1) : (rd+1);
} 
BiTNode *Create(void){
	int data;
	scanf("%d", &data);
	if(data == -1) return NULL;
	BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = data;//........²»ÄÜ¶ªµô 
	p->lchild = Create();
	p->rchild = Create();
	return p;
}

int Depth2(BiTree T){
    if(!T) return 0;
    BiTNode *Q[100];
    int rear = -1, front = -1, depth = 0;
    int last = 0;
    Q[++rear] = T;
    BiTNode *p;
    while(front < rear){
        p = Q[++front];
        if(p->lchild) Q[++rear] = p->lchild;
        if(p->rchild) Q[++rear] = p->rchild;
        if(last == front){
            last = rear;
            depth++;
        }
    }
    return depth;
}
int main(void){
	BiTNode *T = Create();
	cout << Depth2(T) << endl;
	return 0;
}
