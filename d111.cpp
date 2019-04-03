#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	int n,cnt = 0;
	while(cin >> n && n){
		int ans = 1;
		for(int i=2;i<=n/i;i++){
			if(n%i == 0){
				int r = 0;
				while(n%i==0) r++,n/=i;
				ans *= (r+1);
			}
		}
		if(n != 1) ans+=ans;
		cout << (ans&1?"yes\n":"no\n");
	}

   return 0;
}


