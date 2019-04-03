#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000
#define mod 360

char in[N];

int main()
{
	IOS;
	int T,ans;
	cin >> T;
	while(T--){
		cin >> in;
		ans = 0;
		for(int i=0;in[i];i++) ans = (ans*10 + in[i] - '0') % mod;
		cout << ans << '\n';
	}

   return 0;
}


