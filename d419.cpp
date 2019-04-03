#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1200000

bitset<N> bs;
vector<int> prime;
void build(){
	bs[0] = bs[1] = true;
	for(int i=2;i<N;i++){
		if(!bs[i]) prime.push_back(i);
		for(int j=0;i*prime[j]<N;j++){
			bs[i*prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
}

int main()
{
	IOS;
	build();
	int64_t n,ans;
	while(cin >> n){
		ans = 0;
		for(int i=0;prime[i]<=n;i++){
			int64_t t = prime[i];
			while(n >= t) ans += n / t,t*=prime[i];
		}
		cout << ans << '\n';
	}
   return 0;
}


