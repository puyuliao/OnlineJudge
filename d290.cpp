#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;
#define MAXN 1000000000

bool test(int n){
	int ans = 0;
	for(int i=1;i*i<=n;i++){
		if(n%i==0) {
			ans+=i;
			if(i!=n/i && n/i!=n) ans += n/i;
		}
	}
	return ans == n;
}

int main()
{
	//IOS;
	for(int i=33550336;i<MAXN;i++){
		if(test(i)) cout << i << ' ';
		break;
	}

   return 0;
}


