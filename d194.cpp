#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000
#define C 1000000001

int bs[C/8];
int in[N];

int main()
{
	IOS;
	int T,n,ans,t,l,r;
	cin >> T;
	while(T--){
		cin >> n;
		l = r = ans = t = 0;
		bs.reset();
		for(;r<n;r++){
			cin >> in[r];
			if(!test(r)) bs[r] = 1,t++;
			else{
				ans = max(ans,t);
				while(bs[r]) bs[l++] = 0;
				bs[r] = 1,t++;
			}
		}
		ans = max(ans,t);
		cout << ans << '\n';
	}
   return 0;
}


