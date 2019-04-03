#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	int n,t;
	int ans = 0,last = 0;
	while(cin >> n && n){
		ans = last = 0;
		while(n--){
			cin >> t;
			last = max(0,last+t);
			ans = max(last,ans);
		}
		if(ans) cout << "The maximum winning streak is " << ans;
		else cout << "Losing streak";
		cout << ".\n";
	}

   return 0;
}


