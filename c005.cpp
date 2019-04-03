#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	int64_t T,n,a,b,c;
	cin >> T;
	while(T--){
		cin >> n;
		int64_t ans = 0;
		while(n--){
			cin >> a >> b >> c;
			ans+=a*c;
		}
		cout << ans << '\n';
	}

   return 0;
}


