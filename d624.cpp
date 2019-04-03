#include <stdio.h>
#include <stdint.h>
#include <memory.h>

int n,m;
int64_t dp[50][91];

int64_t f(int i,int j){
	if(dp[i][j]) return dp[i][j];
	if(i<n) return dp[i][j] = f(i+1,j-1) + f(0,j-1);
	return dp[i][j] = f(0,j-1);
}

int main()
{
	while(scanf("%d%d",&n,&m)==2){
		memset(dp,0,sizeof(dp));
		for(int i=0;i<50;i++) dp[i][0]=1;
		printf("%lld\n",f(0,m));
	}
	
   return 0;
}
