#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000
#define int int64_t

int s(int n){
	int r = 0;
	while(n) r += n%10, n/=10;
	return r;
}

int f(int n){
	if(n == 1) return 1;
	int mx = 0;
	for(int a=1;a<n;a++){
		mx = max(mx,s(a)+s(n-a));
	}
	return mx;
}

int32_t main()
{
	IOS;
	int T,n;
	cin >> T;
	while(T--){
		cin >> n;
		if(n < 20){
			cout << f(n) << '\n';
			continue;
		}
		int w = 9;
		int mx = 0;
		while(w < n){
			mx = max(mx,s(w)+s(n-w));
			w = w*10+9;
		}
		//if(mx != f(n)) cout << "GG!";
		cout << mx << '\n';
	}

   return 0;
}


