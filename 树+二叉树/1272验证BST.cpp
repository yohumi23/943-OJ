#include<bits/stdc++.h>
using namespace std;
typedef struct BSTNode{
	int data;
	BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

BSTNode *Create(void){
	int data;
	scanf("%d", &data);
	if(data == -1) return NULL;
	BSTNode *p = new BSTNode;
	p->data = data;
	p->lchild = Create();
	p->rchild = Create();
	return p;
}

bool isBST(BSTree T, int l, int r){
	if(T==NULL) return true;
	if(T->data <= min(l, r) || T->data >= max(l, r)) return false;
	bool lok = isBST(T->lchild, l, T->data);
	bool rok = isBST(T->rchild, T->data, r);
	return  lok&&rok;
}
int main(void){
	BSTNode *root = Create();
	bool flag = isBST(root, -999, 999);
	if(flag) cout << "true" << endl;
	else cout << "false" << endl;
	return 0;
}

