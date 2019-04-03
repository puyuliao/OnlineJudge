#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 10001

vector<int> v[N];
bool visit[N];

void dfs(int x){
	visit[x] = true; 
	for(int i : v[x]) if(!visit[i]) dfs(i);
}

int main()
{
	IOS;
	int n,m,l,T,a,b;
	cin >> T;
	while(T--){
		cin >> n >> m >> l;
		for(int i=1;i<=n;i++) v[i].clear();
		memset(visit,0,sizeof(visit));
		while(m--){
			cin >> a >> b;
			v[a].push_back(b);
		}
		while(l--){
			cin >> a;
			dfs(a);
		}
		b = 0;
		for(int i=0;i<=n;i++) if(visit[i])  b++;
		cout << b << '\n';
	}

   return 0;
}


