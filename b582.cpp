#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int x[N];
int y[N];

int main()
{
	IOS;
	int T,n,ans;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=0;i<n;i++) cin >> x[i] >> y[i];
		sort(x,x+n); sort(y,y+n);
		int mx = x[n>>1]; int my = y[n>>1];
		ans = 0;
		for(int i=0;i<n;i++){
			ans += abs(x[i] - mx) + abs(y[i] - my);
		}
		cout << ans << '\n';
	}
	

   return 0;
}


