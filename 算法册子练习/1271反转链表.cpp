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
	//preLָ���m�����ǰһ����㣬 Lָ���m����㣬surRָ���n������һ����� 
	int c = 1, flag = 0;//c��ʾ��ǰΪ�ڼ�����㣬 flagָʾ�����Ƿ���[m,n]��
	if(m==1) flag = 1;//����ӵ�һ����㿪ʼ��ת��
	for(ListNode *p = head; p; c++){//�������� 
		if(c==m-1) preL = p;//��ǰ����m��ǰһ�����
		else if(c==m){//��ǰ���˵�m����� 
			L = p;
			flag = 1;
		} 
		else if(c==n+1){//��n������һ������ʱflag=0 
			sufR = p;
			flag = 0;
		} 
		if(flag){//ʹ��ͷ�巨���ŵ�HΪͷָ��������� 
			q = p->next;
			p->next = H->next;
			H->next = p;
			p = q;//pָ������һ����� 
		} else p = p->next;
	} 
	L->next = sufR;//����ת���������β����ԭ��������
	if(preL){//������ڵ�m-1������ 
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

