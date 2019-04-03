#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int dp[7500];

int main()
{
	IOS;
	dp[0] = 1;
	for(int i : {1,5,10,25,50})
		for(int j=i;j<7500;j++)
			dp[j] += dp[j-i];
	int n;
	while(cin >> n) cout << dp[n] << '\n';

   return 0;
}


