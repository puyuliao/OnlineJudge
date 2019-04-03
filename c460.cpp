#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 3
#define int long long

int cnt[N][1<<N];

int32_t main()
{
	IOS;
	int n,t,a,b,c,ans = 0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> t; cin >> a >> b >> c;
		cnt[t-1][(a<<2) + (b<<1) + c]++;
	}
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			for(int k=0;k<8;k++){
				if((i|j|k) == 7) ans += cnt[0][i] * cnt[1][j] * cnt[2][k];
			}
	cout << ans << '\n';

   return 0;
}


