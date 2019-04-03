#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 100005
#define M 500005
#define int int64_t

struct edge{
	int a,b,w;
	bool operator < (const edge &e){
		return w < e.w;
	}
}in[M];

struct disj{
	int fa[N],dep[N],dis[N];
	void init(int n){
		for(int i=1;i<=n;i++) fa[i] = i,dep[i] = dis[i] = 0;
	}
	int find(int x){
		if(fa[x] == x) return x;
		return find(fa[x]);
	}
	int LCA(int a,int b){
		int d = 0;
		while(a != b){
			//cout << "H";
			if(dep[a] > dep[b]) d = max(d,dis[b]), b = fa[b];
			else d = max(d,dis[a]), a = fa[a];
		}
		return d;
	}
	bool merge(int a,int b,int w){
		a = find(a); b = find(b);
		if(a == b) return false;
		if(dep[a] < dep[b]) swap(a,b);
		fa[b] = a;
		dis[b] = w;
		if(dep[a] == dep[b]) dep[a] ++;
		return true;
	}
}ds;

bitset<M> use;

int32_t main()
{
	//IOS;
	int n,m,mn,smn;
	cin >> n >> m;
	ds.init(n);
	for(int i=0;i<m;i++) cin >> in[i].a >> in[i].b >> in[i].w;
	sort(in,in+m);
	mn = 0; smn = 1ll<<62;
	for(int i=0;i<m;i++) if(ds.merge(in[i].a,in[i].b,in[i].w)) mn += in[i].w, use[i] = 1;
	for(int i=0;i<m;i++) if(!use[i]){
		int d = ds.LCA(in[i].a,in[i].b);
		smn = min(smn,mn - d + in[i].w);
	} 
	cout << mn << ' ' << smn << '\n';
   return 0;
}


