#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

double x[11];
double y[11];

int main()
{
	IOS;
	int n;
	double ans;
	while(cin >> n){
		for(int i=0;i<n;i++){
			cin >> x[i] >> y[i];
		}
		x[n] = x[0],y[n] = y[0];
		ans = 0;
		for(int i=0;i<n;i++){
			ans += x[i]*y[i+1] - y[i]*x[i+1];
		}
		ans = abs(ans)/2.0;
		cout << fixed << setprecision(2) <<ans << '\n';
	}
	
   return 0;
}


