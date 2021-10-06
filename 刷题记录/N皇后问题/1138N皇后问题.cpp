#include<bits/stdc++.h>
using namespace std;
const int N = 13; 
int record[N];
bool isValid(int i, int j);
int NQueens(int i, int n){//i是行序号 
	if(i == n){//终止行 
		return 1;//我的理解：这一条路径成功的走到了最后，即使在valid的限制之下，那么当前的方法就是成功的。返回这个1 
	}
	int res = 0;
	for(int j=0; j < n; ++j){//j表示列，查找当前行数i下的摆法 
		if(isValid(i, j)){
			record[i] = j;//顺序不能错！！！！！ 
			res += NQueens(i+1, n); 
		}
	}
	return res;//返回值是摆完所有的皇后，合法的摆法种类 
}

bool isValid(int i, int j){
	for(int k=0; k<i; ++k){
		if(j == record[k] || abs(record[k] - j) == abs(i - k)){//共列，共斜线 
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



