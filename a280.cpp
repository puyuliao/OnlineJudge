#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 101

vector<int> v[N];
bool visit[N];

void dfs(int n){
	visit[n] = true;
	//cout << n << '\n';
	for(int i : v[n]) if(!visit[i]) dfs(i);
}

int main()
{
	IOS;
	int n,k,a,b;
	while(cin >> n >> k){
		for(int i=0;i<N;i++){
			v[i].clear();
			visit[i] = false;
		}
		while(k--){
			cin >> a >> b;
			v[a].push_back(b);
		}
		dfs(0);
		cout << (visit[n]?"Ok!\n":"Impossib1e!\n");
	}

   return 0;
}


