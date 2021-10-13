#include<bits/stdc++.h>
using namespace std;
struct node{
	int id;
	node *pre, *next;//前驱，后继 
	node(int x) : id(x) {}
};

int main(void){
	int n, m;
	scanf("%d%d", &n, &m);
	node *head = new node(1), *last = head, *now;//为了方便建环，head为指向1的结点
	for(int i=2; i<=n; ++i){//从编号2到n建新结点
		now = new node(i);//now指向当前创建的结点
		now->pre = last;//将now的前驱指向last
		last->next = now;//将last的后继指向now
		last = now;//将last赋值成now
	}
	head->pre = last;
	last->next = head;//首位相连
	node *p = head;//通过p结点的移动来输出和删除结点
	while(p->next != p){//p->next = p说明只剩下一个结点了 
		for(int i=0; i<m-1; ++i) p = p->next;//移动m-1次，从1移动m-1次就到了要死的那个人了 
		now = p->next;//先将Now赋值为p->next;下次从now开始1，2,3，。。。 
		p->pre->next = p->next;
		p->next->pre = p->pre;
		p = now; 
	} 
	printf("%d\n", p->id);
	return 0;
}

