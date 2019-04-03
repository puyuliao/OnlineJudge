#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 2000005
#define int int64_t

int a[N],w[N],pre[N];

int32_t main()
{
	IOS;
	int T,n,k;
	cin >> T;
	while(T--){
		cin >> n >> k;
		for(int i=1;i<=n;i++) cin >> a[i];
		for(int i=1;i<=n;i++) cin >> w[i],pre[i] = pre[i-1] + w[i];	
		int ans = 0;
		for(int i=1,j=1;;i++){
			while(j <= n && a[j] - a[i] <= k) j++;
			if(j>n) break;
			ans += w[i] * (pre[n] - pre[j-1]);
		}	
		cout << ans << '\n';
	}

   return 0;
}


