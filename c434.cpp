#include<stdio.h>
#define MOD 1000000007ul
unsigned int f[1000001] = {0,0,0,1,3};

int main()
{
	//IOS;
	unsigned int p = 2;
	for(int i=5;i<1000001;i++){
		f[i] = p + (f[i-1]<<1), p = p+p;
		if(f[i] < f[i-4]) f[i] ;
 		else if(f[i] > MOD) f[i] %= MOD;
		if(p > MOD) p -= MOD;
	} 
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%u\n",f[n]);
	}

   return 0;
}


