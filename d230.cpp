#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;
#define MOD 10000000
#define MAXN 16000
#define MXP 1800

vector<int> prime;
bitset<MAXN+1> bs;
int ans[5001];
int mot[MXP];
int chd[MXP];

void build(){
	bs[0] = bs[1] = true;
	for(int i=2;i<=MAXN;i++){
		if(!bs.test(i)) prime.push_back(i);
		for(int j=0;i*prime[j]<=MAXN;j++){
			bs[i*prime[j]] = true;
			if(i%prime[j] == 0) break;
		}
	}
}

int powmo(int a,int b,int mod){
	int ans = 1;
	for(;b;b>>=1){
		if(b&1) ans = (int64_t)ans*a%mod;
		a = (int64_t)a*a%mod;
	}
	return ans;
} 

int main()
{
	build();
	int n,m,k;
	while(scanf("%d",&n)==1){
		if(ans[n]){
			printf("%d\n",ans[n]);
			continue;
		}
		memset(mot,0,sizeof(mot));
		memset(chd,0,sizeof(chd));
		m = 3*n;
		for(int i=0,j;m/prime[i];i++){
			j = prime[i];
			while(m/j){
				mot[i] += m/j;
				j*=prime[i];
			}
		}
		for(int i=0,j;n/prime[i];i++){
			j = prime[i];
			while(n/j){
				chd[i] += n/j;
				j*=prime[i];
			}
		}
		k = 2*n+1;
		for(int i=0,j;k/prime[i];i++){
			j = prime[i];
			while(k/j){
				chd[i] += k/j;
				j*=prime[i];
			}
		}
		ans[n] = 1;
		for(int i=0;i<MXP;i++){
			mot[i]-=chd[i];	
			if(mot[i] < 0) cout << mot[i];
			else ans[n] = (int64_t)(ans[n])*powmo(prime[i],mot[i],MOD) % MOD;
		}
		printf("%d\n",ans[n]);
	}
   return 0;
}


