#include<bits/stdc++.h>
using namespace std;
typedef struct ThreadNode{
	int data;
	struct ThreadNode *lchild, *rchild;
	int ltag, rtag;
}ThreadNode, *ThreadTree;


void InThread(ThreadTree *p, ThreadNode *&pre){
	if(p!=NULL){
		InThread(p->lchild, pre);
		if(p->lchild == NULL){
			p->lchild = pre;
			p->ltag = 1;
		}
		if(pre != NULL && pre->rchild == NULL){//pre!=NULL是保证它不是第一个结点的前驱！！ 
			pre->rchild = p;
			p->rtag = 1;
		}
		pre = p;
		inThread(p->rchild, pre);
	}
		
}
void CreateInThread(ThreadTree T){
	ThreadTree pre = NULL;
	if(T!=NULL){
		InThread(T, pre);
		pre->rchild = NULL;
		pre->rtag = 1;
	}
} 
int main(void){

	return 0;
}

