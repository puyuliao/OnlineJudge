#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define M 10000
#define N 50

int dp[N+1][M+1];
 
int main()
{
	IOS;
	int m,n,p,v,w;
	while(cin >> m >> n >> p){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int k=1;k<=p;k++) {
				cin >> w >> v;
				for(int j=m;j>=0;j--){
					if(j + w <= m) dp[i][j] = max({dp[i][j],dp[i-1][j],dp[i-1][j+w] + v});
					else dp[i][j] = max(dp[i][j],dp[i-1][j]);
				} 
			}
		}
		cout << dp[n][0] << '\n';
	}
   return 0;
}
