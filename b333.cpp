#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1001

int lik[N][N],n;
bool visit[N];
int sz[N];
int in[N];

int dfs(int x){
	visit[x] = true; int mx = 0;
	for(int i=1;i<=n;i++){
		if(!lik[x][i]) continue;
		if(!visit[i]) mx = max(mx,dfs(i));
		else mx = max(mx,sz[i]);
	}
	return sz[x] = mx+1;
}

int main()
{
	IOS;
	int m,k,t;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> t;
		for(int j=0;j<t;j++) cin >> in[j];
		int ind = 0; 
		for(int j=in[0];j<in[t-1];j++){
			if(j == in[ind]) {
				ind++;
				continue;
			}
			for(int k=0;k<t;k++) lik[in[k]][j] = 1;
		}
	}
	int mx = 1;
	for(int i=1;i<=n;i++){
		if(!visit[i]) mx = max(mx,dfs(i));
	}
	cout << mx << '\n';
   return 0;
}


