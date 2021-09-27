#include<bits/stdc++.h>
using namespace std;
const int N = 101;//�������Ŀռ� 
char mp[N][N];//������������ŵ��ַ����� 
int a[N*N];//��Ӧ�Ĳ��鼯 
int find(int x){
	return x == a[x] ? x : a[x] = find(a[x]);
}
int movex[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int movey[] = {0, 1, -1, 1, -1, 0, 1, -1};
 
int main(void){
	int n, m;//n��,m�о���
	int i, j;//���������У��� 
	while(~scanf("%d%d", &n, &m)){
		if(n==0&&m==0) break;
		for(i = 0; i < n; ++i){
			scanf("%s", mp[i]);
		}
		int amount = m*n;//��ͨ����������ʼ��Ϊm*n
		for(i = 0; i < amount; i++){
			a[i] = i;
		}
		for(i = 0; i < n; ++i){
			for(j = 0; j < m; ++j){
				if(mp[i][j] == '*'){
					amount--;
				}
				else{
					for(int k = 0; k < 8; ++k){
						int nowi = i + movey[k];
						int nowj = j + movex[k];
						if(nowj>=0 && nowj<m && nowi>=0 && nowi<n && mp[nowi][nowj]=='@'){
							int index_1 = find(i*m + j);
							int index_2 = find(nowi*m + nowj);
							if(index_1 != index_2){
								a[index_1] = index_2;
								amount--;
							} 
						}
					}
				}
			}
		}
		cout << amount <<endl; 
	} 
	return 0;
}

