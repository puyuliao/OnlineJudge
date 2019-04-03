#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 10000

vector<int> v[N+1];
bool visit[N+1];

void dfs(int n){
	visit[n] = true;
	for(int i : v[n]) if(!visit[i]){
		dfs(i);
	}
}

int main()
{
	IOS;
	int n,m,l,q,a,b;
	cin >> n >> m >> l >> q;
	while(m--){
		cin >> a >> b;
		v[a].push_back(b);
	}
	while(l--){
		cin >> a;
		dfs(a);
	}
	while(q--){
		cin >> a;
		cout << (visit[a]?"TUIHUOOOOOO\n":"YA~~\n");
	}
   return 0;
}


