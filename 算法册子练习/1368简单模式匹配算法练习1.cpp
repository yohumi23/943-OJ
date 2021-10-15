#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int main(void){
	char str1[N], str2[N];
	scanf("%s%s", str1+1, str2+1);
	int n1 = strlen(str1+1), n2 = strlen(str2+1);
	int i = 1, j = 1;
	while(i <= n1 && j <= n2){
		if(str1[i] == str2[j]){
			++i, ++j;
		}
		else{
			j = 1;
			i = i - j + 2;
		}
	}
	if(j > n2) printf("YES\n");
	else printf("NO\n");
	return 0;
}

