#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}

int anc[1000001];
int sz[1000001];

int dsfind(int a){
	if(anc[a] == a) return a;
	return anc[a] = dsfind(anc[a]); 
}

void dsunion(int a,int b){
	a = dsfind(a); b = dsfind(b);
	if(a == b) return;
	if(sz[a]<sz[b]) swap(a,b);
	sz[a] += sz[b];
	anc[b] = a;
}

int main()
{
	IOS;
	int n,m,a,b;
	while(cin >> n >> m){
		for(int i=0;i<n;i++) anc[i]=i,sz[i]=1;
		while(m--){
			cin >> a >> b;
			dsunion(a,b);
		}
		cout << *max_element(sz,sz+n) << '\n';
	}
  return 0;
}
