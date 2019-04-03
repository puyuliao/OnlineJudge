#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;
#pragma GCC target("avx")

const double pi = 3.1415926535897932384626;

int main()
{
	IOS;
	double x,y;
	while(cin >> y){
		x = acos(asin(y)) * 180.0 / pi;
		if(isnan(x)) cout << "FAIL!\n";
		else cout << fixed << setprecision(2) << x << '\n';
	}

   return 0;
}
