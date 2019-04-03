#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;
#define MAXN 1201

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
	int n,j;
	while(scanf("%d",&n)==1){
		j = 1;
		for(int i=0;prime[i]<=n;i++,j++){
			printf("%10d",prime[i]);
			if(j%5==0) printf("\n");
		}
		if((j-1)%5) printf("\n");
	}

   return 0;
}


