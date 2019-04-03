#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int extended_gcd(int a, int b,int &x,int &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	int d = extended_gcd(b, a % b, x, y);
	int t = x; x = y; y = t - a/b * y;
	return d;
}

int main()
{
	IOS;
	int a,n,x,y;
	while(cin >> a >> n){
		if(extended_gcd(a,n,x,y) != 1) cout << "No Inverse\n";
		else cout << (x + n) % n << '\n';
	}
   return 0;
}


