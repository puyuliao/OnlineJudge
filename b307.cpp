#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define mod 10007

int main()
{
	IOS;
	int T,a,b,q;
	cin >>T;
	while(T--){
		cin >> a >> b >> q;
		a = q%mod*a%mod;
		b = q%mod*b%mod;
		cout << (a==b?"SAFE\n":"BOOM\n");
	}

   return 0;
}


