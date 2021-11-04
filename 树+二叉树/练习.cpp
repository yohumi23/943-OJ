//层序遍历 
#include<bits/stdc++.h>
using namespace std;
typedef struct BiTNode{
	int data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
//递归层序遍历 
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
	p->data = data;//........不能丢掉 
	p->lchild = Create();
	p->rchild = Create();
	return p;
}

//非递归的先序遍历
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

//非递归的中序遍历
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


//非递归的后序遍历
//指针标记法
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
 
 
//非递归后序遍历
void PostOrder(BiTree T, BiTNode *t){
	if(!T) return;
	BiTNode  *p = T, *r = NULL;
	stack<BiTNode *> s;
	while(p || !s.empty()){
		if(p){
			s.push(p);
			p = p->lchild;
		}
		else {
			p = s.top();
			if(p->rchild && p->rchild!=r){
				p = p->rchild;
			}
			else{
				s.pop();
				cout << p->data << ' ';
				r = p;
				p = NULL;
			}
		}
		
	}
} 

//求指定节点的父节点
//递归
BiTNode *Parent(BiTNode *t, BiTNode *p){
	if(t==NULL || p==NULL) return NULL;
	if(t->lchild == p || t->rchild == p) return t;
	BiTNode *q = Parent(t->lchild, p);
	if(q != NULL) return q;
	else return Parent(t->rchild, p);
} 

//统计度为1的结点的个数
int Degrees_1(BiTNode *t){
	if(t==NULL) return 0;
	if((t->lchild!=NULL && t->rchild==NULL) || (t->lchild==NULL && t->rchild!=NULL)){
		return 1 + Degrees_1(t->lchild) + Degrees_1(t->rchild); 
	}
	else return Degrees_1(t->lchild) + Degrees_1(t->rchild);
} 

//统计度为0的结点的个数
int leaves(BiTNode *t){
	if(t==NULL) return 0;
	if(t->lchild == NULL && t->rchild == NULL) return 1;
	return leaves(t->lchild) + leaves(t->rchild);
}

//计算二叉树中指定结点*p所在的层数(深度)
int level(BiTNode *t, BiTNode *p, int d){
	if(p==NULL) return 0;
	if(t==p) return d;
	int SubTreeLevel = level(t->lchild, p, d+1);
	if(SubTreeLevel > 0) return SubTreeLevel;
	else return level(t->rchild, p, d+1); 
}

//int depth = level(root, p, 1);

//删除所有叶节点
void defoliate(BiTNode *&t){
	if(t==NULL) return;
	if(t->lchild==NULL && t->rchild==NULL) {
		delete t;
		t = NULL;//这一步是避免成为野指针 
	}
	else{
		defoliate(t->lchild);
		defoliate(t->rchild);
	}
}

//计算二叉树中各节点最大元素的值
void maxValue(BiTNode *t, int &max){
	if(t!=NULL){
		if(t->data > max) max = t->data;
		maxValue(t->lchild, max);
		maxValue(t->rchild, max);
	}	 
}

//交换以t为根的二叉树中每个结点的两个子女
void reflect(BiTNode *t, BiTNode *p){
	if(t==NULL) return;
	if(t == p){
		BiTNode *r = t->lchild;
		t->lchild = t->rchild;
		t->rchild = r;
	}
	else{
		reflect(t->lchild, p);
		reflect(t->rchild, p);
		
	}
} 

//打印指定节点的所有祖先(递归)
int Find_Print(BiTNode *t, int x, int path[], int level, int &count){
	if(t!=NULL){
		path[level-1] = t->data;
		if(t->data==x){
			count = level;
			return 1;
		}
		if(Find_Print(t->lchild, x, path, level+1, count)) return 1;
		return Find_Print(t->rchild, x, path, level+1, count);
	}
	else return 0;
}

//打印指定节点的所有祖先(递归)练习1
int Find_Print2(BiTNode *t, int x, int path[], int level, int &count){
	if(t!=NULL){
		path[level-1] = t->data;
		if(t->data == x){
			count = level;
			return 1;
		}
		if(Find_Print2(t->lchild, x, path, level+1, count)) return 1;
		return Find_Print2(t->rchild, x, path, level+1, count);
	}
	else return 0;
}



 

//求前序序列的第k个结点
BiTNode *Pre_Search_K(BiTNode *t, int & count, int k){
	if(t!=NULL){
		count++;
		if(count == k) return t;
		BiTNode *p = Pre_Search_K(t->lchild, count, k);
		if(p!=NULL) return p;
		else return Pre_Search_K(t->rchild, count, k);
	}
	return NULL;
} 
//BiTNode *p = Pre_Search_k(t, 0, k); 


