#include<bits/stdc++.h>
#include<stdint.h> 
CFLAGS="-march=athlon64 -O2 -pipe";
CXXFLAGS="${CFLAGS}";
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define MAXN 100000

vector<int> v[MAXN];
int dis[MAXN];

void dfs(int s,int n,int ls){
	dis[s] = n;
	for(int i : v[s]) {
		if(i != ls) dfs(i,n+1,s);
	} 
}

int main()
{
	IOS;
	int n,a,b;
	while(cin >> n){
		for(int i=0;i<n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			cin >> a >> b;
			v[a].push_back(b); 
			v[b].push_back(a);
		}
		dfs(0,0,-1);
		int s = (int)(max_element(dis,dis+n) - dis);
		//cout << s << '\n';
		dfs(s,0,-1);
		cout << *max_element(dis,dis+n) << '\n';
	}
  return 0;
}

 

