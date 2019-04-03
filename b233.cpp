#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 30001

vector<int> v[N];
bool iscut[N];
int dc[N],sz[N];
int vis[N];
int low[N],clk;

void dfs(int x,int p){
	int clo = vis[x] = low[x] = ++clk;
	sz[x] = dc[x] = 1; iscut[x] = false;
	for(int i : v[x]) if(i != p){
		if(vis[i]) low[x] = min(low[x],low[i]);
		else{
			dfs(i,x); sz[x] += sz[i];
			low[x] = min(low[x],low[i]);
			if(low[i] >= vis[x]) iscut[x] = true,dc[x] += sz[i];
		}
	}
	if(x == p) iscut[x] = false;
}

int main()
{
	IOS;
	int n,m,a,b,s,mx=0,mxd;
	while(cin >> n >> m){
		mx = clk = 0;
		memset(vis,0,sizeof(vis));
		memset(iscut,false,sizeof(iscut));
		for(int i=1;i<=n;i++) v[i].clear();
		while(m--){
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a); 
		}
		cin >> s;
		dfs(s,s);
		for(int i=1;i<=n;i++) if(iscut[i] && mx < dc[i]) mx = dc[i],mxd = i;
		if(mx == 0) cout << 0 << '\n';
		else cout << mxd << ' ' << clk - mx + 1 << '\n'; 
	}
   return 0;
}


