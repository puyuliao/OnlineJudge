#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;

int main()
{
	IOS;
	int T;
	cin >> T;
	double x[3];
	double y[3];
	while(T--){
		for(int i=0;i<3;i++) cin >> x[i] >> y[i];
		cout << (int)floor(abs(x[0]*y[1] - x[1]*y[0] + x[1]*y[2] - x[2]*y[1] + x[2]*y[0] - x[0]*y[2])/14+0.5) << '\n';
	}

   return 0;
}


