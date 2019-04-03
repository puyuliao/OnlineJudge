#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000002

int sz[N];
int64_t ans,n;
vector<pair<int,int> > v[N];
void bfs(int x,int p){
	vector<pair<int,int> > q;
	q.push_back(make_pair(x,p));
	for(int i=0;i<q.size();i++){
		x = q[i].first; p = q[i].second;
		for(auto i : v[x]) if(i.first != p) q.push_back(make_pair(i.first,x));
	}
	for(int i = q.size()-1;i>=0;i--){
		sz[q[i].first] = 1;
		for(auto j : v[q[i].first]) if(j.first != q[i].second){
			 sz[q[i].first] += sz[j.first];  
			 ans += (int64_t)j.second * abs(n - (sz[j.first] << 1));
		}
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
		bfs(1,1);
		cout << ans << '\n';
	}
   return 0;
}
