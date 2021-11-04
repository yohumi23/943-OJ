#include<bits/stdc++.h>
using namespace std;
typedef struct ThreadNode{
	int data;
	ThreadNode *lchild, *rchild;
	int ltag, rtag;
}ThreadNode, *ThreadTree;
 
typedef struct BiTNode{
	int data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
void PreOrderbyPreThreadTree(ThreadTree T){
	if(!T) return;
	ThreadNode *p = T;
	while(p){
		while(p->lchild == 0){
			printf("%d ", p->data);
			p = p->lchild;
		}
		printf("%d ", p->data);
		p = p->rchild;
	}
	
}

int Width(BiTree T){
	if(!T) return 0;
	BiTNode* data[100];
	int level[100];
	int front = -1, rear = -1, k;
	++rear;
	data[rear] = T;
	level[rear] = 1;
	BiTNode *p;
	while(front < rear){
		++front;
		p = data[front];
		k = level[front];
		if(p->lchild){
			++rear;
			data[rear] = p->lchild;
			level[rear] = k + 1;
		}
		if(p->rchild){
			++rear;
			data[rear] = p->rchild;
			level[rear] = k + 1;
		}	

	}	
	k = 1;
	int i = 0, n;
	int max = 0;
	while(i<=rear){
		n = 0;
		while(i<=rear && level[i]==k){
			n++;
			i++;
		}
		k = level[i];
		if(n>max) max = n;	 
	}
	return max;
}
 
 
 //求高度，非递归
int Depth(BiTree T){
	BiTNode *p;
	BiTNode *Q[100];
	int front = -1, rear = -1;
	int depth = 0, last = 0;
	Q[++rear] = T; 
	while(front < rear){
		p = Q[++front];
		if(p->lchild) Q[++rear] = p->lchild;
		if(p->rchild) Q[++rear] = p->rchild;
		if(last == front){
			last = rear;
			++depth;
		}
	}
	return depth;
} 

//后序遍历非递归
void PostOrder(BiTree T){
	if(!T) return;
	BiTNode *p = T, *r = NULL;
	stack<BiTNode*> s;
	s.push(p);
	while(p || !s.empty()){
		if(p){
			s.push(p);
			p = p->lchild;
		}
		else{
			p = s.top();
			if(p->rchild && p->rchild!=r){
				p = p->rchild;
			}
			else{
				s.pop();
				printf("%d ", p->data);
				r = p;
				p = NULL;
			}
		}
	}
}



















int main(void){
	
	return 0;
}






