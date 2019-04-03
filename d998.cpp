#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 100001
#define M 200001

vector<pair<int,int64_t> > v[N];
bool visit[N];
int64_t cycle[M];
int top;
int64_t dis[N];

void dfs(int n){
	visit[n] = true;
	for(auto i : v[n]){
		if(visit[i.first]){
			if(dis[i.first] ^ dis[n] ^ i.second) cycle[top++] = dis[i.first] ^ dis[n] ^ i.second;
		}
		else{
			dis[i.first] = dis[n] ^ i.second;
			dfs(i.first); 
		}
	}
}

void gauss(){
	int now = 0;
	for(int64_t i = 1LL<<62;i && now < top;i>>=1){
		int j = now;
		for(;j<top;j++) if(cycle[j] & i) break;
		if(j == top) continue;
		swap(cycle[now],cycle[j]);
		for(j = now+1;j<top;j++){
			if(cycle[j] & i) cycle[j] ^= cycle[now];
		}
		now++;
	}
}

int main()
{
	IOS;
	int n,m,s,t;
	int64_t d;
	cin >> n >> m;
	while(m--){
		cin >> s >> t >> d;
		v[s].push_back(make_pair(t,d));
		v[t].push_back(make_pair(s,d));
	}
	dfs(1);
	gauss();
	for(int i=0;i<top;i++) dis[n] = max(dis[n],dis[n] ^ cycle[i]);
	cout << dis[n] << '\n';

   return 0;
}


