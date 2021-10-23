#include<bits/stdc++.h>
using namespace std;
struct BiTNode{
	int key;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//查找,递归 
BiTNode *SearchBST(BiTree T, int key){
	if(!T || T->key == key) return T;//找到元素，或者没找到，返回指针 
	else if(T->key < key) 
		return SearchBST(T->rchild, key);
	else 
		return SearchBST(T->lchild, key);
}

//查找，非递归
BiTNode *SearchBST(BiTree T, int key){
	BiTNode *p = T;
	while(p){
		if(p->key == key)
			return key;
		else if(p->key > key)
			p = p->lchild;
		else 
			p = p->rchild;
	} 
	return NULL;
} 

//插入
bool InsertBST(BiTree &T, int key){
	if(!T){
		T = (BiTNode *)malloc(sizeof(BiTNode));
		T->key = key;
		T->lchild = T->rchild = NULL;
		return true;
	}
	else if(T->key == key) return false;//Key已经存在
	else if(T->key > key) 
		return Search(T->lchild, key);
	else 
		return Search(T->rchild, key); 
}

//构造

void CreateBST(BiTree &T, int data[], int length){
	T = NULL;
	for(int i=0; i<length; ++i){
		Insert(T, data[i]);
	}
} 

//删除
bool DeleteBST(BiTree &T, int key){
	if(!T) return false;
	else if(T->key == key) {
		//只有左子树 
		if(T->rchild==NULL){
			BiTNode *p = T;
			T = T->lchild;
			free(p);
		}
		else if(!T->lchild){
			BiTNode *p = T;
			T = T->rchild;
			free(p);
		}
		else {
			BiTNode *p = T->lchild;
			while(p && p->rchild){
				p = p->rchild;
			}
			T->key = p->key;
			free(p);
		}
	} 
	else if(T->key > key) 
		return DeleteBST(T->lchild, key); 
	else 
		return DeleteBST(T->rchild, key);
} 


 
 
int main(void){

	return 0;
}

