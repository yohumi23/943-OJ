#include<bits/stdc++.h>
using namespace std;
typedef struct BiTNode{
	BiTNode *lchild, *rchild;
	int data;
}BiTNode, *BiTree; 

//构建二叉树
//先序 
BiTNode *Create(void){
	int data;
	scanf("%d", &data);
	if(data == -1){
		return NULL;
	}
	BiTree T = (BiTNode *)malloc(sizeof(BiTNode));
	T->data = data;
	T->lchild = Create();
	T->rchild = Create();
	
	return T;
} 
void PreOrder(BiTree T){
	if(!T) 
		return;
	printf("%d ", T->data);//遍历根结点 
	PreOrder(T->lchild);
	PreOrder(T->rchild);
}
void InOrder(BiTree T){
	if(!T)
		return;
	InOrder(T->lchild);
	printf("%d ", T->data);
	InOrder(T->rchild);
} 

void PostOrder(BiTree T) {
	if(!T)
		return;
	PostOrder(T->lchild);
	PostOrder(T->rchild);
	printf("%d ", T->data);
}

//层序遍历
void LevelOrder(BiTree T){
	queue<BiTNode*> q;
	BiTNode *p = NULL; 
	if(T){
		q.push(T);
		while(!q.empty()){
			p = q.front();
			q.pop();
			printf("%d ", p->data);
			if(p->lchild) q.push(p->lchild);//这里不能用else if，有多少，入多少，不是选择的关系 
			if(p->rchild) q.push(p->rchild); 
		}
	}
	
} 
void PostOrder2(BiTree T){
    stack<BiTree> s;
    BiTNode *p = T, *r = NULL;
    while(p || !s.empty()){
        if(p){
            s.push(p);
            p = p->lchild;
        }
        else{
            p = s.top();//假出栈 
            if(p->rchild && p->rchild != r){
                p = p->rchild;
            }
            else{
            	p = s.top(); 
                s.pop();
                printf("%d ",p->data);
                r = p;
                p = NULL;
            }
        }
    }
}

//后序遍历的非递归实现 
struct element{
	BiTNode *ptr;
    int flag;//取值为1，第一次入栈，取值为2，第二次入栈
}x;
void PostOrder3(BiTree T){
    stack<element> s;
    BiTNode *p = T;
    while(p || !s.empty()){
        if(p){
            x.ptr = p;
            x.flag = 1;
            s.push(x);
            p = p->lchild;
        }
        else{
            x = s.top();
            s.pop();
            p = x.ptr;
            if(x.flag == 1){
                x.flag = 2;
                s.push(x);//第二次入栈
                p = p->rchild;
            }
            else{
                printf("%d ", p->data);
                p = NULL;
            }
        }
    }
}



int main(void){
	BiTree T = Create();
//	LevelOrder(T);
	PostOrder3(T);
	return 0;
}
