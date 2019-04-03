#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;

void agcd(int64_t* a,int n){
	if(n==0) return;
	int64_t g = a[0];
	for(int i=1;i<n;i++){
		if(a[i]) g=__gcd(g,a[i]);
	}
	for(int i=0;i<n;i++){
		a[i]/=g;
	}
}

int main()
{
	IOS;
	int64_t ans[4],x1,y1,x2,y2;
	while(cin >> x1 >> y1 >> x2 >> y2){
		ans[0] = (x2-x1)*(x2-x1);
		ans[1] = (y2-y1);
		ans[2] = y1*ans[0];
		ans[3] = (ans[1]*x1+y1)*ans[0];
		agcd(ans,4);
		cout << ans[0] << "y = " << ans[1] << "x^2 + " << ans[2] << "x + " << ans[3] << '\n'; 
	}

   return 0;
}


