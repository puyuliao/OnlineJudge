#include<bits/stdc++.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 50001

int nxt[N];
int sz[N];

void dfs(int n){
	sz[n] = 1;
	if(!sz[nxt[n]]) dfs(nxt[n]);
	sz[n] = sz[nxt[n]] + 1;
}

void brent(int n){
	int x = n,y = n, i = 0, k = 1;
	while(true){
		x = nxt[x];
		if(sz[x]) break;
		if(x == y) break;
		if(++i == k) y = x,i=0,k <<= 1;
	}
	if(!sz[x]){
		i++;
		for(int j = 0;j<i;j++){
			sz[x] = i;
			x = nxt[x]; 
		}
	}
	if(!sz[n]) dfs(n);
}

int main()
{
	IOS;
	int T,n,s,t,cnt = 0;
	cin >> T;
	while(T--){
		cin >> n;
		memset(sz,0,n+1<<2);
		memset(nxt,0,n+1<<2);
		for(int i=1;i<=n;i++){
			cin >> s >> t;
			nxt[s] = t;
		}
		for(int i=1;i<=n;i++)  {
			if(!sz[i]) brent(i);
		}
		int mx = 0; int ind = 0;
		for(int i=1;i<=n;i++) if(mx < sz[i]) mx = sz[i],ind = i;
		cout << "Case " << (++cnt) << ": ";
		cout << ind << '\n';
	}
  return 0;
}
