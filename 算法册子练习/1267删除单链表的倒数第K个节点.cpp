#include<bits/stdc++.h>
using namespace std;
typedef struct LNode{
	int data;
	LNode *next;
}LNode, *LinkList;
void del(LinkList &L, int x){
	LNode *fast = L->next, *slow = L->next, *pre = L;
	while(x--){
		fast = fast->next;
	}
	while(fast){
		fast = fast->next;
		slow = slow->next;
		pre = pre->next; 
	}
	pre->next = slow->next;
	free(slow);
}

void traval(LinkList L){
	LNode *p = L->next;
	while(p){
		printf("%d ", p->data);
		p = p->next;
	}
	
}
int main(void){
	int n, k;
	scanf("%d%d", &n, &k);
	LNode *L = new LNode, *r = L;
	L->next = NULL;
	for(int i=0; i<n; ++i){
		LNode *p = new LNode;
		scanf("%d", &p->data);
		p->next = NULL;
		r->next = p;
		r = p;
	}
//	LNode *tmp = L->next;
//	while(tmp){
//		cout << tmp->data << endl;
//		tmp = tmp->next;
//	}
	del(L, k);
	traval(L);
	return 0;
}

