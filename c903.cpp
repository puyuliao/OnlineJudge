#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000
#define MOD 1000

int main()
{
	IOS;
	int n;
	while(cin >> n){
		int ra = 1, rb = 0;
		int a = 3, b = 1;
		for(;n;n>>=1){
			if(n&1){
				int t = a*rb + b*ra - b*rb;
				ra = (ra*a + 3*rb*b) % MOD;
				rb = t%MOD;
			}
			int t = a*b + b*a - b*b;
			a = (a*a + 3*b*b) % MOD;
			b = t%MOD;
		}
		cout << setw(3) << setfill('0') << ra << '\n';
	}
   return 0;
}


