#include<bits/stdc++.h>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(){}
	ListNode(int x) : val(x), next(NULL) {}
}; 

ListNode* reverseBetween(ListNode* head, int m, int n){
	ListNode *preL  = NULL, *L = NULL, *sufR = NULL, *H = new ListNode, *q;
	//preL指向第m个结点前一个结点， L指向第m个结点，surR指向第n个结点后一个结点 
	int c = 1, flag = 0;//c表示当前为第几个结点， flag指示现在是否处于[m,n]中
	if(m==1) flag = 1;//如果从第一个结点开始反转，
	for(ListNode *p = head; p; c++){//遍历链表 
		if(c==m-1) preL = p;//当前到了m的前一个结点
		else if(c==m){//当前到了第m个结点 
			L = p;
			flag = 1;
		} 
		else if(c==n+1){//第n个结点后一个，此时flag=0 
			sufR = p;
			flag = 0;
		} 
		if(flag){//使用头插法，放到H为头指针的链表上 
			q = p->next;
			p->next = H->next;
			H->next = p;
			p = q;//p指向了下一个结点 
		} else p = p->next;
	} 
	L->next = sufR;//将反转后的子链表尾端与原链表连接
	if(preL){//如果存在第m-1个链表 
		preL->next = H->next;
		return head;
	} else{
		return H->next;
	}
}
void print(ListNode *x){
	printf("%d ", x->val);
	if(x->next) print(x->next);
}	
int main(void){
	int n, L, R, v;
	scanf("%d%d%d", &n, &L, &R);
	ListNode *head = new ListNode, *p = head;
	for(int i=1; i<=n; ++i){
		scanf("%d", &v);
		p->next = new ListNode(v);
		p = p->next;
	}
	print(reverseBetween(head->next, L, R));
	return 0;
}

