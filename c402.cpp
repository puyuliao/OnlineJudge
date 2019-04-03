#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 3005
#define C 2000

vector<int> v[N];
int w[N];
int cor[N];

vector<int> nums;
bitset<N*C/20> bs;

int bfs(int x){
	queue<int> q;
	q.push(x);
	int val[3] = {0,0,0};
	cor[x] = 1;
	val[cor[x]] += w[x];
	while(!q.empty()){
		x = q.front(); q.pop();
		for(int i : v[x]) {
			if(cor[i] == cor[x]) return -1;
			else if(!cor[i]){
				cor[i] = 3 - cor[x];
				val[cor[i]] += w[i];
				q.push(i);
			}
		}
	}
	return abs(val[2] - val[1]);
}

int main()
{
	IOS;
	int n,m,sum = 0,a,b,ans = 0;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> w[i],sum += w[i];
	for(int i=0;i<m;i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=n;i++) if(!cor[i]){
		int t = bfs(i);
		if(t == -1) return cout << "Bye Bye Cruel World!\n",0;
		nums.push_back(t);
		ans += t;
	}
	bs[0] = 1;
	for(int i : nums){
		bs |= bs<<i;
	}
	int sp = ans/2;
	while(sp && !bs[sp]) sp--;
	int delta = abs(sp*2 - ans);
	int t = sum - delta >> 1;
	ans = min(t,sum - t);
	cout << ans << ' ' << sum-ans << '\n';
   return 0;
}


