#include<bits/stdc++.h>
using namespace std;
#define MAXSTRLEN 100
typedef char SString[MAXSTRLEN+2];
void Input(SString &str){
	scanf("%s", str+1);
	str[0] = strlen(str+1);
} 
void get_next(SString substr, int next[]){
	int i = 1, j = 0;
	next[1] = 0;
	while(i<substr[0]){
		if(j==0 || substr[j] == substr[i]){
			++i;
			++j;
			next[i] = j;
		}
		else{
			j = next[j];
		}
	}
}
void Index_KMP(SString str, SString substr){
	int next[255];
	get_next(substr, next);
	int i = 1, j = 1;
	while(i<=str[0] && j<=substr[0]){
		if(j==0 || str[i] == substr[j]){
			++i;
			++j;
		}
		else{
			j = next[j];
		}
	}
	
	for(int k=1; k<=substr[0]; ++k){
		printf("%d ", next[k]);
	}
	if(j>substr[0]) 
		printf("\n%d\n", i-substr[0]);
	else printf("\n0\n");
	
}
int main(void){
	SString str, substr;
	for(int i=0; i<3; ++i){
		Input(str);
		Input(substr);
		Index_KMP(str, substr);
	}
	return 0;
}

