//层序遍历 
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
	p->data = data;//........不能丢掉 
	p->lchild = Create();
	p->rchild = Create();
	return p;
}

//非递归的先序遍历
void PreOrderI(BiTree T){
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
void InOrderI(BiTree T){
	if(T==NULL) return;
	stack<BiTNode*> s;
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
				s.pop();
				printf("%d ", p->data);
				r = p;
				p = NULL;
			}
		}
	}
}


//非递归的后序遍历
//结构体 内置flag标记法
//后序遍历的非递归实现 
struct element{
	BiTNode *ptr;
    int flag;//取值为1，第一次入栈，取值为2，第二次入栈
}x;
void PostOrderII(BiTree T){
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
 
//求二叉树的高度
//递归 
int Depth1(BiTree T){
	if(T==NULL) return 0;
	int ld = Depth1(T->lchild);
	int rd = Depth1(T->rchild);
	return (ld > rd) ? (ld+1) : (rd+1);
} 

//非递归
int Depth2(BiTree T) {
	if(!T) return 0;
	BiTNode *Q[100];//自定义一个队列
	int front = -1, rear = -1, depth = 0;
	int last = 0;
	Q[++rear] = T;
	BiTNode *p;
	while(front < rear){
		p = Q[++front];
		if(p->lchild){
			Q[++rear] = p->lchild;
		}
		if(p->rchild){
			Q[++rear] = p->rchild;
		}
		if(front == last){
			last =  rear;
			++depth;
		}
	} 
	return depth;
}

//不知道对不对。。。。。。 
int width(BiTree T){
	if(!T) return 0;
	BiTNode *Q[101];
	BiTNode *p; 
	int front = -1, rear = -1, max = 1;
	int last = 0;
	Q[++rear] = T;
	while(front < rear){
		p = Q[++front];
		if(p->lchild) Q[++rear] = p->lchild;
		if(p->rchild) Q[++rear] = p->rchild;
		if(front == last){
			if(rear-last > max) 
				max = rear-last;
			last = rea c r;
		}
	}
	return max;
} 

//王道书P155 T14解法 
typedef struct {
    BiTree data[100];//保存队列中的几点指针
    int level[100];//保存data中相同下标结点的层次
    itn front, rear;
}Qu;

int BTWidth(BiTree T){
    BiTNode *p;
    int k, max, i, n;//k为临时结点 
    Qu.front = Qu.rear = -1;//初始化队列
    Qu.rear++;
    Qu.data[Qu.rear] = T;
    Qu.level[Qu.rear] = 1;//根结点层次为1
    while(Qu.front < Qu.rear){
    	Qu.front++;
        p = Qu.data[Qu.front];
        k = Qu.level[Qu.front];
		if(p->lchild){
			Qu.rear++;
			Qu.data[Qu.rear] = p->lchild;
			Qu.level[Qu.rear] = k+1; 
		} 
		if(p->rchild){
			Qu.rear++;
			Qu.data[Qu.rear] = p->rchild;
			Qu.level[Qu.rear] = k+1; 
		} 		
		max = 0; 
		i = 0;
		k = 1;
		while(i<=Qu.rear){
			n = 0;
			while(i<=Qu.rear && Qu.level[i] == k){
				n++;
				i++;
			}
			k = Qu.level[i];
			if(n>max) max = n;
		}
		return max;
    }
}
int main(void){
	BiTNode *T = Create();
	//LevelOrder(T);
	putchar('\n');
	//PostOrderII(T);
	cout << width(T) << endl;
	return 0;
}




