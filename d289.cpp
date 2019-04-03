#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 8000

int dp[N+1];
int c[8] = {1,13,33,43,139,169,1309,2597};

int main()
{
	IOS;
	int n;
	while(cin >> n){
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		for(int i=0;i<8;i++){
			for(int j=c[i];j<=n;j++){
				dp[j] += dp[j-c[i]];
			}
		}
		cout << dp[n] << '\n';
	}

   return 0;
}


