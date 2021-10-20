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

int res = 0;
void getMaxDifference(BiTree T, int max, int min){
	if(T==NULL) return;
	if(T->data > max)
		max = T->data;
	if(T->data < min)
		min = T->data;
	if(max-min > res) res = max - min;
	getMaxDifference(T->lchild, max, min);	
	getMaxDifference(T->rchild, max, min);
}

int main(void){
	BiTree T = Create();
	int max = -999, min = 999;
	getMaxDifference(T, max, min);
	cout << res << endl;
	return 0;
}
