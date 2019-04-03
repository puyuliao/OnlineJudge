#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

uint64_t dp[51] = {1,3,7};
uint64_t f(int n){
	if(dp[n]) return dp[n];
	return dp[n] = 2*f(n-1) + f(n-2);
}

int main()
{
	IOS;
	int n;
	while(cin >> n) cout << f(n) << '\n';

   return 0;
}


