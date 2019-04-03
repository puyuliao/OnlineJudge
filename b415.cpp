#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000
#define f(x,n) ((int64_t)x*x%n) 

int main()
{
	IOS;
	int x,n,m;
	while(cin >> x >> n >> m){
		while(m--){
			cout << x << ' ';
			x = f(x,n);
		}
		cout << '\n';
	} 

   return 0;
}


