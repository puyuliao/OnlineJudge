#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000
#define sq(x) ((x)*(x))

int x_1,y_1,x2,y2,n;
int x[N];
int y[N];

bool chk(int r2){
	for(int i=0;i<n;i++)
		if(sq(x[i] - x_1) > r2 - sq(y[i] - y_1) && sq(x[i] - x2) > r2 - sq(y[i] - y2)) return false;
	return true;
}

int main()
{
	IOS;
	cin >> x_1 >> y_1 >> x2 >> y2 >> n;
	for(int i=0;i<n;i++) cin >> x[i] >> y[i];
	int l = 0, r = 1000000001;
	while(l!=r){
		int m = l + ((r-l)>>1);
		if(!chk(m)) l = m+1; 
		else r=m;
	}
	cout << l << '\n';
   return 0;
}


