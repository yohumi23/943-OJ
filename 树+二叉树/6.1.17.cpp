#include<bits/stdc++.h>
using namespace std;
typedef struct BiTNode{
	int data;
	BiTNode *lchild, *rchild;
	int count;
}BiTNode, *BiTree;

BiTNode *Create(void){
	int data;
	scanf("%d", &data);
	if(data == -1) return NULL;
	BiTNode *p = new BiTNode;
	p->data = data;
	p->lchild = Create();
	p->rchild = Create();
	return p;
}
void Insert1(BiTree &root, BiTNode *&pre, int x){
	BiTNode *p = root;
	pre = NULL;
	while(p!=NULL){
		if(x != p->data){
			pre = p;
			if(x<p->data) {
				p = p->lchild;
			}
			else{
				p = p->rchild;
			} 
		}
		else {
			p->count++;
			return; 
		} 
	}
	BiTNode *s = new BiTNode;
	s->data = x; s->lchild = NULL; s->rchild = NULL;
	if(pre==NULL) root = s;
	else if(pre->data > x){
		pre->lchild = s;
	}	
	else {
		pre->rchild = s; 
	}
	
} 

int main(void){

	return 0;
}

