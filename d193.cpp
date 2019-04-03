#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	int64_t t,n,ans,m;
	cin >>t;
	while(t--){
		cin >> n;
		ans = 0;
		m = (int)floor(sqrt(n));
		for(int i=1;i<=m;i++) ans += (int)floor(n/i);
		cout << ans*2-m*m << '\n';
	}

   return 0;
}


