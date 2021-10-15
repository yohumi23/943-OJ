#include<bits/stdc++.h>
using namespace std;

int a[15];
bool isvalid(int x, int y);
int NQueens(int n, int x){
	if(x == n)
		return 1;
	int ans = 0;
	for(int i=0; i<n; ++i){
		if(isvalid(x, i)){
			a[x] = i;
			ans += NQueens(n, x+1);
		}
	} 
	return ans;
	
}
bool isvalid(int x, int y){
	for(int i=0; i<x; ++i){
		if(a[i] == y || abs(a[i] - y) == abs(x - i)) return false;
	}
	return true;
}
int main(void){
	int n;
	scanf("%d", &n);
	cout << NQueens(n, 0) << endl;
	return 0;
}

