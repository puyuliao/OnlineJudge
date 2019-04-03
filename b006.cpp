#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 30000

int l[N],r[N];
vector<int> v[N];
bool visit[N];
int sz[N];

int dfs(int x){
	visit[x] = true; int mx = 0;
	for(int i : v[x]) 
		if(!visit[i]) mx = max(mx,dfs(i));
		else mx = max(mx,sz[i]);
	return sz[x] = mx+1;
}

int main()
{
	IOS;
	int n;
	while(cin >> n){
		if(n >= N) cout << "WTF",exit(0);
		for(int i=0;i<n;i++) v[i].clear();
		memset(visit,0,sizeof(visit));
		for(int i=0;i<n;i++){
			cin >> l[i] >> r[i];
			if(l[i] > r[i]) swap(l[i],r[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(l[i] <= l[j] && r[i] <= r[j]) v[i].push_back(j);
				else if(l[i] >= l[j] && r[i] >= r[j]) v[j].push_back(i);
			}
		}
		int mx = 0;
		for(int i=0;i<n;i++){
			if(!visit[i]) mx = max(mx,dfs(i));
		}
		cout << mx << '\n';
	}

   return 0;
}


