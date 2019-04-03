#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;

const double pi = 3.14159265358979323;

int main()
{
	double x,y;
	while(scanf("%lf",&y)==1){
		x = acos(asin(y)) * 180.0 / pi;
		if(isnan(x)) printf("FAIL!\n");
		else printf("%.2lf\n",x);
	}

   return 0;
}


