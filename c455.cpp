#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 100005

vector<int> v[N];
int my[N];
bitset<N> vis,greedy;

int mch(int x){
	vis[x] = 1;
	for(int i : v[x]) if(!~my[i] || !vis[my[i]] && mch(my[i]))
		return my[i] = x,1;
	return 0;
}

int main()
{
	IOS;
	int T,p,q,k,a,b;
	cin >> T;
	while(T--){
		cin >> p >> q >> k;
		memset(my,-1,q+1<<2);
		for(int i=1;i<=p;i++) v[i].clear();
		while(k--){
			cin >> a >> b;
			v[a].push_back(b);
		}
		int ans = 0;
		greedy.reset();
		for(int i=1;i<=p;i++)
			for(int j:v[i]) if(!~my[j]){
				my[j] = i; ans ++; greedy[i] = 1; break; 
			}
		for(int i=1;i<=p;i++) {
			if(greedy[i]) continue;
			vis.reset();
			ans += mch(i);
		}
		cout << ans << '\n';
	}
   return 0;
}
