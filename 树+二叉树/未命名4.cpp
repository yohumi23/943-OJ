#include<bits/stdc++.h>
using namespace std;

typedef struct BiTNode{
	int data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTNode *Create(){
    int data;
    scanf("%d", &data);
    if(data==-1) return NULL;
    BiTNode *T = new BiTNode;
    T->lchild = Create();
    T->rchild = Create();
    return T;
}
int diameter = 0;
int Diameter(BiTree T){
    if(!T) return 0;
    int ld = Diameter(T->lchild);
    int rd = Diameter(T->rchild);
    diameter = (ld + rd) > diameter ? (ld + rd) : diameter;
    return (ld > rd ? ld : rd) + 1;
}

int main(void){
    BiTNode *T = Create();
    Diameter(T);
    cout << diameter << endl;
	return 0;
}

