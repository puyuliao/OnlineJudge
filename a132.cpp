#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	int n;
	while(cin >> n && n){
		
		cout << "The parity of ";
		int ans = 0;
		for(unsigned int i=1<<31;i;i>>=1){
			if(n & i) cout << 1,ans++;
			else if(i <= n) cout << 0;
		}
		
		cout << " is " << ans << " (mod 2).\n";
	}

   return 0;
}


