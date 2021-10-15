#include<bits/stdc++.h>
using namespace std;

int main(void){
	char A[1005], B[1005];
	int i = 1, j = 1;
	scanf("%s%s", A+1, B+1);
	int n1 =strlen(A+1), n2 = strlen(B+1);
	while(i<=n1 && j<=n2){
		if(A[i] == B[j]){
			++i, ++j;
		}
		else{
			i = i - j + 2;
			j = 1;
		}
	} 
	if(j > n2) {
		cout << "YES" << endl;
	}else cout << "NO" << endl;
	return 0;
}