//求前序序列的第k个结点 练习
BiTNode *PreSearch_K2(BiTNode* t, int &count, int k){
	if(t!=NULL){
		count++;
		if(count == k) return t;
		BiTNode *p;
		if((p=PreSearch_K2(t->lchild, count, k)) != NULL) return p;
		return PreSearch_K2(t->rchild, count, k);
	}
} 


//利用前序遍历求指定的两个节点之间的路径长度
#define n 101
void PathLength_P_Q(BiTNode *t, int p, int q, int path[], int &len){
	int i, j, k, pc, qc;
	int *path1 = (int *)malloc(sizeof(int)*n);
	int *path2 = (int *)malloc(sizeof(int)*n);
	//Find_Print(t, p, path1, pc);//pc为个数
	//Find_Print(t, q, path2, qc);
	if(!pc || !qc) {//*p 或 *q 中至少有一个不在树中 
		len = 0;
		return;
	} 
	for(i=0; i<pc && i<qc; i++)
		if(path1[i]!=path2[i]) break;//跳过公共祖先
	for(j=pc-1, k=0; j>=i-1; j--, k++) path[k] = path1[j];//连接结点间路径
	for(j=i; j<qc && j++; k++) path[k] = path2[j];
	len = k; 
} 


//利用前序遍历求置顶两个节点之间路径长度
/*
#define N 101
void PathLength_P_Q(BiTNode *t, int p, int q, int path[], int &len){
	int i, j, k, pc, qc;
	int *path1 = (int *)malloc(sizeof(int)*N);
	int *path2 = (int *)malloc(sizeof(int)*N);
	Find_Print(t, p, path1, pc);
	Find_Print(t, q, path2, qc);
	if(!pc || !qc) { 
		len = 0;
		return;
	}
	for(i=0; i<pc && i<qc; ++i){
		if(path1[i] != path2[i]) break;
	}
	for(j=pc-1, k=0; j>=i-1; j--, k++) path[k] = path1[j]; //连接结点间路径 
	for(j=i; j<qc; j++, k++) path[k] = path2[j];
	len = k;
}
*/

//利用后序遍历求二叉树的高度,并判断是否平衡
//int HeightBalance(BiTNode *t, int &height){
//	if(t!=NULL){
//		int lh, rh;
//		if(!HeightBalance(t->lchild, lh)) return 0;//左子树高度
//		HeightBalance(t->rchild, rh) return 0;
//		heigth = (lh > rh) ? 1 + 1h : 1 +rh;
//		if(abs(lh - rh)<=1) return 1;//平衡返回1 
//		else return 0;
//	}
//	else{
//		heigth = 0;
//		return 1;//空树也是平衡树 
//	}
//}

/*
//前序遍历 算法改写
void PreOrder(BiTNode *t){
	if(t!=NULL){
		cout << t->data << ' ';
		PreOrder(t->lchild);
		PreOrder(t->rchild);
	}
} 

//1.消去第二个递归调用PreOrder(t->rchild)
void PreOrder(BiTNode *t){
	if(t!=NULL){
		cout << t->data << ' ';
		PreOrder(t->lchild);
		//PreOrder(t->rchild);
		t = t->rchild;
	}
} 

//2.非递归
void PreOrder(BiTNode *t){
	stack<BiTNode*> s;
	BiTNode *p = t;
	while(p || !s.empty()){
		if(p){
			s.push(p);
			cout << p->data << ' ';
			p = p->lchild;
		}
		else{
			p = s.top();
			p = p->rchild;
			s.pop();
		}
	}
} 
*/
//求T的所有叶节点的值及其所在层次
#define N 101
void leave(BiTree &T, BiTNode * leaf[], int lev[], int &num){
	BiTNode *p = T; num = 0;
	if(!T) return;
	BiTNode *queue[N];
	int rear = -1, front = -1, last = 0, level = 1;
	queue[++rear] = p;
	while(front != rear){
		p = queue[++front];
		if(p->lchild == NULL && p->rchild == NULL){
			leaf[num] = p;
			lev[num] = level;
			++num;
		}
		if(p->lchild) queue[++rear] = p->lchild;
		if(p->rchild) queue[++rear] = p->rchild;
		if(front == last){
			last = rear;
			++level;
		}
	}
}

void Pre_to_Post(BiTNode *pre[], int l1, int r1, BiTNode *post[], int l2, int r2){
	int n = r1 - l1 + 1, m = (n-1) / 2;//左子树或右子树结点数 
	if(n){
		post[r2] = pre[l1];
		Pre_to_Post(pre, l1+1, l1+m, post, l2, l2+m-1);
		Pre_to_Post(pre, r1-m+1, l2, post, l2-m, l2-1);
	}
	
	
}

int main(void){
	BiTNode *T = Create();
	BiTNode *leaf[N]; int lev[N];
	int num;
	leave(T, leaf, lev, num);
	for(int i=0; i<num; ++i){
		cout << leaf[i]->data << '-' << lev[i] << endl;
	}
	putchar('\n');
	return 0;
}




