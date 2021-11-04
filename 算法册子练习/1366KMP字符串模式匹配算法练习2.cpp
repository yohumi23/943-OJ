#include<bits/stdc++.h>
using namespace std;
#define MAXSTRLEN  100
typedef char SString[MAXSTRLEN+2];
void InputString(SString &str){
	scanf("%s", str+1);
	str[0] = strlen(str+1);
}

void get_next(SString substr, int *next){
	int i = 1, j = 0;
	next[1] = 0;
	while(i < substr[0]){
		if(j ==0 || substr[j] == substr[i]){
			next[i+1] = j + 1;
			++i;
			++j;
		}
		else j = next[j];
	}
}

int Index_KMP(SString str, SString substr){
	int next[255];
	int i = 1, j = 1;
	get_next(substr, next);
	while(i<=str[0] && j<=substr[0]){
		if(j==0 || substr[j] == str[i]){
			++i;
			++j;
		}
		else{
			j = next[j];
		}
	}

	for(int k = 1; k <= substr[0]; ++k){
		printf("%d ", next[k]);
	} 
	if(j > substr[0]) return i - substr[0];
	else return 0;	
}
int main(void){
	int i;
	SString str, sub;
	for(i=0; i<3; ++i){
		InputString(str);
		InputString(sub);
		printf("\n%d\n", Index_KMP(str, sub));
	}
}




