#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000

const double gold = 0.5 + 0.5*sqrt(5);

int main()
{
	IOS;
	int64_t a,b,T;
	cin >> T;
	while(T--){
		cin >> a >> b;
		if(a>b) swap(a,b);
		if(a==0 || (b-a)*gold == a) cout << ">\\\\<\n";
		else cout << ">//<\n";
	}
   return 0;
}


