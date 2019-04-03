#include<stdio.h>
#include<stdint.h>
#include<vector>
#include<memory.h>
using namespace std;
#define N 32768
#define lowbit(x) (x&-x)

int bt[N + 1];
int L[N];
int R[N];
int sn;
vector<int> v[N];

void dfs(int x,int p){
	L[x] = sn++; 
	for(int i : v[x]) if(i != p) dfs(i,x);
	R[x] = sn;
}

inline void add(int l,int r,int c){
	for(;l<=sn;l+=lowbit(l)) bt[l] += c;
	for(;r<=sn;r+=lowbit(r)) bt[r] -= c;
}

inline int val(int q){
	int sum = 0;
	for(;q;q-=lowbit(q)) sum += bt[q];
	return sum;
}

inline bool readn(int &a){
	static int c = ' ';
	while(c == ' ' || c == '\n') c = getchar();
	if('0' > c || c > '9') return false; 
	a = 0;
	while('0' <= c && c <= '9') {
		a = a*10 + c-'0';
		c = getchar();
	}
	return a;
}

int main()
{
	int n,q,a,b;
	while(readn(n)){
		for(int i=0;i<n;i++) v[i].clear(); sn = 1;
		for(int i=1;i<n;i++){
			readn(a); readn(b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		dfs(0,0);
		memset(bt,0,sn+1<<2);
		readn(q);
		while(q--){
			readn(a); readn(b);
			add(L[a],R[a],b);
			printf("%d\n",val(L[a]));
		}
	}
   return 0;
}
