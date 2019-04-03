#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 10005

vector<int> v[N];
int dis[N];

int dfs(int x,int p){
	if(x != p) dis[x] = dis[p] + 1;
	for(int i : v[x]) if(i != p) dfs(i,x);
}

int main()
{
	IOS;
	int n,t;
	while(cin >> n){
		memset(dis,0,sizeof(dis));
		for(int i=0;i<n;i++) v[i].clear();
		for(int i=0;i<n;i++){
			while(cin >> t && t!=-1) v[i].push_back(t), v[t].push_back(i);
		}
		dfs(0,0);
		t = (max_element(dis,dis+n) - dis);
		memset(dis,0,sizeof(dis));
		dfs(t,t);
		cout << *max_element(dis,dis+n) << '\n';
	}
	
   return 0;
}


