#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 500000

int64_t dp[5*(N+1)]={0,1,2,3,4,5};
int64_t f(int n){
	if(dp[n] || !n) return dp[n];
	return dp[n] = f(n-n/5-(n%5>0)) + 1;
}

int main()
{
	IOS;
	int n;
	while(cin >> n && ~n){
		cout << f(5*(n+1)) << '\n';
	}

   return 0;
}


