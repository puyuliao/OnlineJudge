#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;
#define MAXN 32001

vector<int> prime;
bool bs[MAXN]={true,true};

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
	build();
	IOS;
	int n,ans;
	while(cin >> n){
		cout << n << "!=";
		for(int i=0,j;prime[i]<=n;i++){
			ans = 0;
			j = prime[i];
			while(j<=n){
				ans+=n/j;
				j*=prime[i];
			}
			cout << ans << ' ';
		}
		cout << '\n';
	}

   return 0;
}


