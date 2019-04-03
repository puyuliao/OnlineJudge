#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 201

int visit[N];
vector<int> v[N];

bool dfs(int x,int c){
	visit[x] = c;
	for(int i : v[x]){
		if(visit[i] == c) return false;
		if(visit[i] == (c^1)) continue;
		if(!visit[i] && dfs(i,c^1));
		else return false; 
	}
	return true;
}

int main()
{
	IOS;
	int n,m,a,b;
	while(cin >> n && n){
		cin >> m;
		for(int i=0;i<n;i++) visit[i] = 0,v[i].clear();
		while(m--){
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		if(dfs(0,2)) cout << "BICOLORABLE.\n";
		else cout << "NOT BICOLORABLE.\n";
	}

   return 0;
}


