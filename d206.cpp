#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 100
#define INF 0x3f3f3f3f

int64_t in[N+1][N+1];
int64_t dp[N+1][N+1];

int main()
{
	//IOS;
	int n;
	while(cin >> n){
		int64_t mx = -INF;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin >> in[i][j];
				dp[i][j] = in[i][j] + max(-dp[i-1][j-1] + dp[i-1][j] + dp[i][j-1],0LL);
				mx = max(mx,dp[i][j]);
			}
		}
		cout << mx << '\n';
	}

   return 0;
}


