#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	int n,t,ans;
	while(cin >> n){
		cin >> ans;
		for(int i=1;i<n;i++) cin >> t,ans = __gcd(ans,t);
		cout << ans << '\n';
	}

   return 0;
}


