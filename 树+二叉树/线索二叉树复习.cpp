#include<bits/stdc++.h>
using namespace std;
typedef struct ThreadNode{
	int data;
	ThreadNode *lchild, *rchild;
	int ltag, rtag;
}ThreadNode, ThreadTree;

//���������������Ĺ���
void InThread(ThreadTree *p, ThreadNode *&pre){
	if(p!=NULL){
		InThread(p->lchild, pre);
		if(p->lchild == NULL){
			p->lchild = pre;
			p->ltag = 1;
		}
		if(pre != NULL &e7& pre->rchild == NULL){
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
		InThread(p->rchild, pre);
	}
}
void CreateInTread(ThreadTree T){
	ThreadTree pre = NULL;
	if(T!=NULL){
		InThread(T, pre);
		pre->rchild = NULL;
		pre->rtag = 1;
	}
}

//�ҳ�������������������������ĵ�һ�����
ThreadNode *First(ThreadNode *p){
	while(p->ltag == 0){
		p = p->lchild;
	}
	return p;
} 

//�ҵ����������������н��p����������еĺ��
ThreadNode *Next(ThreadNode *p){
	if(p->rtag == 1) return p->rchild;
	else return First(p->rchild);
} 

//���������������ı���
void InOrderbyThread(ThreadTree T){
	for(ThreadNode *p = First(T); p!=NULL; p=Next(p)){
		printf("%d ", p->data); 
	}
} 


//���򹹽�����������
void PreThread(ThreadNode *p, ThreadNode *&pre){
	if(p->lchild == NULL){
		p->lchild = pre;
		p->ltag = 1;
	}
	if(pre!=NULL && pre->rchild==NULL){
		pre->rchild = p;
		pre->rtag = 1;
	}
	pre = p;
	if(p->ltag == 0){
		PreThread(p->lchild, pre);
	}
	if(p->rtag == 0){
		PreThread(p->rchild, pre);
	}
}

//���������������ı���
void PreOrder(ThreadTree T){
	if(T != NULL){
		ThreadNode *p = T;
		while(p != NULL){
			while(p->lchild == 0){
				visit(p);
				p = p->lchild;
			}
			visit(p);
			p = p->rchild;
		}
	}
	
	
}
int main(void){

	return 0;
}

