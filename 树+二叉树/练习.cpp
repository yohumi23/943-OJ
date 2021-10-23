//������� 
#include<bits/stdc++.h>
using namespace std;
typedef struct BiTNode{
	int data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void LevelOrder(BiTree T){
	queue<BiTNode*> q;
	BiTNode *p = NULL; 
	if(T){
		q.push(T);
		while(!q.empty()){
			p = q.front();
			q.pop();
			printf("%d ", p->data);
			if(p->lchild) q.push(p->lchild);			
			if(p->rchild) q.push(p->rchild);			
		}
	} 
} 

BiTNode *Create(void){
	int data;
	scanf("%d", &data);
	if(data == -1) return NULL;
	BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = data;//........���ܶ��� 
	p->lchild = Create();
	p->rchild = Create();
	return p;
}

//�ǵݹ���������
void PreOrder(BiTree T){
	if(T==NULL) return;
	stack<BiTNode*> s;
	BiTNode *p = T;
	while(p || !s.empty()){
		if(p){
			printf("%d ", p->data);
			s.push(p);
			p = p->lchild;
		}		
		else{
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
} 

//�ǵݹ���������
void InOrder(BiTree T){
	if(T == NULL) return;
	stack<BiTNode *> s;
	BiTNode *p = T;
	while(p || !s.empty()){
		if(p){
			s.push(p);
			p = p->lchild;
		}
		else{
			p = s.top();
			printf("%d ", p->data);
			s.pop();
			p = p->rchild;
		}
	}
} 


//�ǵݹ�ĺ������
//ָ���Ƿ�
void PostOrderI(BiTree T){
	if(T==NULL) return;
	stack<BiTNode*> s;
	BiTNode *p = T, *r = NULL;
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
				printf("%d ", p->data);
				s.pop();
				r = p;
				p = NULL;
			}
		}
	}
} 
 
//���������������Ĺ���
int main(void){
	BiTNode *T = Create();
	LevelOrder(T);
	putchar('\n');
	PostOrderI(T);
	return 0;
}

