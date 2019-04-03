#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000001
#define INF 0x3f3f3f3f
#define push_back emplace_back
#define ff first
#define ss second

int t[N],dp[N];

int main()
{
	IOS;
	int n,m,a,b,mx = 0;
	cin >> n >> m;
	while(n--){
		cin >> a >> b;
		t[b] += a;	
	}
	fill(dp+1,dp+m+1,-INF);
	for(int i : {4,7}){
		for(int j=i;j<=m;j++){
			dp[j] = max(dp[j],dp[j-i] + t[j]);
			mx = max(mx,dp[j]);
		}
	}
	cout << mx << '\n';
   return 0;
}


