#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
const double pi = 2*acos(0);

int main()
{
	IOS;
	int a,b;
	while(cin >> a >> b){
		double L = sqrt(0.25*b*b - 0.25*a*a);
		double R = 0.5*b;
		cout << fixed << setprecision(3) << L*R*pi << '\n';
	}

   return 0;
}


