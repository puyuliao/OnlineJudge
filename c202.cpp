#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;

int main()
{
	IOS;
	int n;int64_t ans,t;
	cin >> n >> ans;
	while(--n){
		cin >> t;
		ans = __gcd(ans,t);
	}
	cout << ans << '\n';
   return 0;
}


