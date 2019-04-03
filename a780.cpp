#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define eps 1e-9

int main()
{
	IOS;
	double f0, fe, fa;
	while(cin >> f0 >> fe >> fa){
		if(f0+fe+fa < eps) break;
		cout << fixed << setprecision(2) << f0/fe << ' ' << fa/f0*fe << '\n'; 
	}

   return 0;
}


