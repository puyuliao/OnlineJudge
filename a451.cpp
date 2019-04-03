#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1572864
#define mod 1048576

int f[N];

int main()
{
	IOS;
	f[0] = 0; f[1] = 1;
	for(int i=2;i<N;i++) f[i] = (f[i-1]+f[i-2]) % mod;
	int n,m;
	while(cin >> n >> m){
		cout << f[n%N]%(1<<m) << '\n';
	}
   return 0;
}
