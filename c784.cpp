#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	int T;
	cin >> T;
	int l,n,t,x;
	char cmd;
	while(T--){
		int ans = 0;
		cin >> l >> n >> t;
		for(int i=0;i<n;i++){
			cin >> x >> cmd;
			if(cmd == 'R' && x + t <= l) ans++;
			if(cmd == 'L' && x - t >= 0) ans++;
		}
		cout << ans << '\n';
	}

   return 0;
}


