#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

int main()
{
	IOS;
	int k,n;
	cin >> k >> n;
	int t = 1;
	int ans = 0;
	for(;n;n>>=1){
		if(n&1) ans += t;
		t = t*k;
	}
	cout << ans << '\n';
   return 0;
}


