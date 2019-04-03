#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000002

int sz[N];
int64_t ans,n;
vector<pair<int,int> > v[N];
struct state{
	int x,p,sta;
};

void dfs(int x,int p){
	vector<state> s;
	sz[x] = 1;
	s.push_back(state{x,p,0});
	while(!s.empty()){
		state i = ;
		cout << "in " << i.x << '\n';
		sz[i.x] += sz[v[i.x][i.sta].first];
		for(int &j=i.sta;j<v[i.x].size();j++){
			if(v[i.x][j].first != i.p){
				sz[v[i.x][j].first] = 1;
				s.push_back(state{v[i.x][j].first,i.x,0});
				break;
			}
		}
		if(i.sta == v[i.x].size()) s.pop_back();
	}
	for(auto i : v[x]){
		if(i.first != p) ans += (int64_t)i.second * abs(sz[i.first]*2-n);//,cout << ans << '\n';
	}
}

int main()
{
	IOS;
	int a,b,w;
	while(cin >> n){
		memset(sz,0,sizeof(sz));
		for(int i=1;i<=n;i++) v[i].clear(); ans = 0;
		for(int i=1;i<n;i++){
			cin >> a >> b >> w;
			v[a].push_back(make_pair(b,w));
			v[b].push_back(make_pair(a,w));
		}
		dfs(1,1);
		cout << ans << '\n';
	}
   return 0;
}


