#include<bits/stdc++.h>
using namespace std;
const int N = 13; 
int record[N];
bool isValid(int i, int j);
int NQueens(int i, int n){//iÊÇĞĞĞòºÅ 
	if(i == n){
		return 1;
	}
	int res = 0;
	for(int j=0; j < n; ++j){
		if(isValid(i, j)){
			record[i] = j;
			res += NQueens(i+1, n); 
		}
	}
	return res;
}

bool isValid(int i, int j){
	for(int k=0; k<i; ++k){
		if(j == record[k] || abs(record[k] - j) == abs(i - k)){
			return false;
		}
	}
	return true;
}


int main(){
	int N;
	scanf("%d", &N);
	if(N < 3 || N > 13) return 0;
	cout << NQueens(0, N) << endl;
	return 0;
}



