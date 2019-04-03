#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000
#define int int_fast64_t

int ans(int n){
	int w = 5,ans = 0;
	while(w <= n){
		int d = n/w;
		int r = d*w + w-1;
		ans -= d*(r-n);
		ans += w*d*(d+1)/2;
		w *= 5;
	}
	return ans;
}

int32_t main()
{
	IOS;
	int T,l,r;
	cin >> T;
	while(T--){
		cin >> l >> r;
		cout << ans(r) - ans(l-1) << '\n';
	}
   return 0;
}
