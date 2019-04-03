#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 100000
#define lowbit(x) (x&-x)

int n;
int64_t in[N];
int64_t sn[N];
int bt[N+1];
void add(int x,int k){ for(;x<=n;x+=lowbit(x)) bt[x] += k; }
int query(int x){ int ans = 0; for(;x;x-=lowbit(x)) ans += bt[x]; return ans;}
int main()
{
	IOS;	
	while(cin >> n){
		for(int i=0;i<n;i++) cin >> in[i];
		memset(bt,0,sizeof(bt));
		memcpy(sn,in,n<<3);
		sort(sn,sn+n);
		for(int i=0;i<n;i++){
			int k = n - (int)(lower_bound(sn,sn+n,in[i]) - sn);
			cout << query(k) + 1 << '\n';
			add(k,1);
		}
	}
}
