#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

//double area(double a,double b,double c){
//	double s = (a+b+c)*0.5;
//	return sqrt(s*(s-a)*(s-b)*(s-c));
//}

int main()
{
	IOS;
	int n,a,b,c;
	while(cin >> n && n){
		while(n--){
			cin >> a >> b >> c;
			double ma2,mb2,mc2;
			ma2 = (a*a + b*b - c*c*0.5)*0.5;
			mc2 = (a*a + c*c - b*b*0.5)*0.5;
			mb2 = (c*c + b*b - a*a*0.5)*0.5;
			cout << fixed << setprecision(1) << (ma2+mb2+mc2) * 4 / 9.0 << '\n';
		} 
	}

   return 0;
}


