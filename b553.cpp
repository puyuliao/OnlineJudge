#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 30000

int coz(int n){
	int ans = 0;
	while(n!=1){
		if(n&1) n = 3*n+1;
		else n>>=1;
		++ans;
	}
	return ans;
}

int main()
{
	IOS;
	int n;
	while(cin >> n){
		cout << coz(n) <<'\n';
	}

   return 0;
}


