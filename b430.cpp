#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	long double a,b,n;
	while(cin >> a >> b >> n){
		cout << fixed << setprecision(0) << n*(a/n*b - floor(a/n*b)) << '\n';
	}

   return 0;
}
