#include<bits/stdc++.h>
#define N 1000050
using namespace std;
char s[N]; 
int rank[N],y[N],tmp[N]; 
int c[N],SA[N],n,m,Height[N];
void Sort(){
	for(int i=1;i<=m;i++) c[i] = 0;
	for(int i=1;i<=n;i++) c[rank[i]]++;
	for(int i=2;i<=m;i++) c[i] += c[i-1];
	for(int i=n;i>=1;i--) SA[c[rank[y[i]]]--] = y[i];
}
void get_SA(){
	for(int i=1;i<=n;i++) rank[i] = s[i] , y[i] = i;
	Sort();
	for(int k=1;k<=n;k<<=1){
		int cnt = 0;
		for(int i=n-k+1;i<=n;i++) y[++cnt] = i;
		for(int i=1;i<=n;i++) if(SA[i]>k) y[++cnt] = SA[i] - k;
		Sort(); swap(rank,tmp); int num = 1; rank[SA[1]] = 1;
		for(int i=2;i<=n;i++){
			if(tmp[SA[i]] == tmp[SA[i-1]] && tmp[SA[i]+k] == tmp[SA[i-1]+k])
				rank[SA[i]] = num;
			else rank[SA[i]] = ++num;
		} m = num;
	}
}
void get_Hi(){
	int k = 0;
	for(int i=1;i<=n;i++){
		if(rank[i]==1) continue;
		int j = SA[rank[i]-1]; if(k) k--;
		while(i+k<=n && j+k<=n && s[i+k]==s[j+k]) k++; 
		Height[rank[i]] = k;
	}
} 
int main(){
	scanf("%s",s+1); n = strlen(s+1);
	m = 127; get_SA();  get_Hi();
	for(int i=1;i<=n;i++) printf("%d ",SA[i]);
	return 0;
}