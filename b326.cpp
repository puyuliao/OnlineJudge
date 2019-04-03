#include <bits/stdc++.h>
using namespace std; 
#define N 32768

vector<int> v[N];
int sz[N],nxt[N],inn[N],pos[N];
bool vis[N];
int Ntop;

struct Node{
	int p;
	vector<int> a;
	set<int> s;
	void init(){
		s.clear();
		a.resize(0);
		p = 0;
	}
} node[N];

void dfs(int x,int p){
	int mxn,mxsz = 0;
	sz[x] = 1;
	for(int i : v[x]) if(i != p){
		dfs(i,x);
		sz[x] += sz[i];
		if(mxsz < sz[i]) mxsz = sz[i],mxn = i;
	}
	if(mxsz) nxt[x] = mxn;
}

void HL(int x,int p){
	if(!vis[x]){
		Node &nd = node[Ntop++];
		nd.init();
		for(int i = x; ~i; i = nxt[i]){
			vis[i] = true;
			inn[i] = Ntop-1; pos[i] = nd.a.size();
			nd.a.push_back(i);
		}
		nd.p = p;
	}
	for(int i : v[x]) if(i != p) HL(i,x);
}

void modify(int x){
	Node &nd = node[inn[x]];
	if(nd.s.count(pos[x])) return nd.s.erase(pos[x]), void();
	nd.s.insert(pos[x]);
}

int query(int x){
	Node &nd = node[inn[x]];
	if(nd.s.empty() || pos[x] < *nd.s.begin()){
		if(x) return query(nd.p);
		return -1;
	}
	return nd.a[*--nd.s.upper_bound(pos[x])];
}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n,a,b,q; char cmd;
	while(cin >> n){
		memset(vis,false,sizeof(vis));
		memset(nxt,0xff,sizeof(nxt)); Ntop = 0;
		for(int i=0;i<n;i++) v[i].clear();	
		for(int i=1;i<n;i++){
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		dfs(0,0);
		HL(0,0);
		cin >> q;
		while(q--){
			cin >> cmd >> a;
			if(cmd == 'S') cout << query(a) << '\n';
			else modify(a);
		}
	}
   return 0;
}
