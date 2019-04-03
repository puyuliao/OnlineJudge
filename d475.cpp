#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;

inline int64_t tpow(int64_t a,int64_t b){
	if(a == 1) return 1;
	if(a == 0) return 0;
	if(a == -1) return 1 - 2*(b&1);
	int64_t ans = 1;
	for(;b;b>>=1){
		if(b&1) ans*=a;
		a*=a;
	}
	return ans;
}

int main()
{
	//IOS;
	int64_t a,n,cnt = 0;
	while(scanf("%lld%lld",&a,&n) == 2 && (a||n)){
		printf("%lld\n",tpow(a,n));
	}
	cout << "All Over. Exceeded " << 65536 << " lines!";

   return 0;
}


