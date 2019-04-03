#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 100000

int in[N];

int main()
{
	IOS;
	int n;
	while(cin >> n){
		for(int i=0;i<n;i++) cin >> in[i];
		sort(in,in+n);
		int64_t ans = 0;
		for(int i=0;i<n;i+=2) ans += (in[i+1] - in[i]);
		cout << ans << '\n';
	}

   return 0;
}


