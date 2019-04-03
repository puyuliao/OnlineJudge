#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 302

vector<int> v[N];

bitset<N*2> issqr;
int l,r;
bitset<N> vis;
int my[N];

bool dfs(int x){
	vis[x] = 1;
	for(int i : v[x]) if(l <= i && i <= r){
		if(!~my[i] || !vis[my[i]] && dfs(my[i])){
			my[i] = x;
			return true;
		}
	}
	return false;
}

int main()
{
	for(int i=0;i*i<2*N;i++) issqr[i*i] = 1;
	for(int i=1;i<=N;i++) for(int j=i+1;j<=N;j++) if(issqr[i+j]){
		v[i].push_back(j);
		v[j].push_back(i);
	}
	IOS;
	int ans = 0;
	while(cin >> l >> r){
		fill(my+l,my+r+1,-1);
		for(int i=l;i<=r;i++) {
			vis.reset();
			if(dfs(i)) ans ++;
		}
		if(ans == r-l){
			cout << "HHHH\n";
		}
		else cout << -1 << '\n';
	}

   return 0;
}


