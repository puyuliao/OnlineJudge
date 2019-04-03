#include<stdio.h>
#define N 30000

vector<int> v[N+1];
int clk;
int E[N+1<<1];
int H[N+1];
int L[N+1];
int st[__lg(2*(N+1<<1)-1)][N+1<<1|1];

inline int getint(){
	int x = 0,c;
	c = getchar();
	if(c == EOF) exit(0);
	while(c < '0' || c > '9') c = getchar();
	while('0' <= c && c <= '9') x = x*10+c-48,c=getchar();
	if(c == EOF) exit(0);
	return x;
}

void dfs(int n,int fa,int lev){
	E[H[n] = clk++] = n;
	L[n] = lev;
	for(int i : v[n]){
		if(i != fa) {
			dfs(i,n,lev+1);
			E[clk++] = n;
		}
	}
}

void build(){
	int n = clk;
	for(int i=0;i<n;i++) st[0][i] = E[i];
	for(int i=1;(1<<i)<=n;i++)
		for(int j=0;j+i<=n;j++)
			st[i][j] = min(st[i-1][j],st[i-1][j+(1<<i-1)]);
}

inline int RMQ(int a,int b){
	if(a>b) swap(a,b);
	int p = __lg(b-a+1);
	return min(st[p][a],st[p][b-(1<<p)+1]);
}

int main()
{
	int n,q,t,a,b;
	while(true){
		n = getint(); q = getint();
		clk = 0;
		for(int i=1;i<=n;i++){
			v[i].clear();
			while(t = getint()) v[i].push_back(t);
		}
		dfs(1,1,0);
		build();
		while(q--){
			a = getint(); b = getint();
			int ans = RMQ(H[a],H[b]);
			printf("%d %d\n",ans,abs(L[ans] - L[a]) + abs(L[ans] - L[b]));
		}
	}

   return 0;
}


