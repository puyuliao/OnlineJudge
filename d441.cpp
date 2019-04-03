#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;
#define MAXN 10000

vector<int> prime;
bool bs[MAXN]={true,true};
int mf[2000];
int nf[2000];

void build(){
	for(int i=2;i<MAXN;i++){
		if(!bs[i]) prime.push_back(i);
		for(int j=0;i*prime[j]<MAXN;j++){
			bs[i*prime[j]]=true;
			if(i%prime[j] == 0) break;
		}
	}
}

int main()
{
	//IOS;
	build();
	int t,m,n,cnt = 0,ans,tmp,tmpto;
	cin >> t;
	while(t--){
		cin >> m >> n;
		ans = 10000;
		cout << "Case " << (++cnt) << ":\n";
		for(int i = 0;prime[i]<=m;i++){
			mf[i] = 0;
			while(m%prime[i]==0){
				m/=prime[i];
				mf[i]++;
			}
			if(mf[i]){
				tmp = prime[i];
				tmpto = 0;
				while(tmp<=n){
					tmpto+=n/tmp;
					tmp*=prime[i];
				}
				ans = min(ans,tmpto/mf[i]);
			}
		}
		if(ans)cout << ans << '\n';
		else cout << "Impossible to divide\n";
	}

   return 0;
}


