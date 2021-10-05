#include<bits/stdc++.h>
using namespace std;
void hanoi(int n, char A, char B, char C){
	if(n==0) return;
	hanoi(n-1, A, C, B);
	printf("Move disk %d from %c to %c\n", n, A, C);
	hanoi(n-1, B, A, C);	
}

int main(void){
	int n;
	while(cin >> n){
		hanoi(n, 'A', 'B', 'C');
		putchar('\n');
	}	
	return 0;
}

