#include<bits/stdc++.h>
using namespace std;
#define MAXSTRLEN 1001
typedef char SString[MAXSTRLEN+2];
void InputString(SString &str){
	scanf("%s", str+1);
	str[0] = strlen(str+1);
}

void get_next(SString sub, int *next){
	int i = 1, j = 0;
	next[1] = 0;
	while(i <  sub[0]){
		if(j==0 || sub[i] == sub[j]){
			++i, ++j;
			next[i] = j;
		}
		else j = next[j];
	}
}

int KMP(SString S, SString T, int pos){
	int i = pos, j = 1;
	int next[255];
	get_next(T, next);
	for(int i=1; i<=T[0]; ++i) printf("%d ", next[i]);
	while(i <= S[0] && j <= T[0]){
		if(j == 0 || S[i] == T[j]){
			++i, ++j;
		}
		else j = next[j];
	}
	if(j > T[0]) return i - T[0];
	else return 0;
}
int main(void){
	int i;
	SString str, sub;
	for(int i=0; i<3; ++i){
		InputString(str);
		InputString(sub);
		printf("\n%d\n", KMP(str, sub, 1));
	}
	return 0;
}

