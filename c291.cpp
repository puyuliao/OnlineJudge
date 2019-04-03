#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

#define MEM 50002
struct disjoint_set{
	int s,e,anc[MEM],sz[MEM],cp;
	void Init(int s,int e){cp = e-s;for(int i=s;i<e;i++) anc[i] = i,sz[i] = 1;}
	int Find(int x){return anc[x]==x?x:anc[x]=Find(anc[x]);}
	inline int Size(int x){return sz[Find(x)];}
	inline int Count(){return cp;}
	void Union(int x,int y){
		x = Find(x); y = Find(y);
		if(x == y) return;
		if(sz[x] < sz[y]){int t = x;x = y;y = t;}
		sz[x] += sz[y]; anc[y] = x;
		cp--;
	}
};

int main()
{
	IOS;
	int n,t;
	cin >> n;
	disjoint_set ds;
	ds.Init(0,n);
	for(int i=0;i<n;i++){
		cin >> t;
		ds.Union(i,t);
	}
	cout << ds.Count();
   return 0;
}


