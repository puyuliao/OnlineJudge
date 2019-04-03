#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 30000

int F[N];
bitset<N> bs;
vector<int> prime;

void build(){
	bs[0] = bs[1] = 1;
	for(int i=2;i<N;i++){
		if(!bs[i]) prime.push_back(i);
		for(int j=0;i * prime[j]<N;j++){
			bs[i*prime[j]] = 1;
			if(i % prime[j] == 0) break;	
		}
	}
}


void dp(int n){
	memset(F,0xff,sizeof(F));
	F[0] = 0;
	for(int i : prime){
		for(int j = n;j >= i;j--){
			if(~F[j-i]) F[j] = max(F[j],F[j-i] + 1);
		}
		if(i > n) break;
	}
	F[0] = F[1] = -1;
}

int main()
{
	IOS;
	int n;
	build();
	dp(20000);
	while(cin >> n){
		cout << F[n] << '\n';
	}

   return 0;
}


