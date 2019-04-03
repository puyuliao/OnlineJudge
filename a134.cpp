#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 60

int f[N];

int main()
{
	IOS;
	f[0] = 1; f[1] = 1;
	int sz = 2;
	for(;f[sz-1] < 100000000;sz++) f[sz] = f[sz-1] + f[sz-2];
	int T,n;
	cin >> T;
	while(T--){
		cin >> n;
		cout << n << " = ";
		int t = n;
		for(int i=sz-1;i>0;i--){
			if(t >= f[i]) cout << 1,t-=f[i];
			else if(f[i] <= n) cout << 0;
			
		}
		cout << " (fib)\n";
	}


   return 0;
}


