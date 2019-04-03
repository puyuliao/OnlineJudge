#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 105

int a[N];
int b[N];
int dp[N][N];

int main()
{
	IOS;
	int n,m,cnt = 0;
	while(cin >> n >> m &&  (n||m)){
		cout << "Twin Towers #" << ++cnt << "\nNumber of Tiles : ";
		for(int i=1;i<=n;i++) cin >> a[i];
		for(int j=1;j<=m;j++) cin >> b[j];
		for(int i=1;i<=n;i++) 
			for(int j=1;j<=m;j++)
				if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
				else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		cout << dp[n][m] << '\n';
	}

   return 0;
}


