#include<bits/stdc++.h>
using namespace std;
typedef struct BiTNode{
	int data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

int depth(BiTree T){
	if(!T) return 0;
	int ld = depth(T->lchild);
	int rd = depth(T->rchild);
	return (ld > rd) ? ld : rd + 1; 
}
int diameter = 0;
int Diameter(BiTree T){
	if(!T) return 0;
	int ld = Diameter(T->lchild);
	int rd = Diameter(T->rchild);
	diameter = diameter < (ld + rd) ? (ld+rd) : diameter;
	return (ld>rd?ld:rd) + 1;
	
	
} 
int main(void){
	
	return 0;
}

