#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 10001
#define INF 0x3f3f3f3f

int dis[N];
int indeg[N];
bool visit[N];
vector<int> lik[N];
queue<int> q;

void bfs(int n){
	q.push(n);
	visit[n] = true;
	dis[n] = 0;
	while(!q.empty()){
		n = q.front(); q.pop();
		for(int i : lik[n]){
			if(!visit[i]){
				visit[i] = true;
				dis[i] = dis[n] + 1;
				q.push(i);
			}
		}
	}
}

int main()
{
	IOS;
	int n,m,a,b,s,t;
	while(cin >> n >> m){
		for(int i=1;i<=n;i++){
			lik[i].clear();
		}
		memset(dis,0x3f,n+1<<2);
		memset(indeg,0,n+1<<2);
		memset(visit,false,n+1);
		while(m--){
			cin >> a >> b;
			lik[b].push_back(a);
			indeg[a]++;
		}
		cin >> s >> t;
		for(int i = 1;i <= n; i++){
			if(indeg[i] == 0 && i != t) {
				q.push(i);
				visit[i] = true;
			}
		}
		while(!q.empty()){
			a = q.front(); q.pop();
			for(int i : lik[a]){
				visit[i] = true;				
				indeg[i]--;
				if(indeg[i] == 0) q.push(i);
			}
		}
		
		bfs(t);
		if(dis[s] == INF) cout << "-1\n";
		else cout << dis[s] << '\n';
	}

   return 0;
}


