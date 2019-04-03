#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define M 1000

int dp[M+1];
int main()
{
	IOS;
	int n,m,w,c;
	while(cin >> m >> n){
		memset(dp,0,m+1<<2);
		while(n--){
			cin >> w >> c;
			for(int i=m;i>=w;i--){
				dp[i] = max(dp[i],dp[i-w] + c);
			}
		}
		cout << dp[m] << '\n';
	}

   return 0;
}


